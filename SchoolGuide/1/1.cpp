#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define MaxPlace 100
#define MaxInt 999
typedef struct arc{//������
	int RoadLen;//·��
	int ivex,jvex;//�ߵ����˵Ķ���λ�ã�
	string NextName;//��һ�����˵Ķ��������
	arc *next;
}SArc;//������
typedef struct Scenic{
	string SName;//��������
	int No;//�������
	string Info;//������Ϣ
	SArc *first;//ָ���һ���߽��
	//string SVex[MaxPlace];//�������Ʊ�
//	int RoadNums;//·������
//	int RoadLen;//·��
//	int data[MaxPlace][MaxPlace];//����
}SVex[MaxPlace];//��������

typedef struct { //�ڽ�����
	SVex Sv;//��ͷ
	int RoadNums;//·������
	int VexNums;//������
//	int data[MaxPlace][MaxPlace];
}SGraph;
//******************************************
void InitMap(SGraph &SG){//��ʼ��
	SG.RoadNums=SG.VexNums=0;
	for(int i=0;i<MaxPlace;i++){
		for(int j=0;j<MaxPlace;j++){
		SG.Sv[i].Info=SG.Sv[i].SName=" ";
		SG.Sv[i].No=0;
		SG.Sv[i].first=NULL;
//		SG.data[i][j]=MaxInt;
}
	
	}
}//��ʼ������
//******************************************
void CreateMap(SGraph &SG){
	int Locate(SGraph SG,string v);
	string ls,rs;
	int len;
	int a,b;
	SArc *p;
	cout<<"�����뾰����Ŀ��";
	cin>>SG.VexNums;
	cout<<"�������ܹ��м���·��";
	cin>>SG.RoadNums;
// ��ʼ������	
	for(int i=0;i<SG.VexNums;i++){
		cout<<"�������"<<i+1<<"�����������:"<<endl;
		cin>>SG.Sv[i].SName;
		cout<<"�������"<<i+1<<"������Ĵ���:"<<endl;
		cin>>SG.Sv[i].No;
		cout<<"�������"<<i+1<<"���������Ϣ:"<<endl;
		cin>>SG.Sv[i].Info;		
	}
	for(i=0;i<SG.RoadNums;i++){
		cout<<"���������·����Ϣ"<<endl;
		cout<<"�������"<<i+1<<"��·�����Ҿ���"<<endl;
			cin>>ls>>rs;
		cout<<"����������·�ĳ��ȣ�";
		cin>>len;
		a=Locate(SG,ls);
		b=Locate(SG,rs);
		p=new SArc;
		p->ivex=a;
		p->jvex=b;
		p->NextName=SG.Sv[b].SName;
		p->RoadLen=len;
		p->next=SG.Sv[a].first;
		SG.Sv[a].first=p;
	//	SG.data[a][b]=SG.data[b][a]=p->RoadLen;
		/*���´���������������ͼ�����ǽ�������ͼ��ɾȥ*/   
		p=new SArc;
		p->NextName=SG.Sv[a].SName;
		p->ivex=b;
		p->jvex=a;
		p->RoadLen=len;
		p->next=SG.Sv[b].first;
		SG.Sv[b].first=p;
	}
}
//Locate
int Locate(SGraph SG,string v){
	for(int i=0;i<SG.VexNums;i++)
		if(v==SG.Sv[i].SName) break;
		
		if(i>=SG.VexNums){
			cout<<"DATA NOT FOUND!"<<endl;
			return -1;
		}
		return i;
}
//���
void Show(SGraph &SG){
		for(int i=0;i<SG.VexNums;i++){
		SArc *t=SG.Sv[i].first;
		cout<<SG.Sv[i].SName<<"->";
		while(t){
			cout<<t->NextName<<"->";
			t=t->next;
		}
		cout<<"NULL";
		cout<<endl;
	}/*
		cout<<"********************************"<<endl;
		for(i=0;i<SG.VexNums;i++){
			for(int j=0;j<SG.VexNums;j++)
//				cout<<setw(4)<<setiosflags(ios::right)<<SG.data[i][j];
			cout<<endl;
		}
	cout<<"********************************"<<endl;
	*/
}
//��ѯ
void Search(SGraph SG){
	string s;
	cout<<"��������Ҫ��ѯ�ľ��������:";
	cin>>s;
	for(int i=0;i<SG.VexNums;i++)
		if(SG.Sv[i].SName==s){
			cout<<"���ѯ�ľ������Ϣ�ǣ�";
			cout<<"�������ƣ�"<<s<<"/������룺"<<SG.Sv[i].No<<"/������Ϣ:"<<SG.Sv[i].Info<<endl;
			return;
		}
		cout<<"������ľ���û�ҵ���"<<endl;	
}
//���·����
void FindWay(SGraph SG){
	string s1;//���
	int v;
	string s2;//�յ㣻
	cout<<"��������㣺"<<endl;
	cin>>s1;
	cout<<"�������յ㣺"<<endl ;
	cin>>s2;
	int begin=Locate(SG,s1);
	int final=Locate(SG,s2);
	/*������õ����ڽӾ�����Ϊ�洢�ṹ����������㷨
	bool S[MaxPlace];//����S
	int D[MaxPlace];//����D
	int Path[MaxPlace];//·��
//	SArc *p=SG.Sv[begin].first;
	for(int i=0;i<SG.VexNums;i++){
		S[i]=false;//��ʼʱ��Ϊ�ռ�
	    D[i]=SG.data[begin][i];//
		if(D[i]<MaxInt) Path[i]=begin;
         else Path[i]=-1;
	}
	S[begin]=true;
	D[begin]=0;//Դ�㵽Դ��ľ���Ϊ0
//	 ��ʼ����������ʼ��ѭ����ÿ�����vo��ĳ������v�����·������v�ӵ�S
//	��
	
	for(i=1;i<SG.VexNums;i++){	
		int min=MaxInt;
	for(int w=0;w<SG.VexNums;w++)
		if(!S[w]&&D[w]<min){v=w;min=D[w];}
		S[v]=true;
		for(w=0;w<SG.VexNums;w++)
			if(!S[w]&&(D[v]+SG.data[v][w]<D[w])){
				D[w]=D[v]+SG.data[v][w];
				Path[w]=v;
			}
			
	}
	for(int k=0;k<SG.VexNums;k++)
		cout<<Path[k]<<"->";
	cout<<"��̾���:";
	cout<<D[final]<<endl;
}�ڽӾ������*/
	//�ڽӱ��㷨
	int jg[MaxPlace];  //���·�����߷� jg[i]�����i��ǰ�������±�λ�ã�
	SArc *p=SG.Sv[begin].first;
	bool S[MaxPlace];//����S����ʼʱ��Ϊ�ռ�
	int D[MaxPlace];//�����㵽��������ľ��룬
	for(int i=0;i<SG.VexNums;i++){
		S[i]=false;//��ʼ��Ϊfalse��ʾ�ռ�
		D[i]=MaxInt;//��ʼʱ��ʼ��Ϊ�����ɴ�
		jg[i]=-1;//-1��ʾû��ǰ�����
		}
		while(p){
		//	cout<<p->NextName<<" "<<p->ivex<<" "<<p->RoadLen<<endl;
			if(p->RoadLen<MaxInt){
			D[Locate(SG,p->NextName)]=p->RoadLen;//���ڿ�ʼ���ֱ�������Ľ���·�����µ�D(·����)�У����û��ֱ�������򲻱�(Ϊ�����);
			jg[Locate(SG,p->NextName)]=Locate(SG,SG.Sv[begin].SName);//���뿪ʼ��ֱ�������Ľ���Ӧ���±�λ����jg(ǰ����)�е�ֵ����Ϊ��ʼ���
																	//��ǰ��Ϊ��㣻
			}
		   p=p->next; //Ѱ����һ�������ֱ�����ڵľ���
		}
	//��ʼ������
	S[begin]=true;//�������뼯��S��
	D[begin]=0;//��㵽���ľ���Ϊ0
	for(i=0;i<SG.VexNums;i++){ //n����� ��ѭ����һ�ξ͵�һ�����·���ĵ�
		int min=MaxInt;
		for(int w=0;w<SG.VexNums;w++)
			if(!S[w]&&D[w]<min){v=w;min=D[w];}   //�ҳ�D[]��·����̵ĵ㣬��Ϊ��һ��㣻
			S[v]=true;//����̵ĵ���뼯��S
		
			p=SG.Sv[v].first;//����һ�������µ������
			while(p!=NULL){
				if(!S[Locate(SG,p->NextName)]&&(p->RoadLen)+D[v]<=D[Locate(SG,p->NextName)])//����������ֱ�������Ҳ���S�����У���ͨ��v�����·��С��֮ǰֱ��
																							//����ľ���С�����£�
				{	D[Locate(SG,p->NextName)]=(p->RoadLen)+D[v];//���¾����
						jg[Locate(SG,p->NextName)]=Locate(SG,SG.Sv[v].SName);//�������ǰ��
					p=p->next;//�����ж���һ��ֱ�����ڵĽ��
				}
				else //���򣬸ý�㲻������µ�����������
					p=p->next;
			}
	}//�����for
   cout<<"��̾���:";
	cout<<D[final]<<endl; 


//��Ϊ�����·���߷�Ҫ���յ㿪ʼ��jg[](ǰ��������ǰ��),�ô��յ�������ң�������������ǵ���ģ����²������������⣻
//��ȻҲ������ջ�ķ���������ȳ�
	string right[MaxPlace];//�����洢���·�������ĵ�
	int count=0;//���ڼ�¼
//	for(int k=0;k<SG.VexNums;k++)
//		cout<<jg[k]<<" ";
	cout<<endl;
//	cout<<SG.Sv[final].SName<<" ";
	right[0]=SG.Sv[final].SName;//��һλ
	count++;
	int t=final;t=jg[t];
	while(t!=begin){
	//	cout<<SG.Sv[t].SName<<" ";
		right[count]=SG.Sv[t].SName;
		count++;

		t=jg[t];	
	}
//	cout<<SG.Sv[begin].SName<<endl;
	right[count]=SG.Sv[begin].SName;
	count++;
	//�ѵ���ľ������������У��ٴӺ���ǰ������ɣ�
	for(int y=count-1;y>=0;y--)
		cout<<right[y]<<" ";
	cout<<endl;	
}

//null->1->1->3->3->4->NULL


int main(){
	SGraph SG;
	InitMap(SG);
	CreateMap(SG);
	Show(SG);
	Search(SG);
	for(int i=0;i<10;i++)
FindWay(SG);
	return 1;
}
		
		

		

  





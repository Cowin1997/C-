#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define MaxPlace 100
#define MaxInt 999
typedef struct arc{//边类型
	int RoadLen;//路长
	int ivex,jvex;//边的两端的顶点位置；
	string NextName;//下一个两端的顶点的名字
	arc *next;
}SArc;//边类型
typedef struct Scenic{
	string SName;//景点名字
	int No;//景点代码
	string Info;//景点信息
	SArc *first;//指向第一个边结点
	//string SVex[MaxPlace];//景点名称表
//	int RoadNums;//路的条数
//	int RoadLen;//路长
//	int data[MaxPlace][MaxPlace];//矩阵
}SVex[MaxPlace];//景点类型

typedef struct { //邻接链表
	SVex Sv;//表头
	int RoadNums;//路的条数
	int VexNums;//景点数
//	int data[MaxPlace][MaxPlace];
}SGraph;
//******************************************
void InitMap(SGraph &SG){//初始化
	SG.RoadNums=SG.VexNums=0;
	for(int i=0;i<MaxPlace;i++){
		for(int j=0;j<MaxPlace;j++){
		SG.Sv[i].Info=SG.Sv[i].SName=" ";
		SG.Sv[i].No=0;
		SG.Sv[i].first=NULL;
//		SG.data[i][j]=MaxInt;
}
	
	}
}//初始化结束
//******************************************
void CreateMap(SGraph &SG){
	int Locate(SGraph SG,string v);
	string ls,rs;
	int len;
	int a,b;
	SArc *p;
	cout<<"请输入景点数目：";
	cin>>SG.VexNums;
	cout<<"请输入总共有几条路：";
	cin>>SG.RoadNums;
// 初始化景点	
	for(int i=0;i<SG.VexNums;i++){
		cout<<"请输入第"<<i+1<<"个景点的名字:"<<endl;
		cin>>SG.Sv[i].SName;
		cout<<"请输入第"<<i+1<<"个景点的代码:"<<endl;
		cin>>SG.Sv[i].No;
		cout<<"请输入第"<<i+1<<"个景点的信息:"<<endl;
		cin>>SG.Sv[i].Info;		
	}
	for(i=0;i<SG.RoadNums;i++){
		cout<<"请输入各条路的信息"<<endl;
		cout<<"请输入第"<<i+1<<"条路的左右景点"<<endl;
			cin>>ls>>rs;
		cout<<"请输入这条路的长度：";
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
		/*以下代码用来建立无向图，若是建立有向图，删去*/   
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
//输出
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
//查询
void Search(SGraph SG){
	string s;
	cout<<"请输入你要查询的景点的名称:";
	cin>>s;
	for(int i=0;i<SG.VexNums;i++)
		if(SG.Sv[i].SName==s){
			cout<<"你查询的景点的信息是：";
			cout<<"景点名称："<<s<<"/景点代码："<<SG.Sv[i].No<<"/景点信息:"<<SG.Sv[i].Info<<endl;
			return;
		}
		cout<<"您输入的景点没找到！"<<endl;	
}
//最短路径；
void FindWay(SGraph SG){
	string s1;//起点
	int v;
	string s2;//终点；
	cout<<"请输入起点："<<endl;
	cin>>s1;
	cout<<"请输入终点："<<endl ;
	cin>>s2;
	int begin=Locate(SG,s1);
	int final=Locate(SG,s2);
	/*如果采用的是邻接矩阵作为存储结构则采用如下算法
	bool S[MaxPlace];//集合S
	int D[MaxPlace];//集合D
	int Path[MaxPlace];//路径
//	SArc *p=SG.Sv[begin].first;
	for(int i=0;i<SG.VexNums;i++){
		S[i]=false;//开始时候为空集
	    D[i]=SG.data[begin][i];//
		if(D[i]<MaxInt) Path[i]=begin;
         else Path[i]=-1;
	}
	S[begin]=true;
	D[begin]=0;//源点到源点的距离为0
//	 初始化结束，开始主循环，每次求得vo到某个顶点v的最短路径，将v加到S
//	集
	
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
	cout<<"最短距离:";
	cout<<D[final]<<endl;
}邻接矩阵结束*/
	//邻接表算法
	int jg[MaxPlace];  //最短路径的走法 jg[i]存的是i的前驱结点的下表位置；
	SArc *p=SG.Sv[begin].first;
	bool S[MaxPlace];//集合S，开始时候为空集
	int D[MaxPlace];//出发点到各个顶点的距离，
	for(int i=0;i<SG.VexNums;i++){
		S[i]=false;//初始化为false表示空集
		D[i]=MaxInt;//开始时初始化为均不可达
		jg[i]=-1;//-1表示没有前驱结点
		}
		while(p){
		//	cout<<p->NextName<<" "<<p->ivex<<" "<<p->RoadLen<<endl;
			if(p->RoadLen<MaxInt){
			D[Locate(SG,p->NextName)]=p->RoadLen;//将于开始结点直接相连的结点的路长更新到D(路长表)中，如果没有直接相连则不变(为无穷大);
			jg[Locate(SG,p->NextName)]=Locate(SG,SG.Sv[begin].SName);//将与开始点直接相连的结点对应的下标位置在jg(前驱表)中的值更新为开始结点
																	//既前驱为起点；
			}
		   p=p->next; //寻找下一个与起点直接相邻的景点
		}
	//初始化结束
	S[begin]=true;//将起点放入集合S中
	D[begin]=0;//起点到起点的距离为0
	for(i=0;i<SG.VexNums;i++){ //n个结点 大循环找一次就到一个最短路径的点
		int min=MaxInt;
		for(int w=0;w<SG.VexNums;w++)
			if(!S[w]&&D[w]<min){v=w;min=D[w];}   //找出D[]中路长最短的点，既为下一结点；
			S[v]=true;//将最短的点加入集合S
		
			p=SG.Sv[v].first;//以这一顶点重新当做起点
			while(p!=NULL){
				if(!S[Locate(SG,p->NextName)]&&(p->RoadLen)+D[v]<=D[Locate(SG,p->NextName)])//如果与新起点直接相邻且不在S集合中，且通过v到达的路径小于之前直接
																							//到达的距离小，更新，
				{	D[Locate(SG,p->NextName)]=(p->RoadLen)+D[v];//更新距离表
						jg[Locate(SG,p->NextName)]=Locate(SG,SG.Sv[v].SName);//更新最短前驱
					p=p->next;//继续判断下一个直接相邻的结点
				}
				else //否则，该结点不满足更新的条件，跳过
					p=p->next;
			}
	}//最外层for
   cout<<"最短距离:";
	cout<<D[final]<<endl; 


//因为求最短路径走法要从终点开始在jg[](前驱表中找前驱),得从终点往起点找，这样输出来的是倒序的，以下操作解决这个问题；
//当然也可以用栈的方法，后进先出
	string right[MaxPlace];//用来存储最短路径经过的点
	int count=0;//用于记录
//	for(int k=0;k<SG.VexNums;k++)
//		cout<<jg[k]<<" ";
	cout<<endl;
//	cout<<SG.Sv[final].SName<<" ";
	right[0]=SG.Sv[final].SName;//第一位
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
	//把倒序的经过存入数组中，再从后往前输出即可；
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
		
		

		

  





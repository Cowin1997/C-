#include <iostream>
#include <string>
using namespace std;
class AMGraph{
private:
    int vnum;//������;
	int bnum;//����
	string **V;//������Ϣ��
	int **data;//��������   ��Сnew������
public:	
	void InitAMG(int v,int b);//��ʼ��
	int Locate(string v);
	void InputAMG();//ͼ������
	void ShowAMG();//�������
	void JudgeZf();//�Է����
	void JudgeDc();//�ԳƼ��
	void JudgeCd();//���ݼ��
};
//*********************************************************************************
void AMGraph::InitAMG(int v,int b){
		vnum=v;
		bnum=b;
		data=new int *[vnum];
		for(int i=0;i<vnum;i++)
			data[i]=new int [vnum];
		V=new string *[vnum];
		for(i=0;i<vnum;i++)
			V[i]=new string[1];//ÿ�����㵱ǰ����Ϊֻ��һ����Ϣ��
								//�� V[i][0]���涥����Ϣ
		for(i=0;i<vnum;i++)
			for(int j=0;j<vnum;j++)
				data[i][j]=0;
	}
//*********************************************************************************
int AMGraph::Locate(string v){
	for(int i=0;i<vnum;i++){
		if(v==V[i][0])  break;	
	}
	return i;
	if(i==vnum)    {
		cout<<"Error! Locate not found!"<<endl;
		return -1;
	}
		
}
//*********************************************************************************
void AMGraph::InputAMG(){
	string v1,v2;
	int a,b;
	cout<<"�����붥������";
	cin>>vnum;
	cout<<"���������:";
	cin>>bnum;
	cout<<"������������㣺";
	for(int i=0;i<vnum;i++)
	cin>>V[i][0];
	cout<<"����������ߵ������˵�(��Ԫ��ϵ)"<<endl;
		for(i=0;i<bnum;i++){
			cin>>v1>>v2;   
			a=Locate(v1);  //�ڶ�����Ϣ���ҵ������v1��λ��
			b=Locate(v2);	//�ҵ������v2��λ��	
			data[a][b]=1;   //���� A B C λ��Ϊ0 1 2 �����ϵ A B ���ҵ���0����1����ֵΪ1,��ʾ���ڹ�ϵ
		}
}
//********************************************************************************
void AMGraph::ShowAMG(){
	for(int i=0;i<vnum;i++){
		for(int j=0;j<vnum;j++)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}
}
//********************************************************************************
void AMGraph::JudgeZf(){//���߷���bool����    return b;
		bool a=false;
		for(int i=0;i<vnum;i++){
			if(data[i][i]==1)  a=true;
			else {a=false;break;}
		}
		if(a)
			cout<<endl<<"�Է�"<<endl;
		else
			cout<<"���Է�"<<endl;
	}
//********************************************************************************
void AMGraph::JudgeDc(){//���߷���bool����    return b;
	bool b=false;
	for(int i=0;i<vnum;i++){
			for(int j=0;j<vnum;j++){
				if (data[i][j]==data[j][i])
						b=true; 
				if(data[i][j]!=data[j][i])
				{b=false;break;}
			}			
		//	if(b)
		//		cout<<"�Գ�"<<endl;
			if(!b)
				cout<<"�ǶԳ�"<<endl;
			break;//����for(int i=0;i<vnum;i++)
	}
				if(b)
				cout<<"�Գ�"<<endl;
	}
//********************************************************************************
void AMGraph::JudgeCd(){    //���߷���bool����    return b;
	bool b=false;
	for(int i=0;i<vnum;i++){
		for(int j=0;j<vnum;j++){
			for(int k=0;k<vnum;k++){
				if(data[i][j]*data[j][k]==data[i][k])
					b=true;
				if(data[i][j]*data[j][k]!=data[i][k])
				{b=false;break;}
			}
		if(!b)
			cout<<"�Ǵ���"<<endl;
		break;
		}
		if(!b)
			break;
}
if(b)
	cout<<"����"<<endl;
}
//********************************************************************************

int main(){
	AMGraph G;
	G.InitAMG(6,14);
	G.InputAMG();
	G.ShowAMG();
	G.JudgeZf();
	G.JudgeDc();
	G.JudgeCd();
	return 0;
}
/*
�����붥������6
���������:14
������������㣺1 2 3 4 5 6
����������ߵ������˵�
1 1
2 2
3 3
4 4
5 5
6 6
1 2
1 4
1 5
2 5
3 2
3 6
3 5
4 5
1 1 0 1 1 0
0 1 0 0 1 0
0 1 1 0 1 1
0 0 0 1 1 0
0 0 0 0 1 0
0 0 0 0 0 1
*/

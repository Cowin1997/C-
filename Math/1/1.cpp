#include <iostream>
#include <string>
using namespace std;
#define Max 100
typedef struct {
	int data[Max][Max];
	//int **data;
	int vnum;//������;
	int bnum;//����
	//string *V;
	string V[Max];
}AMGraph;

//��ʼ��
void InitAMG(AMGraph &G){
//	int n;//n�Ƕ���
//	int m;//����
//	cin>>n>>m;
//	G.data=new int [3][3];
//	G.data=p;
//	string *t=new string[n];
//	G.V=t;

	for(int i=0;i<Max;i++){
		G.V[i]="";
		for(int j=0;j<Max;j++)
			G.data[i][j]=0;
			
	}
}

//Locate()
int Locate(AMGraph G,string v){
	for(int i=0;i<G.vnum;i++){
		if(v==G.V[i])   break;
		
	}
	return i;
if(i==G.vnum)    return -1;
		
}
		
//����
void InputAMG(AMGraph&G,int n,int m){
	string v1,v2;
	int a,b;
	cout<<"�����붥������";
	cin>>G.vnum;
	cout<<"���������:";
	cin>>G.bnum;
	cout<<"������������㣺";
	for(int i=0;i<G.vnum;i++)
		cin>>G.V[i];
	cout<<"����������ߵ������˵�"<<endl;
		for(i=0;i<G.bnum;i++){
			cin>>v1>>v2;
			a=Locate(G,v1);
			b=Locate(G,v2);
			G.data[a][b]=1;
		}
}
//���
void ShowAMG(AMGraph G){
	for(int i=0;i<G.vnum;i++){
		for(int j=0;j<G.vnum;j++)
			cout<<G.data[i][j]<<" ";
		cout<<endl;
	}
}
//�ж�

		

int main(){
	AMGraph M;
	InitAMG(M);
	InputAMG(M,5,5);
	ShowAMG(M);
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
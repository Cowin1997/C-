#include <iostream>
#include <iomanip>
#include <string>
#include "Queue.h"
using namespace std;
#define MaxInt 32767
#define MaxVNum 100
typedef struct {
//	char (*V)[MaxVNum];//顶点
	string V[MaxVNum];//顶点
	int  arcs[MaxVNum][MaxVNum];
	int vexnum;//总顶点数
	int arcnum;//总边树
}AMGraph;
bool VisitedDFS[MaxVNum];
bool VisitedBFS[MaxVNum];
//*****LocateVex()******
int LocateVex(AMGraph G,string v){
	int loc;
	for(loc=0;loc<G.vexnum;loc++)
		if(G.V[loc]==v)   return loc;
	return -1;
}
//创建有向图
void CreateAMG(AMGraph &G){
//	char *v1,*v2;//顶点
//	char v1,v2;//顶点
	string v1,v2;
	int w;//权重
	printf("请输入总顶点数:");
	cin>>G.vexnum;
	cout<<"请输入总边数：";
	cin>>G.arcnum;
	cout<<"请输入所有的顶点:";
	for(int i=0;i<G.vexnum;i++){
	//	G.V[i]=new char [5];
		cin>>G.V[i];
	}
	for(i=0;i<G.vexnum;i++)
		for(int j=0;j<G.vexnum;j++)
			G.arcs[i][j]=MaxInt;
		for(int k=0;k<G.arcnum;k++){
			while(!k){
				cout<<"请输入该边的两个顶点和权重"<<endl;
				cout<<"V1"<<" V2"<<" W"<<endl;
				break;
			}
			cin>>v1;
			cin>>v2;
			cin>>w;//>>v2>>w;
			//无向图 w=1；
			int locv1=LocateVex(G,v1);
			int locv2=LocateVex(G,v2);
			G.arcs[locv1][locv2]=w;//有向图
		//	G.arcs[locv1][locv2]=G.arcs[locv2][locv1]=1;//无向图
		}
}
//输出
void ShowAMG(AMGraph G){
	for(int i=0;i<G.vexnum;i++){
		for(int j=0;j<G.vexnum;j++){
			cout<<setw(6)<<setiosflags(ios::right)<<G.arcs[i][j];
		}
		cout<<endl;
	}
}



	int t;
	
	

//深度优先搜索遍历图
void DFSAMG(AMGraph G,int V){//V代表第几个顶点 

	cout<<G.V[V]<<" ";
	VisitedDFS[V]=true;
	for(t=0;t<G.vexnum;t++)
		if((G.arcs[V][t]!=32767)&&(!VisitedDFS[t]))
			DFSAMG(G,t);             //递归
//	cout<<"深度优先遍历:"<<endl;
}
//广度优先遍历
void BFSAMG(AMGraph G,int V,LinkQueue &Q){ //V代表顶点
//	int count,temp;
//	temp=V;
	int e;
	InitLinkQueue(Q);
	InQueue(Q,V);
	VisitedBFS[V]=true;
	cout<<G.V[V]<<" ";
	while(Q.Head!=Q.Rear){//队不空
		DeQueue(Q,e);
	//	count=1;
		for(t=0;t<G.vexnum;t++){
			if((G.arcs[e][t]!=32767)&&(!VisitedBFS[t]))
			{	InQueue(Q,t);
				cout<<G.V[t]<<" ";
				VisitedBFS[t]=true;
			}
		}

	}
}









void main(){
	//V=+-1;
	LinkQueue Q;
	AMGraph G;
	CreateAMG(G);
	ShowAMG(G);
	DFSAMG(G,0);
	cout<<endl;
	BFSAMG(G,0,Q);


}
/*
6 
10 
A B C D E F
V1 V2 W
A  B  5
A  D  7
B  C  4
C  A  8
C  F  9
D  F  6
D  C  5
E  D  5
F  E  1
F  A  3
*/


/*
V1 V2 W
A  B  1
A  C  1
B  D  1
B  E  1
D  H  1
C  F  1
C  G  1
*/

/*
v1 v2 5
v1 v4 7
v2 v3 4
v3 v1 8
v3 v6 9
v4 v6 6
v5 v4 5
v6 v1 3
v6 v5 1
v4 v3 5
*/
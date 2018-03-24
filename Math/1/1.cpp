#include <iostream>
#include <string>
using namespace std;
#define Max 100
typedef struct {
	int data[Max][Max];
	//int **data;
	int vnum;//顶点数;
	int bnum;//边数
	//string *V;
	string V[Max];
}AMGraph;

//初始化
void InitAMG(AMGraph &G){
//	int n;//n是顶点
//	int m;//边数
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
		
//输入
void InputAMG(AMGraph&G,int n,int m){
	string v1,v2;
	int a,b;
	cout<<"请输入顶点数：";
	cin>>G.vnum;
	cout<<"请输入边数:";
	cin>>G.bnum;
	cout<<"请输入各个顶点：";
	for(int i=0;i<G.vnum;i++)
		cin>>G.V[i];
	cout<<"请输入各条边的两个端点"<<endl;
		for(i=0;i<G.bnum;i++){
			cin>>v1>>v2;
			a=Locate(G,v1);
			b=Locate(G,v2);
			G.data[a][b]=1;
		}
}
//输出
void ShowAMG(AMGraph G){
	for(int i=0;i<G.vnum;i++){
		for(int j=0;j<G.vnum;j++)
			cout<<G.data[i][j]<<" ";
		cout<<endl;
	}
}
//判断

		

int main(){
	AMGraph M;
	InitAMG(M);
	InputAMG(M,5,5);
	ShowAMG(M);
	return 0;
}



/*
请输入顶点数：6
请输入边数:14
请输入各个顶点：1 2 3 4 5 6
请输入各条边的两个端点
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
#include <iostream>
using namespace std;
#define N  100  //行
#define M  100  //列
struct Map{
	int Row;//行
	int Arr;//列
	int map[N][M];

};
//得到地图
void GetMap(Map & Map)
{   
	cout<<"请输入行数: "; cin>>Map.Row;
	cout<<"请输入列数: "; cin>>Map.Arr;
	cout<<"请数入"<<Map.Row<<"*"<<Map.Arr<<"的矩阵: "<<endl;
	for(int i=1;i<=Map.Row;i++)   //[1][1]入口 [8][9]出口
		for(int j=1;j<=Map.Arr;j++)
			cin>>Map.map[i][j];
			for(int r=0;r<=Map.Row+1;r++)
	{	Map.map[r][0]=1;
	    Map.map[r][Map.Arr+1]=1;
	}
	for(int a=0;a<=Map.Arr+1;a++)
	{	Map.map[0][a]=1;
	    Map.map[Map.Row+1][a]=1;
	}
}
//输出地图
void ShowMap(Map & Map){
	cout<<"输出地图："<<endl;

	for(int i=0;i<=Map.Row+1;i++)
	{	for(int j=0;j<=Map.Arr+1;j++)
			cout<<Map.map[i][j]<<" ";
		cout<<endl;
	}
}
//链栈结构体
typedef struct SNode{
     SNode * next;
	 int dir;//上 下 左 右分别为1 2 3 4
	 int Pos_X;
	 int Pos_Y;
} *LinkStack;
LinkStack p,t;
//栈初始化
void StackInit(LinkStack &S){
   S=new SNode;
   S->next=NULL;
   S->Pos_X=1;
   S->Pos_Y=1;
}
//入栈
void Push(LinkStack &S,int x,int y){
	t=new SNode;
	if(!t) cout<<"错误！申请空间失败！"<<endl;
	t->Pos_X=x;
	t->Pos_Y=y;
	t->next=S;
	S=t;
	
}
//出栈
void Pop(LinkStack &S){
	if(S==NULL)  cout<<"错误！这是一个空栈！"<<endl;
     t=S;
	 S=S->next;
	 free(t);
}
//防止来回
int found(int x,int y,LinkStack &S){
	p=S;
	while(p!=NULL){
		if(x==p->Pos_X&&y==p->Pos_Y)
			return 1;
		p=p->next;
	}
	return 0;
}
void MazeProblem(LinkStack &S,Map &m){
       StackInit(S);
	   int x,y;//direction为1 2 3 4 东南西北
	   while(S&&(S->Pos_X!=m.Row||S->Pos_Y!=m.Arr)){//S
		   x=S->Pos_X;
		   y=S->Pos_Y;
			   if(y+1<=m.Arr&&m.map[x][y+1]==0&&!found(x,y+1,S)){
				   Push(S,x,y+1);
				   S->next->dir=1;
				   continue;
			   } 
			   if(x+1<=m.Row&&m.map[x+1][y]==0&&!found(x+1,y,S)){
				   Push(S,x+1,y);
				   S->next->dir=2;
				    continue;
			   }
			   if(y-1>=1&&m.map[x][y-1]==0&&!found(x,y-1,S)){
				   Push(S,x,y-1);
				   S->next->dir=3;
				    continue;
			   }
			     if(x-1>=1&&m.map[x-1][y]==0&&!found(x-1,y,S)){
				   Push(S,x-1,y);
					S->next->dir=4;
					 continue;
			   } 
               else 
			   {
			     m.map[S->Pos_X][S->Pos_Y]=1;
				 Pop(S);
			   }			   
	   }	  
}
void Info(LinkStack S){

	LinkStack p=S;
	LinkStack t,L;
	L=NULL;
		if(S==NULL)  cout<<"没路！"<<endl;
		else    {p->dir=1;cout<<"路径为:"<<endl;}	
		while(p!=NULL){
		t=new SNode;
		t->dir=p->dir;
		t->Pos_X=p->Pos_X;
		t->Pos_Y=p->Pos_Y;
		t->next=L;
		L=t;
		p=p->next;
		}
		while(L){
		cout<<"("<<L->Pos_X<<","<<L->Pos_Y<<","<<L->dir<<")"<<endl;
		L=L->next;
		}	  	
}

//主函数
void main(){
   LinkStack S;
   Map Maze;
   GetMap(Maze);
   ShowMap(Maze);
   MazeProblem(S,Maze);
   Info(S);
}
/*
0 0 1 0 0 0 1 0
0 0 1 0 0 0 1 0
0 0 0 0 1 1 0 1
0 1 1 1 0 0 1 0
0 0 0 1 0 0 0 0
0 1 0 0 0 1 0 1
0 1 1 1 1 0 0 1
1 1 0 0 0 1 0 1
1 1 0 0 0 0 0 0
*/
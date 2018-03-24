#include <iostream>
using namespace std;
#define N  100  //��
#define M  100  //��
struct Map{
	int Row;//��
	int Arr;//��
	int map[N][M];

};
//�õ���ͼ
void GetMap(Map & Map)
{   
	cout<<"����������: "; cin>>Map.Row;
	cout<<"����������: "; cin>>Map.Arr;
	cout<<"������"<<Map.Row<<"*"<<Map.Arr<<"�ľ���: "<<endl;
	for(int i=1;i<=Map.Row;i++)   //[1][1]��� [8][9]����
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
//�����ͼ
void ShowMap(Map & Map){
	cout<<"�����ͼ��"<<endl;

	for(int i=0;i<=Map.Row+1;i++)
	{	for(int j=0;j<=Map.Arr+1;j++)
			cout<<Map.map[i][j]<<" ";
		cout<<endl;
	}
}
//��ջ�ṹ��
typedef struct SNode{
     SNode * next;
	 int dir;//�� �� �� �ҷֱ�Ϊ1 2 3 4
	 int Pos_X;
	 int Pos_Y;
} *LinkStack;
LinkStack p,t;
//ջ��ʼ��
void StackInit(LinkStack &S){
   S=new SNode;
   S->next=NULL;
   S->Pos_X=1;
   S->Pos_Y=1;
}
//��ջ
void Push(LinkStack &S,int x,int y){
	t=new SNode;
	if(!t) cout<<"��������ռ�ʧ�ܣ�"<<endl;
	t->Pos_X=x;
	t->Pos_Y=y;
	t->next=S;
	S=t;
	
}
//��ջ
void Pop(LinkStack &S){
	if(S==NULL)  cout<<"��������һ����ջ��"<<endl;
     t=S;
	 S=S->next;
	 free(t);
}
//��ֹ����
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
	   int x,y;//directionΪ1 2 3 4 ��������
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
		if(S==NULL)  cout<<"û·��"<<endl;
		else    {p->dir=1;cout<<"·��Ϊ:"<<endl;}	
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

//������
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
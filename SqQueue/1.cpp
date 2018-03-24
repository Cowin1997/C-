#include <iostream>
using namespace std;
#define OK 1
#define FALSE 0
const int N=20;
typedef struct {
	int *base;
	int front;
	int rear;
}SqQueue;

//初始化队列
int InitQueue(SqQueue &Q){
	Q.base=(int*)malloc(N*sizeof(int));
	if(!Q.base){
		cout<<"内存分配失败！"<<endl;
		return FALSE;
	}
	Q.front=Q.rear=0;
	return OK;
}
//入队
int InQueue(SqQueue &Q,int e){
	if((Q.rear+1)%N==Q.front){
		cout<<"进队失败！队满！"<<endl;
		return FALSE;
	}
	else{
		Q.base[Q.rear]=e;
		Q.rear=(Q.rear+1)%N;
		return OK;
	}
}
//出队
int OutQueue(SqQueue &Q,int &e){
	if(Q.front==Q.rear){
		cout<<"出队失败！队列为空!"<<endl;
		return FALSE;
	}
	else
	{
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%N;
	return OK;
	}
}/*
void main(){
	SqQueue Q;
	int e;
	InitQueue(Q);
	for(int i=1;i<N;i++)
		InQueue(Q,i);
	for(int j=1;j<N;j++)
	{	OutQueue(Q,e);
	    cout<<e<<"出队！"<<endl;
	}
	cout<<endl;
	InQueue(Q,100);
	while(Q.front!=Q.rear)
	{		OutQueue(Q,e);
			cout<<e<<"  ";
	}

	cout<<"最后"<<e<<"出队！"<<endl;
    	OutQueue(Q,e);	
}



*/


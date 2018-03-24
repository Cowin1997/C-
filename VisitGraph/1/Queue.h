#include <iostream>
using namespace std;
typedef struct Qnode{
	int data;
	Qnode *next;
}*Queue;
typedef struct{
	Queue Head;
	Queue Rear;
}LinkQueue;
//构造空队列
void InitLinkQueue(LinkQueue &Q){
	Q.Head=Q.Rear=new Qnode;
	if(!Q.Head) exit(3);
	Q.Head->next=NULL;
}
//入队
void InQueue(LinkQueue &Q,int e){
	Queue t=new Qnode;
	if(!t) exit(3);
	t->data=e;t->next=NULL;
	Q.Rear->next=t;//**
	Q.Rear=t;
}
//出队
void DeQueue(LinkQueue &Q,int &e){
	 if(Q.Head==Q.Rear) {  cout<<"队空！"<<endl; return ;} 
     Queue p=Q.Head->next;
	 e=p->data;
	 Q.Head->next=p->next;
	 if(Q.Rear==p) Q.Rear=Q.Head;
	 delete p;
}













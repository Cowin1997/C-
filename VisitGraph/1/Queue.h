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
//����ն���
void InitLinkQueue(LinkQueue &Q){
	Q.Head=Q.Rear=new Qnode;
	if(!Q.Head) exit(3);
	Q.Head->next=NULL;
}
//���
void InQueue(LinkQueue &Q,int e){
	Queue t=new Qnode;
	if(!t) exit(3);
	t->data=e;t->next=NULL;
	Q.Rear->next=t;//**
	Q.Rear=t;
}
//����
void DeQueue(LinkQueue &Q,int &e){
	 if(Q.Head==Q.Rear) {  cout<<"�ӿգ�"<<endl; return ;} 
     Queue p=Q.Head->next;
	 e=p->data;
	 Q.Head->next=p->next;
	 if(Q.Rear==p) Q.Rear=Q.Head;
	 delete p;
}













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

//��ʼ������
int InitQueue(SqQueue &Q){
	Q.base=(int*)malloc(N*sizeof(int));
	if(!Q.base){
		cout<<"�ڴ����ʧ�ܣ�"<<endl;
		return FALSE;
	}
	Q.front=Q.rear=0;
	return OK;
}
//���
int InQueue(SqQueue &Q,int e){
	if((Q.rear+1)%N==Q.front){
		cout<<"����ʧ�ܣ�������"<<endl;
		return FALSE;
	}
	else{
		Q.base[Q.rear]=e;
		Q.rear=(Q.rear+1)%N;
		return OK;
	}
}
//����
int OutQueue(SqQueue &Q,int &e){
	if(Q.front==Q.rear){
		cout<<"����ʧ�ܣ�����Ϊ��!"<<endl;
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
	    cout<<e<<"���ӣ�"<<endl;
	}
	cout<<endl;
	InQueue(Q,100);
	while(Q.front!=Q.rear)
	{		OutQueue(Q,e);
			cout<<e<<"  ";
	}

	cout<<"���"<<e<<"���ӣ�"<<endl;
    	OutQueue(Q,e);	
}



*/


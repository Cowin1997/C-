#include <iostream>
#define OK 1
#define ERROR 0
using namespace std;
typedef struct QN{
	int data;
	QN *next;
}*QNode;
typedef struct p_QNode{
	QNode front;
	QNode rear;
}*LinkQueue;
//��ʼ����
int InitLQueue(LinkQueue &LQ){
	LQ->front=LQ->rear=NULL;
	return OK;
}
//���















void main(){
}




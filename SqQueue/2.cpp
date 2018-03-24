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
//初始化啊
int InitLQueue(LinkQueue &LQ){
	LQ->front=LQ->rear=NULL;
	return OK;
}
//入队















void main(){
}




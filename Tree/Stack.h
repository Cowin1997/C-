
#include <iostream>
using namespace std;
//��ջ
typedef struct LNode{
	char c;
	LNode *next;
}LNode,*Linklist;


//��ʼ��
void InitStack(Linklist &L){
	L=NULL;
}

//��ջ
void Push(Linklist &L,char ch){
	Linklist t;
	t=new LNode;
	t->c=ch;
	t->next=L;
	L=t;
}
//��ջ
void Pop(Linklist &L,BitNode q){
	Linklist p;
	p=L;
	if(!p) cout<<"Empty Stack!"<<endl;
	else{
		cout<<p->c;
		L=p->next;
		free(p);
	}
}
//�ж�ջ��
int StackEmpty(Linklist L){
	if(L=NULL) return 1;
	else    return 0;
}


	
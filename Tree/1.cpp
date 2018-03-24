#include <iostream>
//#include "Stack.h"
using namespace std;
typedef char Telemtype;
typedef struct BiTNode{
	char c;
	BiTNode *lchild;
	BiTNode *rchild;
}BiTNode,*BiTree;


//��ջ
typedef struct SNode{
	char c;
	BiTNode *cpylchild;
	BiTNode *cpyrchild;
	SNode *next;

}SNode,*Stack;
Stack S;
//��ʼ����ջ
void InitStack(Stack &S){
	S=NULL;
} 
//��ջ����������������ջS
void Push(Stack &S,BiTree p){
	Stack t;
	t=new SNode;
	t->c=p->c;
	t->cpylchild=p->lchild;
	t->cpyrchild=p->rchild;
	t->next=S;
	S=t;
}
//��ջ����ջS�������˵�q
void Pop(Stack &S,BiTree &q){
	if(S!=NULL){
	q->c=S->c;
	q->lchild=S->cpylchild;
	q->rchild=S->cpyrchild;
	}
	else
		cout<<"S�ǿ�ջ��"<<endl;
	S=S->next;
	
}

//��ʼ������
void InitTree(BiTree &T){
	T=NULL;
}

//�������������
void CreatTree(BiTree &T){
	char ch;
	cin>>ch;
	if(ch=='#') T=NULL;
	else{
		T=new BiTNode;
		T->c=ch;
		CreatTree(T->lchild);
		CreatTree(T->rchild);
	}
}

//��������
void Visit(BiTree T){
	cout<<T->c<<" ";
}

//�������  �ݹ�
void PreTraverse(BiTree T){
	if(T){
		Visit(T);
		PreTraverse(T->lchild);
		PreTraverse(T->rchild);
	}
}

//������� �ǵݹ�
void PreTraverse_N(BiTree T){
	InitStack(S);
	BiTree t,p;
	BiTree q;
	t=new BiTNode;
	q=t;
	p=T;
	if(p)  Push(S,p);
	while(S){
		q=t;//                                 ��
		Pop(S,q);
		while(q!=NULL){
		Visit(q);

		if(q->rchild!=NULL) Push(S,q->rchild);

			q=q->lchild;// p����û����ջ����p�������ѭ������ ָ��NULL ������Pop(S,q) qΪ�գ�^^^^^)						 
}
}
}//-*ad##e##bf##g##ch####
	
//A B D H # # I # # E J # # K # # C F L # # # G # #





//������� �ݹ�
void InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->lchild);
		Visit(T);
		InOrderTraverse(T->rchild);
	}
}
//������� �ǵݹ�
void InOrderTraverse_N(BiTree T){
    InitStack(S);
	BiTree p,q;
	p=T;
	q=new BiTNode;
	while(S||p){
		if(p){
			Push(S,p);
			p=p->lchild;
		}
		else{
			Pop(S,q);
			Visit(q);//<<" ";
			p=q->rchild;
		}
}
}
//������� �ݹ�
void LastTraverse(BiTree T){
	if(T){
		LastTraverse(T->lchild);
		LastTraverse(T->rchild);
		Visit(T);
	}
}
//������
int main(){
	BiTree T;
	InitTree(T);
	CreatTree(T);
	//����ĵݹ�ͷǵݹ�
	cout<<"����ݹ�ͷǵݹ�"<<endl;
	{
	PreTraverse(T);
	cout<<endl;
   PreTraverse_N(T);
	cout<<endl;


	}
	//����ĵݹ�ͷǵݹ�
	cout<<"����ݹ�ͷǵݹ�"<<endl;
	{
	InOrderTraverse(T);
	cout<<endl;
	InOrderTraverse_N(T);
	cout<<endl;
	}
	//����ݹ�
		cout<<"����ݹ�"<<endl;
	LastTraverse(T);
	cout<<endl;
	return 0;
}
	






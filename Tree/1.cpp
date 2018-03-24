#include <iostream>
//#include "Stack.h"
using namespace std;
typedef char Telemtype;
typedef struct BiTNode{
	char c;
	BiTNode *lchild;
	BiTNode *rchild;
}BiTNode,*BiTree;


//链栈
typedef struct SNode{
	char c;
	BiTNode *cpylchild;
	BiTNode *cpyrchild;
	SNode *next;

}SNode,*Stack;
Stack S;
//初始化链栈
void InitStack(Stack &S){
	S=NULL;
} 
//入栈；把树结点的数据入栈S
void Push(Stack &S,BiTree p){
	Stack t;
	t=new SNode;
	t->c=p->c;
	t->cpylchild=p->lchild;
	t->cpyrchild=p->rchild;
	t->next=S;
	S=t;
}
//出栈；把栈S的数据退到q
void Pop(Stack &S,BiTree &q){
	if(S!=NULL){
	q->c=S->c;
	q->lchild=S->cpylchild;
	q->rchild=S->cpyrchild;
	}
	else
		cout<<"S是空栈！"<<endl;
	S=S->next;
	
}

//初始化空树
void InitTree(BiTree &T){
	T=NULL;
}

//按先序遍历输入
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

//访问数据
void Visit(BiTree T){
	cout<<T->c<<" ";
}

//先序遍历  递归
void PreTraverse(BiTree T){
	if(T){
		Visit(T);
		PreTraverse(T->lchild);
		PreTraverse(T->rchild);
	}
}

//先序遍历 非递归
void PreTraverse_N(BiTree T){
	InitStack(S);
	BiTree t,p;
	BiTree q;
	t=new BiTNode;
	q=t;
	p=T;
	if(p)  Push(S,p);
	while(S){
		q=t;//                                 ↓
		Pop(S,q);
		while(q!=NULL){
		Visit(q);

		if(q->rchild!=NULL) Push(S,q->rchild);

			q=q->lchild;// p这里没有入栈！！p到这如果循环结束 指向NULL 而上面Pop(S,q) q为空，^^^^^)						 
}
}
}//-*ad##e##bf##g##ch####
	
//A B D H # # I # # E J # # K # # C F L # # # G # #





//中序遍历 递归
void InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->lchild);
		Visit(T);
		InOrderTraverse(T->rchild);
	}
}
//中序遍历 非递归
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
//后序遍历 递归
void LastTraverse(BiTree T){
	if(T){
		LastTraverse(T->lchild);
		LastTraverse(T->rchild);
		Visit(T);
	}
}
//主函数
int main(){
	BiTree T;
	InitTree(T);
	CreatTree(T);
	//先序的递归和非递归
	cout<<"先序递归和非递归"<<endl;
	{
	PreTraverse(T);
	cout<<endl;
   PreTraverse_N(T);
	cout<<endl;


	}
	//中序的递归和非递归
	cout<<"中序递归和非递归"<<endl;
	{
	InOrderTraverse(T);
	cout<<endl;
	InOrderTraverse_N(T);
	cout<<endl;
	}
	//后序递归
		cout<<"后序递归"<<endl;
	LastTraverse(T);
	cout<<endl;
	return 0;
}
	






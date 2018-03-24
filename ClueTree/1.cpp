#include <iostream>
using namespace std;
typedef int TElemType;
typedef struct BiThrNode{
	char data;
	BiThrNode *lchild,*rchild;
	int LTag,Rtag;
}BiThrNode,*BiThrTree;
	BiThrTree pre;

/*
	��ʼ��
*/
void InitBiThrTree(BiThrTree &T){
	T=NULL;
}
/*
	��������
*/
void PutData(BiThrTree &T){
	char ch;
	cin>>ch;
if(ch=='#') T=NULL;
else{
	T=new BiThrNode;
	T->data=ch;
	PutData(T->lchild);
	PutData(T->rchild);
	}
}
/*
	����������
*/
void InThreading(BiThrTree p){
	if(p){
		InThreading(p->lchild);
		if(!p->lchild){        //  P�����ӿ�
			p->LTag=1; 	//Tag=1 ����
			p->lchild=pre;            
		}
		else p->LTag=0;
		if(!pre->rchild){       // pre�Һ���Ϊ��     
		pre->Rtag=1;
		pre->rchild=p;
		}
	else	pre->Rtag=0;
		pre=p;
		InThreading(p->rchild);
	}
}
/*
	��ͷ��������������
*/
void InOrderThreading(BiThrTree &Thrt,BiThrTree T){
	//�������������T������������Thrtָ��ͷ���
	Thrt=new BiThrNode;
	Thrt->data='!';
	Thrt->LTag=0;
	Thrt->Rtag=1;
	Thrt->rchild=Thrt;
	if(!T) Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		InThreading(T);
		pre->rchild=Thrt;
		pre->Rtag=1;
		Thrt->rchild=pre;
	}
	Thrt->Rtag=1;
}

void InOrderTraverse(BiThrTree T){
	if(T){
		InOrderTraverse(T->lchild);
	//	Visit(T);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
}
void Show2(BiThrTree T){
	BiThrTree p;
	p=T->lchild;
	while(p!=T){
		while(p->LTag==0)  p=p->lchild;
		cout<<p->data;
		while(p->Rtag==1&&p->rchild!=T){
			p=p->rchild;cout<<p->data;
		}
		p=p->rchild;
	}
}













int main(){


	BiThrTree Thrt,T;
	InitBiThrTree(Thrt);
	InitBiThrTree(T);
	PutData(T);
	InOrderTraverse(T);
	InOrderThreading(Thrt,T);
//cout<<endl<<Thrt->Rtag<<endl;//-*a##b##c##
	cout<<endl;
	Show2(Thrt);
	cout<<endl;

//-+a##*b##-c##d##/e##f##




return 0;
}
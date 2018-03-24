
#include <iostream>
using namespace std;
//Á´Õ»
typedef struct LNode{
	char c;
	LNode *next;
}LNode,*Linklist;


//³õÊ¼»¯
void InitStack(Linklist &L){
	L=NULL;
}

//ÈëÕ»
void Push(Linklist &L,char ch){
	Linklist t;
	t=new LNode;
	t->c=ch;
	t->next=L;
	L=t;
}
//³öÕ»
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
//ÅÐ¶ÏÕ»¿Õ
int StackEmpty(Linklist L){
	if(L=NULL) return 1;
	else    return 0;
}


	
#include <iostream>
using namespace std;
typedef int elemtype;
typedef struct SNode{
	elemtype data;
	SNode * next;
}*LinkStack;
LinkStack t,p;
//��ʼ��
void InitLinkStack(LinkStack &S,int  n){
	S=new SNode;
	S->next=NULL;
	if(n>0)
	cout<<"please input "<<n<<" data��"<<endl;
	for(int i=1;i<=n;i++){
	 t=new SNode;
		if(!t) cout<<"����ռ�ʧ�ܣ�"<<endl;
		cin>>t->data;
		t->next=S->next;
		S->next=t;
}
}
//��ջ
void Push(LinkStack &S,elemtype e){
     t=new SNode;
	t->data=e;
	t->next=S->next;
		S->next=t;
}
//��ջ
void Pop(LinkStack &S){
	if(!S->next) cout<<"ջ�գ�"<<endl;
	else
		cout<<S->next->data<<endl;
		p=S->next;
	   S->next=p->next;
	   delete p;
}
//��ջ��
void StackEmpty(LinkStack &S){
	if(S->next==NULL) cout<<"ջ�գ�"<<endl;
}
//��ջ��
int StackLength(LinkStack &S){
	int j=0;
	p=S;
	while(p->next){ p=p->next;j++;}
		return j;
	}
//��ջ��
int StackTop(LinkStack &S){
	return S->next->data;
}
//���ջ
void ClearStack(LinkStack &S){
	while(S->next) 
	{
		p=S->next;
		S->next=p->next;
		delete p;
	}
}
//������
int main(){
   LinkStack S;
	InitLinkStack(S,0);
	Push(S,100);
	ClearStack(S);
//	Pop(S);
	cout<<StackLength(S)<<endl;
//	cout<<StackTop(S)<<endl;



	return 0;
}





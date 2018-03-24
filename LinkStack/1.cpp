#include <iostream>
using namespace std;
typedef int elemtype;
typedef struct SNode{
	elemtype data;
	SNode * next;
}*LinkStack;
LinkStack t,p;
//³õÊ¼»¯
void InitLinkStack(LinkStack &S,int  n){
	S=new SNode;
	S->next=NULL;
	if(n>0)
	cout<<"please input "<<n<<" data£º"<<endl;
	for(int i=1;i<=n;i++){
	 t=new SNode;
		if(!t) cout<<"ÉêÇë¿Õ¼äÊ§°Ü£¡"<<endl;
		cin>>t->data;
		t->next=S->next;
		S->next=t;
}
}
//ÈëÕ»
void Push(LinkStack &S,elemtype e){
     t=new SNode;
	t->data=e;
	t->next=S->next;
		S->next=t;
}
//³öÕ»
void Pop(LinkStack &S){
	if(!S->next) cout<<"Õ»¿Õ£¡"<<endl;
	else
		cout<<S->next->data<<endl;
		p=S->next;
	   S->next=p->next;
	   delete p;
}
//ÅÐÕ»¿Õ
void StackEmpty(LinkStack &S){
	if(S->next==NULL) cout<<"Õ»¿Õ£¡"<<endl;
}
//ÇóÕ»³¤
int StackLength(LinkStack &S){
	int j=0;
	p=S;
	while(p->next){ p=p->next;j++;}
		return j;
	}
//¶ÁÕ»¶¥
int StackTop(LinkStack &S){
	return S->next->data;
}
//Çå¿ÕÕ»
void ClearStack(LinkStack &S){
	while(S->next) 
	{
		p=S->next;
		S->next=p->next;
		delete p;
	}
}
//Ö÷º¯Êý
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





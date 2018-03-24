#include <iostream>
using namespace std;
typedef struct Node{
	int data;
	int no;
	Node * next;
}Node,*Linklist;
Node *p,*t,*q;
//初始化,并生成n个结点
void Initlist(Linklist &L,int n){
	L=new Node;
	L->next=NULL;
	for(int i=1;i<=n;i++){	
		cout<<"请输入第"<<i<<"数据:  ";
		t=new Node;
	    t->no=i;
		cin>>t->data;
		if(L->next==NULL){
		//	p=L;
			L->next=t;
			p=t;
		}
		else
		{	p->next=t;
			p=p->next;
		}
		if(i==n)
			p->next=L->next;
	
	}

}
//查找元素
void GetElem(Linklist L,int i,int &e){
	p=L->next;
	int j=1;
	while(p&&j<i){
		p=p->next;
		j++;
	}
	if(!p||j>i)
		cout<<"Error!"<<endl;
	e=p->data;
	cout<<"-------------------------"<<endl;
		cout<<"要查找的第"<<i<<"个元素是："<<e<<endl;
		cout<<"-------------------------"<<endl;
}
//删除结点
void Listdelet(Linklist &L,int i,int &e){
	p=L;
	int j=1;
	while(p&&j<i){
		p=p->next;
		j++;
	}
	if(!p||j>i)
		cout<<"Error!"<<endl;
	q=p->next;
	e=q->data;
	p->next=q->next;
	delete q;
	cout<<"-------------------------"<<endl;
	cout<<"删除的是第"<<i<<"个元素:"<<e<<endl;
	cout<<"-------------------------"<<endl;
}
//求表长
int ListLength(Linklist &L){
	int count=0;
	p=L->next;
	while(p){
		count++;
		p=p->next;
	}
	cout<<"-------------------------"<<endl;
	cout<<"表长是: "<<count<<endl;
	cout<<"-------------------------"<<endl;
	return count;
}
//插入结点
void ListInsec(Linklist &L,int i,int e){
     int j=1;
	 p=L;
	 while(p&&j<i)
	 {
		 p=p->next;
		 j++;
	 }
	 if(!p||j>i)//i不能大于表长且不能小于0
	  cout<<"Error!"<<endl;
	
	 
    t=new Node;
	t->data=e;
	t->next=p->next;
	p->next=t;
}

//输出
void show(Linklist &L){
	cout<<"------下面输出链表-------"<<endl;
	q=L->next;
   int j=1;
   while(q!=NULL){
     cout<<"第"<<j<<"数据是:  ";
	 cout<<q->data<<endl;
	 q=q->next;
	 j++;
}
}
//实现约瑟夫环
void YSFF(Linklist &L,int n,int m){
	p=L->next;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			p=p->next;
			if(p==L)
				p=p->next;
		}
       m=p->data;
	   cout<<p->no<<endl;
	   p->data=p->next->data;
	   p->no=p->next->no;
	   q=p->next;
	   p->next=p->next->next;  
	   free(q);
	   }
}

//
void TEST(Linklist &L,int l){
	p=L->next;
	q=p->next->next;
	l=q->data;
	
	free(q);cout<<l<<endl;
}















//主函数		
int main(){
//  int e;
   Linklist Mylist;
	Initlist(Mylist,3);
//	show(Mylist);
//	GetElem(Mylist,1,e);
//	Listdelet(Mylist,3,e);
//	show(Mylist);
//	ListLength(Mylist);
//	ListInsec(Mylist,6,999);
//	show(Mylist);
//	YSFF(Mylist,7,20);
    TEST(Mylist,3);
	return 0;

}

#include <iostream>
using namespace std;
typedef struct Node{
	int data;
	int no;
	Node * next;
}Node,*Linklist;
Node *p,*t,*q;
//��ʼ��,������n�����
void Initlist(Linklist &L,int n){
	L=new Node;
	L->next=NULL;
	for(int i=1;i<=n;i++){	
		cout<<"�������"<<i<<"����:  ";
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
//����Ԫ��
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
		cout<<"Ҫ���ҵĵ�"<<i<<"��Ԫ���ǣ�"<<e<<endl;
		cout<<"-------------------------"<<endl;
}
//ɾ�����
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
	cout<<"ɾ�����ǵ�"<<i<<"��Ԫ��:"<<e<<endl;
	cout<<"-------------------------"<<endl;
}
//���
int ListLength(Linklist &L){
	int count=0;
	p=L->next;
	while(p){
		count++;
		p=p->next;
	}
	cout<<"-------------------------"<<endl;
	cout<<"����: "<<count<<endl;
	cout<<"-------------------------"<<endl;
	return count;
}
//������
void ListInsec(Linklist &L,int i,int e){
     int j=1;
	 p=L;
	 while(p&&j<i)
	 {
		 p=p->next;
		 j++;
	 }
	 if(!p||j>i)//i���ܴ��ڱ��Ҳ���С��0
	  cout<<"Error!"<<endl;
	
	 
    t=new Node;
	t->data=e;
	t->next=p->next;
	p->next=t;
}

//���
void show(Linklist &L){
	cout<<"------�����������-------"<<endl;
	q=L->next;
   int j=1;
   while(q!=NULL){
     cout<<"��"<<j<<"������:  ";
	 cout<<q->data<<endl;
	 q=q->next;
	 j++;
}
}
//ʵ��Լɪ��
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















//������		
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

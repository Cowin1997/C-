 #include <iostream>
using namespace std;
const int N=7 ;
const int M=20;
typedef int elemtype;
typedef struct Node{
	elemtype Code;
	int No;
	Node *next;
}*Linklist;
Linklist q,p,t;
// ��ͷ���
void InitList(Linklist &L,int n){
	L=p=NULL;
	for(int i=1;i<=n;i++){
		t=new Node;
		cout<<"�������"<<i<<"��ѧ���������ǣ�";
		cin>>t->Code;
		t->No=i;
		if(p==NULL)
		{	p=t;
		    L=t;}
		else 
		{	p->next=t;
			p=p->next;
		}
		if(i==n)
			p->next=L;
	}
}
//ʵ��Լɪ��
void YSFF(Linklist &L,int n,int m){
  cout<<"���˳��"<<endl;
	p=L; t=L;
	for(int i=1;i<=n;i++)
	{	for(int j=1;j<m;j++){p=p->next;}
		m=p->Code;
    	cout<<p->No<<endl;
		p->No=p->next->No;
		p->Code=p->next->Code;
		q=p->next;
        p->next=q->next;
        free(q);
	//	������
   /*	q=p;
	m=p->Code;
	cout<<p->No<<" ";
	while(t->next!=p){t=t->next;}
	t->next=p->next;
	p=p->next;
	free(q);*/
	}

}
//������
	int main(){
		Linklist Mylist;
		InitList(Mylist,N);
		YSFF(Mylist,N,M);//n=7 m=20
		return 0;
	}

// 3 1 7 2 4 8 4 
// 6 1 4 7 2 3 5

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
// 无头结点
void InitList(Linklist &L,int n){
	L=p=NULL;
	for(int i=1;i<=n;i++){
		t=new Node;
		cout<<"请输入第"<<i<<"个学生的密码是：";
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
//实现约瑟夫环
void YSFF(Linklist &L,int n,int m){
  cout<<"输出顺序："<<endl;
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
	//	方法二
   /*	q=p;
	m=p->Code;
	cout<<p->No<<" ";
	while(t->next!=p){t=t->next;}
	t->next=p->next;
	p=p->next;
	free(q);*/
	}

}
//主函数
	int main(){
		Linklist Mylist;
		InitList(Mylist,N);
		YSFF(Mylist,N,M);//n=7 m=20
		return 0;
	}

// 3 1 7 2 4 8 4 
// 6 1 4 7 2 3 5

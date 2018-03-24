#include <iostream>
using namespace std;
const LIST_INIT_SIZE=10;
const LISTINCREMENT=5;
typedef int elemtype;
struct SqList{
elemtype * base;//����ַָ��
elemtype length;//���Ա�ĳ���
int listsize;//���Ա�Ĵ洢����
};
//��ʼ��
int Initialize (SqList &L){
L.length=0;
L.listsize=LIST_INIT_SIZE;
L.base=new int [ LIST_INIT_SIZE];
if(!L.base) { cout<<"�洢����ʧ�ܣ�"<<endl; return 0;}
 return 1;
}
//����
void Search (SqList & L){
int x;
cout<<"��������Ҫ���ҵ�����:"<<endl;
cin>>x;
for(int i=0;i<L.length;i++)
		if(x==L.base[i])     cout<<"�������ҵ���"<<"λ���ǣ� "<<i+1<<endl;
		if(i>L.length)    cout<<"����δ�ҵ�!"<<endl;
}
//����
int Insec(SqList &L,int InsecLoc,elemtype e){
	int *newbase;
	int *p,*q;
	if(InsecLoc<1||InsecLoc>L.length+1) {cout<<"�������Χ��"<<endl;return 0;}
	if(L.length>=L.listsize){
		 newbase=(elemtype *)realloc(L.base,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(int));
      	if(!newbase) {cout<<"�������ʧ�ܣ�"<<endl;return -1;}
		  L.base=newbase;
		L.listsize+=LISTINCREMENT;
	}
		q=L.base+InsecLoc-1;
		p=L.base+L.length-1;
		for(p;p>=q;p--)
			*(p+1)=*p;
			*q=e;
			L.length++;		
			return 1;
}
//���
void Output(SqList &L){
		cout<<"��������"<<endl;
		for(int i=0;i<L.length;i++)
		cout<<L.base[i]<<"	"<<endl;
}
//���
int SqListLen(SqList &L){
	return L.length;
}
//ɾ��
int Delete(SqList &L){
	int idelete;
	cout<<"����Ҫɾ���ĵ�i��Ԫ�� "<<endl;
	cin>>idelete;
	int deletedata=L.base[idelete-1]; 
	if(idelete<1||idelete>L.length){cout<<"�������ֵ����Χ��"<<endl; return -1;}
	for(int i=idelete-1;i<L.length-1;i++)
		L.base[i]=L.base[i+1];
	     L.length--;
	    cout<<"ɾ���ɹ��� "<<"ɾ����������:"<<deletedata<<endl;
    return 1;
}
//ð������
void Sort(SqList &L){
	cout<<"�����"<<endl;
	int temp;
	for(int i=0;i<L.length-1;i++)
	for(int j=0;j<(L.length-1-i);j++)
	if(L.base[j]>L.base[j+1]){
	temp=L.base[j];
	L.base[j]=L.base[j+1];
	L.base[j+1]=temp;
	}
}
//���ַ����ҷ�
void Binarysearch (SqList &L){
    Sort(L);
	Output(L);
	int Searchdata;
	cout<<"��������Ҫ���ҵ�����:"<<endl;
	cin>>Searchdata;
	int mid,top,tail;
	top=0;
	tail=L.length-1;
	mid=(tail+top)/2;
	while(top<=tail){
		if(Searchdata==L.base[mid])  { cout<<"���ҵ�!"<<" λ���� : "<<mid+1<<endl;break;}	
	 if(Searchdata>L.base[mid])  {top=mid+1;mid=(top+tail)/2;}
	 if(Searchdata<L.base[mid])  {tail=mid-1;mid=(top+tail)/2;}
	}
	if(top>tail) cout<<"����δ�ҵ�!"<<endl;
}
//������
int main()
{	SqList Mylist;
	Initialize(Mylist);
	Insec(Mylist,1,200);
	Insec(Mylist,2,100);
	Insec(Mylist,3,400);
	Insec(Mylist,4,300);
	Insec(Mylist,1,500);
	Output(Mylist);
	Search(Mylist);
	Delete(Mylist);
	Output(Mylist);
	Binarysearch(Mylist);
	cout<<"����:"<<SqListLen(Mylist)<<endl;
	return 0;
}
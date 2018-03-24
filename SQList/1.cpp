#include <iostream>
using namespace std;
const LIST_INIT_SIZE=10;
const LISTINCREMENT=5;
typedef int elemtype;
struct SqList{
elemtype * base;//基地址指针
elemtype length;//线性表的长度
int listsize;//线性表的存储长度
};
//初始化
int Initialize (SqList &L){
L.length=0;
L.listsize=LIST_INIT_SIZE;
L.base=new int [ LIST_INIT_SIZE];
if(!L.base) { cout<<"存储分配失败！"<<endl; return 0;}
 return 1;
}
//查找
void Search (SqList & L){
int x;
cout<<"请输入你要查找的数据:"<<endl;
cin>>x;
for(int i=0;i<L.length;i++)
		if(x==L.base[i])     cout<<"数据已找到，"<<"位置是： "<<i+1<<endl;
		if(i>L.length)    cout<<"数据未找到!"<<endl;
}
//插入
int Insec(SqList &L,int InsecLoc,elemtype e){
	int *newbase;
	int *p,*q;
	if(InsecLoc<1||InsecLoc>L.length+1) {cout<<"输出超范围！"<<endl;return 0;}
	if(L.length>=L.listsize){
		 newbase=(elemtype *)realloc(L.base,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(int));
      	if(!newbase) {cout<<"储存分配失败！"<<endl;return -1;}
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
//输出
void Output(SqList &L){
		cout<<"输出结果："<<endl;
		for(int i=0;i<L.length;i++)
		cout<<L.base[i]<<"	"<<endl;
}
//求表长
int SqListLen(SqList &L){
	return L.length;
}
//删除
int Delete(SqList &L){
	int idelete;
	cout<<"输入要删除的第i个元素 "<<endl;
	cin>>idelete;
	int deletedata=L.base[idelete-1]; 
	if(idelete<1||idelete>L.length){cout<<"输入的数值超范围！"<<endl; return -1;}
	for(int i=idelete-1;i<L.length-1;i++)
		L.base[i]=L.base[i+1];
	     L.length--;
	    cout<<"删除成功！ "<<"删除的数据是:"<<deletedata<<endl;
    return 1;
}
//冒泡排序
void Sort(SqList &L){
	cout<<"排序后："<<endl;
	int temp;
	for(int i=0;i<L.length-1;i++)
	for(int j=0;j<(L.length-1-i);j++)
	if(L.base[j]>L.base[j+1]){
	temp=L.base[j];
	L.base[j]=L.base[j+1];
	L.base[j+1]=temp;
	}
}
//二分法查找法
void Binarysearch (SqList &L){
    Sort(L);
	Output(L);
	int Searchdata;
	cout<<"请输入你要查找的数据:"<<endl;
	cin>>Searchdata;
	int mid,top,tail;
	top=0;
	tail=L.length-1;
	mid=(tail+top)/2;
	while(top<=tail){
		if(Searchdata==L.base[mid])  { cout<<"已找到!"<<" 位置是 : "<<mid+1<<endl;break;}	
	 if(Searchdata>L.base[mid])  {top=mid+1;mid=(top+tail)/2;}
	 if(Searchdata<L.base[mid])  {tail=mid-1;mid=(top+tail)/2;}
	}
	if(top>tail) cout<<"数据未找到!"<<endl;
}
//主函数
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
	cout<<"表长是:"<<SqListLen(Mylist)<<endl;
	return 0;
}
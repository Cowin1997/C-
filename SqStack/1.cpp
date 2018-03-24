#include <iostream>
using namespace std;
//#define SIZE 5
#define OK 1
#define FALSE 0
typedef  int  status;
typedef int selemtype;
typedef struct Snode{
selemtype *base;
selemtype *top;
int stacksize;
}SqStack;
//判断栈空
status StackEmpty(SqStack &S){
   if(S.top==S.base)  return OK;
   else				 return FALSE;
}
//初始化
status StackInit(SqStack &S,int s){
	S.base=new selemtype [s];
	if(!S.base) return FALSE;
		S.top=S.base;
		S.stacksize=s;
		cout<<"Please input "<<s<<" data:"<<endl;
		for(int i=0;i<s;i++){
			int t;
			cin>>t;
			*(S.top)=t;
			(S.top)++;
		}

	return OK;
}
//入栈
status Push(SqStack &S,selemtype e){
	if(S.top-S.base==S.stacksize){
		S.base=(selemtype*)realloc(S.base,(S.stacksize+1)*sizeof(selemtype));
	    S.stacksize=+1;
	}
    *(S.top)=e;
	S.top++;
	return OK;
}
//出栈
status Pop(SqStack &S){
	if(S.top==S.base)
		return FALSE;
	selemtype	e=*(--S.top);
	return e;
}
//读栈顶
status GetTop(SqStack &S,selemtype &e){
	if(S.top==S.base) return FALSE;
	else 
		e=*(S.top-1);
	return e;
}
//求栈长
void StackLength(SqStack &S){
	cout<< (S.top-S.base);

}

int main(){
	SqStack S;
	StackInit(S,4);
	Push(S,5);
	Push(S,6);
	cout<<"长度：";
	StackLength(S);
	cout<<endl;
	for(int i=1;i<=6;i++)
		cout<<Pop(S)<<endl;
	

	
	
}
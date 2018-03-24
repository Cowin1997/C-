#include <iostream>
using namespace std;
typedef struct Node{
	int n;
	Node *next;
}*LinkStack;
LinkStack OPTR;//运算符号
LinkStack OPND;// 操作数
//初始化
void Init(LinkStack &L){
	L=NULL;
}
//入栈
void Push(LinkStack &L,int Push_Data){
	LinkStack t;
	t=new Node;
    t->n=Push_Data;
	t->next=L;
	L=t;
}
//出栈
int Pop(LinkStack &L){
	LinkStack p;
	int e;
	if(!L) {cout<<"空栈！"<<endl; return -1;}
	else{
		p=L;
		e=p->n;
		L=L->next;
		free(p);
	}
	return e;
}
//
char Precede(char a,char b)
{
	int i,j;
	char GXB[][7]={
		{'>','>','<','<','<','>','>'},//+ - * / ( ) #
		{'>','>','<','<','<','>','>'},//-
		{'>','>','>','>','<','>','>'},//*
		{'>','>','>','>','<','>','>'},///
		{'<','<','<','<','<','=','0'},//(
		{'>','>','>','>','0','>','>'},//)
		{'<','<','<','<','<','0','='} //#
		};// 0 表示不允许的情况
	switch(a){
	case '+':i=0;break;
	case '-':i=1;break;
	case '*':i=2;break;
	case '/':i=3;break;
	case '(':i=4;break;
	case ')':i=5;break;
	case '#':i=6;break;
	}
	switch(b){
	case '+':j=0;break;
	case '-':j=1;break;
	case '*':j=2;break;
	case '/':j=3;break;
	case '(':j=4;break;
	case ')':j=5;break;
	case '#':j=6;break;
	}
	return GXB[i][j];
}
//GetTOP返回栈顶元素
int GetTop(LinkStack &L){
	return L->n;
}
///////////////////////////////////////////////
int GetNext(int &n){
	char c;
	n=0;
	while((c=getchar())==' ');
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'||c=='#')
	{	n=c;
	return 1;}
	while(c>='0'&&c<='9'){
		n=n*10+c-'0';
		c=getchar();
	}
	ungetc(c,stdin);   
	return 0;	
}
/////////////输出/////////////////#
void OutPutOPND(LinkStack &L){
	LinkStack q;
	q=L;
	if(!q) cout<<"空！"<<endl;

	while(q){
		cout<<q->n<<"　";
		q=q->next;
	}
	cout<<endl;
}
void OutPutOPTR(LinkStack &L){
	LinkStack q;
	q=L;
	if(!q) cout<<"空！"<<endl;

	while(q){
		cout<<char(q->n)<<"　";
		q=q->next;
	}
	cout<<endl;
}
float Operator(int a,char c,int b){
     float result;
	 switch(c){
	 case '+':result=a+b;break;
	 case '-':result=a-b;break;
	 case '*':result=a*b;break;
	 case '/':result=a/b;break;
	 }
	 return result;
}
int Value(){
	int c,flag,a,b;
	char x,e;
	Init(OPND);
	Init(OPTR);
	Push(OPTR,'#');
	flag=GetNext(c);
	x=GetTop(OPTR);
	while(c!='#'||x!='#'){
		if(flag==0){
			Push(OPND,c);
			flag=GetNext(c);
		}
		else{
			x=GetTop(OPTR);
			switch(Precede(x,c)){
			case '<':Push(OPTR,c);flag=GetNext(c);break;
			case '>':e=Pop(OPTR);b=Pop(OPND);a=Pop(OPND);Push(OPND,Operator(a,e,b));break;
			case '=':Pop(OPTR);flag=GetNext(c);break;
			}
		}
	x=GetTop(OPTR);
	}
	int result=GetTop(OPND);
		return result;
}

///////////////////////////////////
//主函数
void main(void){

int	v=Value();
cout<<v<<endl;
OutPutOPND(OPND);
	OutPutOPTR(OPTR);

//1+(23+(3*9+6)/2-4)*96/6#        561
}


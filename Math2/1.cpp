#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class AMGraph{
private:
int row;
int list;
int vnum;//顶点数;
int bnum;//边数
string **V;//顶点信息表
int **data;//矩阵数组   大小new出来的
public:
void InitAMG(int v,int b);//初始化
int Locate(string v);
void InputAMG();//图的输入
void JudgeZf();//自反检测
void JudgeDc();//对称检测
void JudgeCd();//传递检测
void ConnectInit();//二元初始化
AMGraph Connect(AMGraph M);//二元关系建立连接
void Show();///矩阵输出
AMGraph MatriU(AMGraph x);//矩阵并
void ConnectContinue(AMGraph x,AMGraph y);//继续输入矩阵关系；
AMGraph MatriN(AMGraph x);//求矩阵的交
AMGraph AMGraph::MatriB();
AMGraph AMGraph::MatriC(AMGraph x);
};
//*********************************************************************************
void AMGraph::InitAMG(int v,int b){
vnum=v;
bnum=b;
data=new int *[vnum];
for(int i=0;i<vnum;i++)
data[i]=new int [vnum];
V=new string *[vnum];
for(i=0;i<vnum;i++)
V[i]=new string[1];//每个顶点当前设置为只有一个信息；
//既 V[i][0]保存顶点信息
for(i=0;i<vnum;i++)
for(int j=0;j<vnum;j++)
data[i][j]=0;
this->row=this->list=this->vnum;
}
//****************************************************************************
int AMGraph::Locate(string v){
for(int X=0;X<this->vnum;X++){
if(v==(this->V[X][0])) break; 
}
   return X;
   if(X>=this->vnum){
	   cout<<"data not found!"<<endl;
	   exit(1);
   }
}
//****************************************************************************
void AMGraph::InputAMG(){
string v1,v2;
int a,b;
cout<<"请输入顶点数：";
cin>>vnum;
cout<<"请输入边数:";
cin>>bnum;
this->row=this->list=this->vnum;
cout<<"请输入各个顶点：";
for(int i=0;i<vnum;i++)
cin>>V[i][0];
cout<<"请输入各条边的两个端点(二元关系)"<<endl;
for(i=0;i<bnum;i++){
cin>>v1>>v2;
a=Locate(v1);  //在顶点信息表找到输入的v1的位置
b=Locate(v2);	//找到输入的v2的位置
data[a][b]=1;   //例如 A B C 位置为0 1 2 输入关系 A B 则找到【0】【1】赋值为1,表示存在关系
}
}
//****************************************************************************
void AMGraph::JudgeZf(){//或者返回bool类型    return b;
bool a=false;
for(int i=0;i<vnum;i++){
if(data[i][i]==1)  a=true;
else {a=false;break;}
}
if(a)
cout<<endl<<"自反"<<endl;
else
cout<<"非自反"<<endl;
}
//****************************************************************************
void AMGraph::JudgeDc(){//或者返回bool类型    return b;
bool b=false;
for(int i=0;i<vnum;i++){
for(int j=0;j<vnum;j++){
if (data[i][j]==data[j][i])
b=true;
if(data[i][j]!=data[j][i])
{b=false;break;}
}
//	if(b)
//		cout<<"对称"<<endl;
if(!b)
cout<<"非对称"<<endl;
break;//跳出for(int i=0;i<vnum;i++)
}
if(b)
cout<<"对称"<<endl;
}
//****************************************************************************
void AMGraph::JudgeCd(){    //或者返回bool类型    return b;
bool b=false;
for(int i=0;i<vnum;i++){
for(int j=0;j<vnum;j++){
for(int k=0;k<vnum;k++){
if(data[i][j]*data[j][k]==data[i][k])
b=true;
if(data[i][j]*data[j][k]!=data[i][k])
{b=false;break;}
}
if(!b)
cout<<"非传递"<<endl;
break;
}
if(!b)
break;
}
if(b)
cout<<"传递"<<endl;
}
//****************************************************************************
AMGraph AMGraph::Connect(AMGraph M){//二元
	string v1,v2;//输入关系的传参数
	int a,b;//用来保存在集合的下标
	int n;//输入的关系对数
	AMGraph temp;//返回的对象
	temp.row=this->vnum;//集合1为x个元素，集合2为y个，则关系矩阵大小为x*y
	temp.list=M.vnum;//
	temp.data=new int *[temp.row];
	for(int i=0;i<temp.row;i++)
		temp.data[i]=new int [temp.list];
	for(i=0;i<temp.row;i++)
	for(int j=0;j<temp.list;j++)
		temp.data[i][j]=0;
		/* 初始化空间 */
	cout<<"请输入关系个数：";
	cin>>n;
	cout<<"请输入关系:"<<endl;
	for(i=0;i<n;i++){
	cin>>v1>>v2;
	a=Locate(v1); 
	b=M.Locate(v2); 
	temp.data[a][b]=1;
	}
	return temp;
}
//****************************************************************************
void AMGraph::ConnectInit(){

	cout<<"请输入顶点数：";
	cin>>this->vnum;
	this->V=new string *[this->vnum];
	for(int i=0;i<this->vnum;i++)
		V[i]=new string [1];
	cout<<"请输入顶点信息：";
	for(i=0;i<this->vnum;i++)
		cin>>this->V[i][0];
	this->data=NULL;
	this->row=this->list=this->bnum=0;
}
//****************************************************************************
void AMGraph::ConnectContinue(AMGraph x,AMGraph y){
	int n;
	string v1,v2;
	int a,b;
	cout<<"请继续输入要建立的关系对数:";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v1>>v2;
		a=x.Locate(v1);
		b=y.Locate(v2);
		this->data[a][b]=1;
	}
}

//****************************************************************************
void AMGraph::Show(){
		cout<<"---------------------------"<<endl;
	for(int i=0;i<this->row;i++){
		for(int j=0;j<this->list;j++)
			cout<<setw(3)<<setiosflags(ios::right)<<this->data[i][j]<<" ";
		cout<<endl;
	}
			cout<<"---------------------------"<<endl;
}
//****************************************************************************
AMGraph AMGraph::MatriU(AMGraph x){//求矩阵并
	AMGraph result;
	if(x.row!=row||x.list!=list){//判断两个矩阵是否满足并的条件；
		cout<<"矩阵不符合要求"<<endl;
        exit(1);
	}
	result.row=x.row;
	result.list=x.list;
	result.data=new int *[x.row];
	for(int i=0;i<x.row;i++)
			result.data[i]=new int [this->list];
		for(i=0;i<x.row;i++)
		for(int j=0;j<x.list;j++)
			 result.data[i][j]=0;
	for(i=0;i<x.row;i++)
		for(int j=0;j<x.list;j++){
			if((x.data[i][j])+(data[i][j])>=1)
				result.data[i][j]=1;
		}
	cout<<endl;
	return result;
}
//****************************************************************************
AMGraph AMGraph::MatriN(AMGraph x){//求矩阵交
	AMGraph result;
	if(x.row!=row||x.list!=list){//判断两个矩阵是否满足并的条件；
		cout<<"矩阵不符合要求"<<endl;
        exit(1);
	}
	result.row=x.row;
	result.list=x.list;
	result.data=new int *[x.row];
	for(int i=0;i<x.row;i++)
			result.data[i]=new int [this->list];
		for(i=0;i<x.row;i++)
		for(int j=0;j<x.list;j++)
			 result.data[i][j]=0;
	for(i=0;i<x.row;i++)
		for(int j=0;j<x.list;j++){
			if((x.data[i][j])*(data[i][j])==1)
				result.data[i][j]=1;
		}
	cout<<endl;
	return result;
}
//****************************************************************************
AMGraph AMGraph::MatriB(){//求矩阵补
	AMGraph result;
	result.row=row;
	result.list=list;
	result.data=new int *[row];
	for(int i=0;i<row;i++)
			result.data[i]=new int [list];
		for(i=0;i<row;i++)
		for(int j=0;j<list;j++)
			 result.data[i][j]=0;
	for(i=0;i<row;i++)
		for(int j=0;j<list;j++){
			if(data[i][j]==0)
				result.data[i][j]=1;
		}
	cout<<endl;
	return result;
}
//****************************************************************************
AMGraph AMGraph::MatriC(AMGraph x){//求矩阵差
	AMGraph result;
	if(x.row!=row||x.list!=list){//判断两个矩阵是否满足并的条件；
		cout<<"矩阵不符合要求"<<endl;
        exit(1);
	}
	result.row=x.row;
	result.list=x.list;
	result.data=new int *[x.row];
	for(int i=0;i<x.row;i++)
			result.data[i]=new int [this->list];
		for(i=0;i<x.row;i++)
		for(int j=0;j<x.list;j++)
			 result.data[i][j]=0;
	for(i=0;i<x.row;i++)
		for(int j=0;j<x.list;j++){
			if((data[i][j])>=(x.data[i][j]))
				result.data[i][j]=(data[i][j])-(x.data[i][j]);
			if((data[i][j])<(x.data[i][j])){
				cout<<"该矩阵作差时，被减矩阵不存在减矩阵的元素";
			exit(1);}
		}
	cout<<endl;
	return result;
}
//****************************************************************************
int main(){
AMGraph G,G1;
AMGraph M,M1;
AMGraph temp;
/************************
G.InitAMG(3,3);
G.InputAMG();
G.Show();
G.JudgeZf();//判断自反
G.JudgeDc();//判断对称
G.JudgeCd();//判断传递
*//////////////////////

G.ConnectInit();
M.ConnectInit();
temp=G.Connect(M);// 建立关系
temp.Show();//输出关系矩阵


AMGraph temp1=G.Connect(M);
temp1.Show();//输出关系矩阵


//temp.ConnectContinue(M,G);//继续加入关系对

cout<<"矩阵求补"<<endl;
AMGraph tempB=temp.MatriB();//对加入关系后的矩阵求补矩阵
tempB.Show();//输出补矩阵

cout<<"矩阵求差"<<endl;
AMGraph tempC=temp.MatriC(temp1);
tempC.Show();

cout<<"矩阵求并"<<endl;
AMGraph tempU=temp.MatriU(temp1);
tempU.Show();

cout<<"矩阵求交"<<endl;
AMGraph tempN=temp.MatriN(temp1);
tempN.Show();
system("pause");
return 0;
}


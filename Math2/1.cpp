#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class AMGraph{
private:
int row;
int list;
int vnum;//������;
int bnum;//����
string **V;//������Ϣ��
int **data;//��������   ��Сnew������
public:
void InitAMG(int v,int b);//��ʼ��
int Locate(string v);
void InputAMG();//ͼ������
void JudgeZf();//�Է����
void JudgeDc();//�ԳƼ��
void JudgeCd();//���ݼ��
void ConnectInit();//��Ԫ��ʼ��
AMGraph Connect(AMGraph M);//��Ԫ��ϵ��������
void Show();///�������
AMGraph MatriU(AMGraph x);//����
void ConnectContinue(AMGraph x,AMGraph y);//������������ϵ��
AMGraph MatriN(AMGraph x);//�����Ľ�
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
V[i]=new string[1];//ÿ�����㵱ǰ����Ϊֻ��һ����Ϣ��
//�� V[i][0]���涥����Ϣ
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
cout<<"�����붥������";
cin>>vnum;
cout<<"���������:";
cin>>bnum;
this->row=this->list=this->vnum;
cout<<"������������㣺";
for(int i=0;i<vnum;i++)
cin>>V[i][0];
cout<<"����������ߵ������˵�(��Ԫ��ϵ)"<<endl;
for(i=0;i<bnum;i++){
cin>>v1>>v2;
a=Locate(v1);  //�ڶ�����Ϣ���ҵ������v1��λ��
b=Locate(v2);	//�ҵ������v2��λ��
data[a][b]=1;   //���� A B C λ��Ϊ0 1 2 �����ϵ A B ���ҵ���0����1����ֵΪ1,��ʾ���ڹ�ϵ
}
}
//****************************************************************************
void AMGraph::JudgeZf(){//���߷���bool����    return b;
bool a=false;
for(int i=0;i<vnum;i++){
if(data[i][i]==1)  a=true;
else {a=false;break;}
}
if(a)
cout<<endl<<"�Է�"<<endl;
else
cout<<"���Է�"<<endl;
}
//****************************************************************************
void AMGraph::JudgeDc(){//���߷���bool����    return b;
bool b=false;
for(int i=0;i<vnum;i++){
for(int j=0;j<vnum;j++){
if (data[i][j]==data[j][i])
b=true;
if(data[i][j]!=data[j][i])
{b=false;break;}
}
//	if(b)
//		cout<<"�Գ�"<<endl;
if(!b)
cout<<"�ǶԳ�"<<endl;
break;//����for(int i=0;i<vnum;i++)
}
if(b)
cout<<"�Գ�"<<endl;
}
//****************************************************************************
void AMGraph::JudgeCd(){    //���߷���bool����    return b;
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
cout<<"�Ǵ���"<<endl;
break;
}
if(!b)
break;
}
if(b)
cout<<"����"<<endl;
}
//****************************************************************************
AMGraph AMGraph::Connect(AMGraph M){//��Ԫ
	string v1,v2;//�����ϵ�Ĵ�����
	int a,b;//���������ڼ��ϵ��±�
	int n;//����Ĺ�ϵ����
	AMGraph temp;//���صĶ���
	temp.row=this->vnum;//����1Ϊx��Ԫ�أ�����2Ϊy�������ϵ�����СΪx*y
	temp.list=M.vnum;//
	temp.data=new int *[temp.row];
	for(int i=0;i<temp.row;i++)
		temp.data[i]=new int [temp.list];
	for(i=0;i<temp.row;i++)
	for(int j=0;j<temp.list;j++)
		temp.data[i][j]=0;
		/* ��ʼ���ռ� */
	cout<<"�������ϵ������";
	cin>>n;
	cout<<"�������ϵ:"<<endl;
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

	cout<<"�����붥������";
	cin>>this->vnum;
	this->V=new string *[this->vnum];
	for(int i=0;i<this->vnum;i++)
		V[i]=new string [1];
	cout<<"�����붥����Ϣ��";
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
	cout<<"���������Ҫ�����Ĺ�ϵ����:";
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
AMGraph AMGraph::MatriU(AMGraph x){//�����
	AMGraph result;
	if(x.row!=row||x.list!=list){//�ж����������Ƿ����㲢��������
		cout<<"���󲻷���Ҫ��"<<endl;
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
AMGraph AMGraph::MatriN(AMGraph x){//�����
	AMGraph result;
	if(x.row!=row||x.list!=list){//�ж����������Ƿ����㲢��������
		cout<<"���󲻷���Ҫ��"<<endl;
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
AMGraph AMGraph::MatriB(){//�����
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
AMGraph AMGraph::MatriC(AMGraph x){//������
	AMGraph result;
	if(x.row!=row||x.list!=list){//�ж����������Ƿ����㲢��������
		cout<<"���󲻷���Ҫ��"<<endl;
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
				cout<<"�þ�������ʱ���������󲻴��ڼ������Ԫ��";
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
G.JudgeZf();//�ж��Է�
G.JudgeDc();//�ж϶Գ�
G.JudgeCd();//�жϴ���
*//////////////////////

G.ConnectInit();
M.ConnectInit();
temp=G.Connect(M);// ������ϵ
temp.Show();//�����ϵ����


AMGraph temp1=G.Connect(M);
temp1.Show();//�����ϵ����


//temp.ConnectContinue(M,G);//���������ϵ��

cout<<"������"<<endl;
AMGraph tempB=temp.MatriB();//�Լ����ϵ��ľ����󲹾���
tempB.Show();//���������

cout<<"�������"<<endl;
AMGraph tempC=temp.MatriC(temp1);
tempC.Show();

cout<<"������"<<endl;
AMGraph tempU=temp.MatriU(temp1);
tempU.Show();

cout<<"������"<<endl;
AMGraph tempN=temp.MatriN(temp1);
tempN.Show();
system("pause");
return 0;
}


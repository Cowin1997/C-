#include <iostream>
#include <string>
#include <iomanip>
//#include "Matrix.h"
using namespace std;
class AMGraph{
private:
int row;//���������
int list;//���������
int vnum;//������;
int bnum;//����
string **V;//������Ϣ��
int **data;//��������   ��Сnew������
public:
void InitAMG(int v,int b);//��ʼ��ͼ��a,bΪ������������
int Locate(string v);//ȷ���±�
void InputAMG();//ͼ������
void JudgeZf();//�Է����
void JudgeDc();//�ԳƼ��
void JudgeCd();//���ݼ��
void ConnectInit();//��Ԫ��ʼ��
AMGraph Connect(AMGraph M);//��Ԫ��ϵ��������
void Show();///�������
AMGraph MatriU(AMGraph x);//������
void ConnectContinue(AMGraph x,AMGraph y);//������������ϵ��
AMGraph MatriN(AMGraph x);//�����Ľ�
AMGraph AMGraph::MatriB();//������
AMGraph AMGraph::MatriC(AMGraph x);//�������
AMGraph AMGraph::MatriNi(); //��������
bool JudgeMatriEqual(AMGraph X);
AMGraph rRZf(AMGraph G); //���Է��հ�
AMGraph sRDc();//��ԳƱհ�
AMGraph Matricx(AMGraph x);//�����ĳ˷�
};
//*********************************************************************************
void AMGraph::InitAMG(int v,int b){//��ʼ��ͼ��a,bΪ������������
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
int AMGraph::Locate(string v){//ȷ���±�
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
void AMGraph::InputAMG(){//ͼ������
string v1,v2;
int a,b;
this->row=this->list=this->vnum;
cout<<"������������㣺";
for(int i=0;i<vnum;i++)
cin>>V[i][0];
cout<<"����������ߵ������˵�(��Ԫ��ϵ)"<<endl;
for(i=0;i<bnum;i++){
cin>>v1>>v2;
a=Locate(v1);  //�ڶ�����Ϣ���ҵ������v1��λ��
b=Locate(v2);	//�ҵ������v2��λ��
//data[a][b]=1;   //���� A B C λ��Ϊ0 1 2 �����ϵ A B ���ҵ���0����1����ֵΪ1,��ʾ���ڹ�ϵ
data[a][b]++;////�����ڽӾ���ֻ��Ҫ������һ��  ps:����һ��ע�͵���
}
}
//****************************************************************************
void AMGraph::JudgeZf(){//���߷���bool����    return b; //�Է����
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
void AMGraph::JudgeDc(){//���߷���bool����    return b;//�ԳƼ��
bool b=false;
for(int i=0;i<row;i++){
for(int j=0;j<list;j++){
if (data[i][j]==data[j][i])
b=true;
if(data[i][j]!=data[j][i])
{b=false;break;}
}
//	if(b)
//		cout<<"�Գ�"<<endl;
if(!b){
cout<<"�ǶԳ�"<<endl;
break;
}//����for(int i=0;i<vnum;i++)
}
if(b)
cout<<"�Գ�"<<endl;
}
//****************************************************************************
void AMGraph::JudgeCd(){ //���ݼ��   //���߷���bool����    return b;
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
AMGraph AMGraph::Connect(AMGraph M){//��Ԫ��ϵ��������
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
void AMGraph::ConnectInit(){//��Ԫ��ʼ��

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
void AMGraph::ConnectContinue(AMGraph x,AMGraph y){//������������ϵ��
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
void AMGraph::Show(){//���������
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
AMGraph AMGraph::MatriNi(){ //��������
	AMGraph result;
	result.row=list;
	result.list=row;
	result.data=new int *[result.row];
	for(int i=0;i<result.row;i++)
		result.data[i]=new int [result.list];
	for(i=0;i<row;i++)
		for(int j=0;j<list;j++)
			result.data[i][j]=this->data[j][i];
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
bool AMGraph::JudgeMatriEqual(AMGraph X){ //�жϾ����Ƿ����
	int i,j;
	if(X.row!=row||X.list!=list)
		return false;
	if(X.row==row&&X.list==list){
		for( i=0;i<row;i++)
			for(j=0;j<list;j++){
				if(X.data[i][j]!=data[i][j]) return false;
			}
			if(i==X.row&&j==list)
				return true;
	}
	
}
//****************************************************************************
AMGraph AMGraph::rRZf(AMGraph G){ //���Է��հ�
	AMGraph result;
	/* �������� */
	result.row=G.row;
	result.list=G.list;
	result.vnum=G.vnum;
	result.data=new int *[G.row];
	/* ������� */
	for(int i=0;i<G.row;i++)
		result.data[i]=new int [G.list];
	for(i=0;i<G.row;i++){
		for(int j=0;j<G.list;j++)
			result.data[i][j]=G.data[i][j];
	} //�����ڴ�
	for(i=0;i<G.row;i++)
		result.data[i][i]=1;  //���Խ��߱�1����������
	return result; //���ض���
}
//****************************************************************************
AMGraph AMGraph::sRDc(){//��ԳƱհ�,���������
	AMGraph MatriNN=this->MatriNi();
	AMGraph result=this->MatriU(MatriNN);
	return result;
}
//****************************************************************************
AMGraph AMGraph::Matricx(AMGraph x){//�����ĳ˷�
	int t=0;;
	int temp=0;
	AMGraph result;
		result.row=x.row;
		result.list=x.list;
		result.data=new int *[result.row];
		for(int i=0;i<result.row;i++)
			result.data[i]=new int [result.list];
		for(i=0;i<result.row;i++)
			 for(int j=0;j<result.list;j++){
				 for(int k=0;k<this->list;k++){
					 t=(this->data[i][k])*(x.data[k][j]);//**
					 temp+=t;
				 }
				 result.data[i][j]=temp;
				 t=temp=0;
			 }
	 return result;
};
//****************************************************************************
int main(){
AMGraph G,G1,t;
/*
AMGraph M,M1;
AMGraph temp;
*/
G.InitAMG(4,4);
G.InputAMG();
cout<<"������ͼ:"<<endl;
G.Show();
/*
cout<<"�ڽӾ���"<<endl;
G.Show();
G1=G;//G1�洢ÿ�ξ����һ�εĽ��
t=G;//tΪ�ɴ��Ծ���
for(int i=1;i<5;i++){
	cout<<"A^"<<i+1<<endl;
	G1=G1.Matricx(G);
	G1.Show();
	t=t.MatriU(G1);
}
cout<<"�ɴ��Ծ���Ϊ��"<<endl;
t.Show();//����ɴ��Ծ���


v1 v2 v3 v4 v5

v1 v1
v2 v1
v2 v1
v2 v3
v3 v2
v4 v5
v5 v4

 */


G1=G.rRZf(G);
cout<<"��õ��Է��հ������ǣ�"<<endl;
G1.Show();

if(G.JudgeMatriEqual(G1))
cout<<"ͨ���Է��հ��ж����Է���"<<endl;
else
cout<<"ͨ���Է��հ��жϲ����Է���"<<endl;

AMGraph G11=G.sRDc();

G11.Show();
if(G.JudgeMatriEqual(G11))
cout<<"ͨ���ԳƱհ��ж��ǶԳƵ�"<<endl;
else
cout<<"ͨ���ԳƱհ��жϲ��ǶԳƵ�"<<endl;

AMGraph x2=G.Matricx(G);
t=G.MatriU(x2);

cout<<"��1�ξ���*:"<<endl;x2.Show();
for(int i=1;i<=2;i++){
 x2=G.Matricx(x2);
 t=x2.MatriU(t);
cout<<"��"<<i+1<<"�ξ���*:"<<endl;
x2.Show();
}
cout<<"��õĴ��ݱհ������ǣ�"<<endl;
t.Show();
if(G.JudgeMatriEqual(x2))
cout<<"ͨ�����ݱհ��ж��Ǵ��ݵ�"<<endl;
else
cout<<"ͨ�����ݱհ��жϲ��Ǵ��ݵ�"<<endl;
G.JudgeZf();//�ж��Է�
G.JudgeDc();//�ж϶Գ�
G.JudgeCd();//�жϴ���

/*
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
*/
system("pause");
return 0;
}


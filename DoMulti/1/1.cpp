#include <iostream>
#include <iomanip>
using namespace std;
typedef int elemtype;
class Matri {
private:
	elemtype **data;
	int MRow;
	int MList;
	bool Check(Matri X);//检测两个矩阵是否可以相乘
public:
	void InitMatri();
	void InputMatri();
	void ShowMatri();
	Matri Matrimulti(Matri X);
};
//初始化置0
void Matri::InitMatri(){
	cout<<"请输入行数：";
	cin>>MRow;
	cout<<"请输入列数:";
	cin>>MList;
		data= new elemtype *[MRow];
		for(int i=0;i<MRow;i++){
			data[i]=new elemtype[MList];     
		for(int j=0;j<MList;j++)
			data[i][j]=0;
		}
}
//输入
void Matri::InputMatri(){
	cout<<"请输入一个"<<MRow<<"*"<<MList<<"的矩阵:"<<endl;
	for(int i=0;i<MRow;i++)
		for(int j=0;j<MList;j++)
			cin>>data[i][j];
	cout<<"矩阵输入完毕"<<endl;
}
//输出
void Matri::ShowMatri(){
	cout<<"输出矩阵为："<<endl;
	for(int i=0;i<MRow;i++){
		for(int j=0;j<MList;j++)
			cout<<setw(4)<<setiosflags(ios::right)<<data[i][j];
		cout<<endl;
	}
}
//矩阵乘法
Matri Matri::Matrimulti(Matri X){
	 Matri result;
	 elemtype t=0;
	 elemtype temp=0;
	 if(!this->Check(X)){
		 cout<<"错误，不符合条件，请检查是否正确！"<<endl;;
		exit(1);
	 }
	 else{
		 result.MRow=this->MRow;
		 result.MList=X.MList;
		 result.data= new elemtype *[result.MRow];
		for(int i=0;i<result.MRow;i++){
			result.data[i]=new elemtype[result.MList];     
		for(int j=0;j<result.MList;j++)
			result.data[i][j]=0;
		}
		 for(i=0;i<result.MRow;i++)
			 for(int j=0;j<result.MList;j++){
				 for(int k=0;k<this->MList;k++){
					 t=(this->data[i][k])*(X.data[k][j]);//**
					 temp+=t;
				 }
				 result.data[i][j]=temp;
				 t=temp=0;
			 }
	 }
	 return result;
};


bool Matri::Check(Matri X){
	 if(this->MList==X.MRow)
	 return true;
	 else return false;
}
int main(){
	Matri M;
	Matri X;
	Matri result;
	M.InitMatri();
	M.InputMatri();
	M.ShowMatri();
	X.InitMatri();
	X.InputMatri();
	X.ShowMatri();
	result=M.Matrimulti(X);
	result.ShowMatri();
	return 0;
}
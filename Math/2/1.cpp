#include <iostream>
#include <string>
using namespace std;
class AMGraph{
private:
    int vnum;//顶点数;
	int bnum;//边数
	string **V;//顶点信息表
	int **data;//矩阵数组   大小new出来的
public:	
	void InitAMG(int v,int b);//初始化
	int Locate(string v);
	void InputAMG();//图的输入
	void ShowAMG();//矩阵输出
	void JudgeZf();//自反检测
	void JudgeDc();//对称检测
	void JudgeCd();//传递检测
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
	}
//*********************************************************************************
int AMGraph::Locate(string v){
	for(int i=0;i<vnum;i++){
		if(v==V[i][0])  break;	
	}
	return i;
	if(i==vnum)    {
		cout<<"Error! Locate not found!"<<endl;
		return -1;
	}
		
}
//*********************************************************************************
void AMGraph::InputAMG(){
	string v1,v2;
	int a,b;
	cout<<"请输入顶点数：";
	cin>>vnum;
	cout<<"请输入边数:";
	cin>>bnum;
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
//********************************************************************************
void AMGraph::ShowAMG(){
	for(int i=0;i<vnum;i++){
		for(int j=0;j<vnum;j++)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}
}
//********************************************************************************
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
//********************************************************************************
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
//********************************************************************************
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
//********************************************************************************

int main(){
	AMGraph G;
	G.InitAMG(6,14);
	G.InputAMG();
	G.ShowAMG();
	G.JudgeZf();
	G.JudgeDc();
	G.JudgeCd();
	return 0;
}
/*
请输入顶点数：6
请输入边数:14
请输入各个顶点：1 2 3 4 5 6
请输入各条边的两个端点
1 1
2 2
3 3
4 4
5 5
6 6
1 2
1 4
1 5
2 5
3 2
3 6
3 5
4 5
1 1 0 1 1 0
0 1 0 0 1 0
0 1 1 0 1 1
0 0 0 1 1 0
0 0 0 0 1 0
0 0 0 0 0 1
*/

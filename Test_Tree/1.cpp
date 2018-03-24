//二叉树
#include <iostream>
using namespace std;
typedef int TElemtype;
typedef struct BitNode{
	TElemtype data;
	struct BitNode *lchild,*rchild;
}*BitTree;
	//构造空二叉树

void InitTree(BitTree &T){
	T=NULL;
}

	//
void CreatBitTree(BitTree &T,TElemtype n){
	BitTree t;
	t=new BitNode;
    T->lchild=t;



	
}



void main(){
}

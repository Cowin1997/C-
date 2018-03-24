#include <iostream>
#include <fstream>
using namespace std;
#define OK 1
#define ERROR 0
typedef char **HC;
typedef struct HfNode{
	char c;
	int weight;
	int parent;
	int lchild;
	int rchild;
}Hnode,*Ht;
//*******************************Select函数********************************//
void select(Ht &H,int s,int &x1,int &x2){  
    int v1,v2;  
    v1=v2=99999;  
    x1=x2=0;  
    for(int i=1;i<=s;i++)  
    {  
        if (H[i].parent==0)  
        {  
            if(H[i].weight<v1)  
            {  
                v2=v1;  
                x2=x1;  
                v1=H[i].weight;  
                x1=i;  
            }  
           else if(H[i].weight<v2)
            {  
                x2=i;  
                v2=H[i].weight;  
            }  
        }  
    }  
} 
//*******************************保存函数********************************//
void hfmtree_txt(Ht &H,int n){

	ofstream outfile("hfmTree.txt",ios::out);
    outfile<<n;
  	for(int i=1;i<=n;i++)
	   outfile<<H[i].c;
  	for(i=1;i<=n;i++)
		outfile<<" "<<H[i].weight<<" ";
	outfile<<endl;
	 outfile.close();
}
//*******************************初始化函数********************************//
int InitHnode(Ht &H,int n){  //n为叶子的个数
	int s1,s2;
	char c;
	int m=2*n-1;
//	ofstream outfile("hfmTree.txt",ios::out);
//  outfile<<n;
	if(n<1) return ERROR;
	H=new Hnode[m+1];
	for(int i=1;i<=m;i++)
		H[i].lchild=H[i].rchild=H[i].parent=0;
	cout<<"请输入"<<n<<"个字符："<<endl;
	c=getchar();
		for(i=1;i<=n;i++){
		//	outfile<<c;
			H[i].c=c;
			c=getchar();
		}
    cout<<"请输入"<<n<<"个字符的权重："<<endl;
		for(i=1;i<=n;i++){
			cin>>H[i].weight;
		//	outfile<<" "<<H[i].weight<<" ";
		}
	// outfile.close();
	for(i=n+1;i<=m;i++){
		select(H,i-1,s1,s2);
		H[s1].parent=H[s2].parent=i;
		H[i].lchild=s2;
		H[i].rchild=s1;
		H[i].weight=H[s1].weight+H[s2].weight;
	}
	hfmtree_txt(H,n);
	return OK;
}
//*******************************输出函数********************************//
void out(Ht &H,int n){
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<H[i].c<<":"<<H[i].weight<<"  "<<H[i].parent<<"  "<<H[i].lchild<<"  "<<H[i].rchild<<endl;
	for(i;i<=2*n-1;i++)
			cout<<" "<<":"<<H[i].weight<<"  "<<H[i].parent<<"  "<<H[i].lchild<<"  "<<H[i].rchild<<endl;
}

//*******************************读取函数********************************//
void read_hfmtree_txt(Ht &H,int &n){
	int m;
	char ch;
	int w,s1,s2;
	ifstream infile("hfmTree.txt",ios::in);
	if(!infile){
		cout<<"open error";
    	return;
	}
    infile>>m;
	n=m;
//	cout<<m;
	char *c_har=new char[n];
	int  *i_nt=new int [n];
	H=H=new Hnode[2*n+1];
	for(int i=1;i<=n;i++){
		infile.get(ch);
		c_har[i]=ch;
	//	cout<<c_har[i];
		H[i].c=c_har[i];
	}
	cout<<endl;
	for(i=1;i<=n;i++){
		infile>>w;
		i_nt[i]=w;
	//	cout<<i_nt[i]<<" ";
		H[i].weight=i_nt[i];
	} 
	for(i=1;i<=2*n-1;i++)
		H[i].lchild=H[i].rchild=H[i].parent=0;
	for(i=n+1;i<=2*n-1;i++){
		select(H,i-1,s1,s2);
		H[s1].parent=H[s2].parent=i;
		H[i].lchild=s2;
		H[i].rchild=s1;
		H[i].weight=H[s1].weight+H[s2].weight;
	}
	if(H)
		cout<<"hfmtree.txt加载成功！"<<endl;
	infile.close();
}

//*******************************赫夫曼编码********************************//

void CreatHuffmanCode(Ht H,HC &HC,int n){
	int start,c,f;
	char *cd;
	HC=new char *[n+1];
	cd=new char [n];
	cd[n-1]='\0';
	for(int i=1;i<=n;i++){
		start=n-1;
		c=i;f=H[i].parent;
		while(f!=0){
			--start;
			if(H[f].lchild==c)  cd[start]='0';
			else cd[start]='1';
			c=f;f=H[f].parent;
		}
		HC[i]=new char [n-start];
		strcpy(HC[i],&cd[start]);
	}
	delete cd;
}
//*******************************编码函数********************************//
void  Encoding( Ht &H,HC &HC,int &n){
	/*int e=0;
	ofstream outfilen("hfmTree.txt",ios::out);
    outfilen<<e;
	n=e;
	outfilen.close();
	*/
    char ch;
	if(HC==NULL&&H==NULL)
	read_hfmtree_txt(H,n);
	CreatHuffmanCode(H,HC,n);
	ofstream outfile("CodeFile.txt",ios::out);
	ifstream infile("ToBeTran.txt",ios::in);
	if(!infile){
		cout<<"open error,maybe file is not exit";
    	return;
	}
    cout<<"从文件CodeFile.txt读入的是："<<endl;
	while(infile.get(ch)){
		for(int i=1;i<=n;++i)  
			if(H[i].c==ch){
				cout<<ch;
				//cout<<HC[i]<<endl;
				outfile<<HC[i];
				break;  }	
}
	cout<<endl;
outfile.close();
infile.close();	
}
//*******************************译码********************************//
void yima( Ht &H,HC &HC,int &n){
/*	int e=0;
	ofstream outfile("hfmTree.txt",ios::out);
    outfile<<e;
	n=e;
	outfile.close();
	*/
   char ch;
   int i=2*n-1;
   	ifstream infile("CodeFile.txt",ios::in);
	cout<<"编译出来的是:"<<endl;
   infile.get(ch);
	while(!infile.eof()){
		if(ch=='0'&&H[i].lchild!=0){
			i=H[i].lchild;
           infile.get(ch);
		}
			if(ch=='1'&&H[i].rchild!=0){
					i=H[i].rchild;
            infile.get(ch); 
			}
           if(H[i].lchild==0&&H[i].rchild==0)
		   {cout<<H[i].c; i=2*n-1;}
     
	}
   cout<<endl;

}
//*******************************主函数********************************//
int main(){
	char c;
	int N=27;
	HC HC=NULL;
	Ht H=NULL;
    cout<<"\t\t\t*************"<<endl;
    cout<<"\t\t\t初始化请输入I"<<endl;
	cout<<"\t\t\t编码请输入E"<<endl;
	cout<<"\t\t\t译码请输入Y"<<endl;
	cout<<"\t\t\t退出请输入Q"<<endl;
	cout<<"\t\t\t输出赫夫曼树请输入O"<<endl;
	cout<<"\t\t\t*************"<<endl;
    cout<<"请输入操作"<<endl;
	while(cin>>c){
	switch(c){
	case 'i':
	case 'I':cout<<"请输入个数："<<endl;cin>>N;InitHnode(H,N);CreatHuffmanCode(H,HC,N);break;
	case 'e': 
	case 'E':Encoding(H,HC,N);break;
	case 'y':
	case 'Y':if(!H) read_hfmtree_txt(H,N);CreatHuffmanCode(H,HC,N);yima(H,HC,N);break;
	case'o':
	case 'O':if (!H) read_hfmtree_txt(H,N);CreatHuffmanCode(H,HC,N);out(H,N);
	case 'q':
	case 'Q':break;
	}
	if(c=='q'||c=='Q')
		break;
	if(c!='Q'||c!='q')
		cout<<endl<<"请输入下一个操作"<<endl;
	}		
	
	return OK;
}

// ABCDEFGHIJKLMNOPQRSTUVWXYZ
//186 64  13  22  32  103  21  15  47  57  1  5  32  20  57  63  15  1  48  51  80  23  8  18  1  16  1

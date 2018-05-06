#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstring>
#include <cstdio>
#define  N 22
using namespace std;
int gameover=1;
int x,y;
int x1,y1;//随机出米
long start;
char key;

  class snake_position
  {
  public:
	  int x,y;//x:行  y:列
	  void chishihua(int &j);
  };
//***************************************************//
  void snake_position::chishihua(int &j)
  {
	  x=1;
	  y=j;
  }
//**************************************************//
snake_position position[(N-2)*(N-2)+1];//20*20+1=401


  /////////////////////////////////////////////////////
  ////////////////////////////////////////////////////
  class snake_map
  {
  public:
	  void chushihua();//初始化函数
      void show();
	  void setfood();
	  snake_map(int h=4,int t=1,int l=4,char d='D',int s=0):head(h),tail(t),length(l),direction(d),score(s){}
	  void setgrade();
	  int SNAKEHEXIN();
	  void last();

  private:
	  char map[N][N];
	  int grade;
	  int length;
	  int gamespeed;
	  char direction;
	  int head;
	  int tail;
	  int score;
	  bool gameauto;
  };

//////////////////////初始化/////////////////////
  void snake_map::chushihua()
  {
	  int i,j;
	 // for(i=1;i<=3;i++)
	//	  map[1][i]='*';
	//  map[1][4]='#';
	  for(i=1;i<N;i++)     //N-2=20   1-20
		  for(j=1;j<N;j++)
			  map[i][j]=' ';
		  for(i=0;i<=N-1;i++)
			  map[0][i]=map[N-1][i]='-';
		  for(i=1;i<=N-2;i++)
			  map[i][0]=map[i][N-1]='|';
  }
////////////////////////输出//////////////////////
  void snake_map::show()
  {   int i,j;
	  system("cls");
	 // cout<<endl;
	  for(i=0;i<N;i++)
	  {   //cout<<'\t';
		  for(j=0;j<N;j++)
			  cout<<map[i][j]<<' ';
		  if(i==2)  cout<<"\t等级："<<grade;
		  if(i==6)  cout<<"\t速度："<<gamespeed;
		  if(i==10) cout<<"\t得分："<<score;
		  if(i==14) cout << "\t暂停：按一下空格键" ;
          if(i==18) cout << "\t继续：按两下空格键" ;
			cout<<endl;
	  }
  }

//////////////////////产生米///////////////////////////

  void snake_map::setfood()
  {		
	  srand(time(NULL));
	  do
	  { x1=1+rand()%(N-2);
	    y1=1+rand()%(N-2);
	  }
	  while(map[x1][y1]!=' ');
		  map[x1][y1]='*';
  }
/////////////////////设置等级///////////////////////////////////
 

  void snake_map::setgrade()
  {  //cout<<"\t\t\t\tplease set the grade 1-7"<<endl;
     cin>>grade;
	 while(grade>7||grade<1)
	 {
		 cout<<"input error!   please try again! "<<endl;
		 cin>>grade;
	 }
	    switch(grade)
    {
        case 1: gamespeed = 1000;gameauto = 0;break;
		case 2: gamespeed = 800;gameauto = 0;break;
		case 3: gamespeed = 600;gameauto = 0;break;
		case 4: gamespeed = 400;gameauto = 0;break;
		case 5: gamespeed = 200;gameauto = 0;break;
		case 6: gamespeed = 100;gameauto = 0;break;
		case 7: grade = 1;gamespeed = 1000;gameauto = 1;break;
	}

  }

/////////////////////SNAKEHEXIN//////////////////////////////////
  int snake_map::SNAKEHEXIN()
 {
    key=direction;
	start=clock();
	while((gameover=(clock()-start<=gamespeed))&&!kbhit());
    if(gameover)
	{
	   key=getch();
	}
	if(key==' ')
	{
		while(getch()!=' '){}
	}
	else 
		direction=key;
	switch(direction)
	{
	case 'W': x=position[head].x-1;y=position[head].y;break;//  UP
	case 'A': x=position[head].x;y=position[head].y-1;break;// LEFT
	case 'S': x=position[head].x+1;y=position[head].y;break;//DOWN
	case 'D': x=position[head].x;y=position[head].y+1;break;//RIGHT


	}
	//if(getch()!='W'||getch()!='A'||getch()!='S'||getch()!='D')
	//	   ;
		
		if (x==0||x==N-1||y==0||y==N-1)
		gameover=0;
	else if(map[x][y]!=' '&& !(x==x1&&y==y1))
		gameover=0;
	else if(x==x1&&y==y1)
	{
		length++;
		if(length>=8 &&gameauto)
		{
			length-=8;
		    grade++;
			if(gamespeed>=200)
				gamespeed-=200;
			else
				gamespeed=100;
		}
	    map[x][y]='#';
		map[position[head].x][position[head].y]='*';
	    head=(head+1)%((N-2)*(N-2));
		position[head].x=x;
		position[head].y=y;
	    gameover=1;
		score+=20;
		setfood();
	}
	else
	{
		map[position[tail].x][position[tail].y]=' ';//将蛇尾巴置空
		tail=(tail+1)%((N-2)*(N-2));
		map[position[head].x][position[head].y]='*';//将蛇头更新为身
		head=(head+1)%((N-2)*(N-2));
		position[head].x=x;
		position[head].y=y;
		map[position[head].x][position[head].y]='#';
		gameover=1;
	}
	return gameover;
  }

  void snake_map::last()
  {
	  cout<<"\n\n\n\t\t\t游戏结束!"<<endl;
      cout<<"\n\n\n\t\t\t得分"<<score<<endl;
  }

///////////////////////////////
//       主函数             //
//////////////////////////////
  

int main()
{  SetConsoleTitle("贪吃蛇--By ShiZiWanGe");
	char ctn='Y';
    int D;
	cout<<"\n\n\n\n\t\t 欢迎进入贪吃蛇游戏! "<<endl;
    cout<<"\n\n\n\t\t 按任意键开始游戏！"<<endl;
	cout<<"\n\n\t\t-------By LXB---------"<<endl;
	getch();
	while(ctn=='Y')
	{ 
		system("cls");//清屏
		snake_map snake;
        cout << "\n\n请输入数字选择游戏等级：" << endl;
		cout << "\n\n\n\t\t\t1.等级一：速度 1000 \n\n\t\t\t2.等级二：速度 800 \n\n\t\t\t3.等级三：速度 600 ";
		cout << "\n\n\t\t\t4.等级四：速度 400 \n\n\t\t\t5.等级五：速度 200 \n\n\t\t\t6.等级六：速度 100 \n\n\t\t\t7.自动升级模式" << endl;
	for(int i=1;i<=4;i++)
		position[i].chishihua(i);
		snake.chushihua();
		snake.setgrade();
		snake.setfood();
	do
	{
		snake.show();
		D=snake.SNAKEHEXIN();
	}
	while(D);
	system("cls");
	ctn='a';
	snake.last();
cout<<"继续游戏，请输入Y。"<<endl;
cin>>ctn;
	}
  


	return 0;
}
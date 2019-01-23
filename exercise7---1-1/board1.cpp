
#ifndef BOARD_CPP
#define BOARD_CPP

#include"board1.h"


#pragma comment(lib,"Fmodvc.lib")                        //引入Fmod音频播放引擎
#include <conio.h>
#include "Fmod.h"


extern   Fl_GIF_Image *white1_img; 
extern	Fl_GIF_Image *black1_img;
extern	Fl_JPEG_Image *board1_img;
extern	Fl_JPEG_Image *board2_img;
extern	Fl_JPEG_Image *board3_img;
extern void change_picture()   ;
extern game_window *win;



//----------对board类的函数进行定义--------------------------------------------------
board::board(int x1 ,int y1,int x, int y,int n)//初始化board类
	:Fl_Widget (x1,y1,x,y,"")
{
	line_num=n;
	 set_address();
	
};

int board::handle(int e)//捕捉鼠标运动的handle函数
{
	
	
	switch(e)
	{
		case  FL_PUSH://如果鼠标点击了，就开始下棋
			{
				int x=Fl::event_x();
				int y=Fl::event_y();
                cout<<x<<"    "<<y<<endl;
				 if(100<x && x<100+39*(N-1) && 100<y && y<100+39*(N-1))
				 {

				switch (win->mode)//根据所选的Mode选择不同的下棋方式
				{
				case 1:
					{ 
						xiaqi(x,y);
						cout<<"m&m \n";
						break;
					}
				case 2:
					{   
					xiaqi(x,y); 
					cout<<"i call white--ai\n";
					win->redraw();
				     white_ai();    
					 break;
					   }
			    case 3:
					{  
						cout<<"i call black-- ai\n";   
						xiaqi(x,y); 
						win->redraw();
						black_ai();  
						 break;
					}
				}


	       }	
		   check_white_win();
		   check_black_win();
			break;
			}
		
		case FL_MOVE:{  //若棋子移动，则画出红色小方框标记
			     
					 int x=Fl::event_x();
				     int y=Fl::event_y();
					 if(100<x && x<100+39*(N-1) && 100<y && y<100+39*(N-1))
					 shadow(x,y);
					 break;
					 }
      default:
		 break;        
	}
	return 1;
}

//--------------------------------------------------------------------------------



void board::draw()//画出棋盘线
{
	
	int i = 0;
	while(i<line_num)
	{
		fl_color(FL_BLACK);
		fl_line(100,39*i+100,100+39*(N-1),39*i+100);
		fl_line(100+39*i,100,100+39*i,100+39*(N-1));
		i++;
	}
}


void board::  xiaqi(int x,int y)//定义下棋函数
{      
	    int tempx=(x-81)/39;//棋盘上的坐标为tempx与tempy
		int tempy=(y-81)/39;
		cout<<tempx<<"  and   "<<tempy<<endl;
		if(win->qipan[tempx][tempy]!=0|| win->someone_win==1)//若已经分出胜负或者棋盘上已经有人下过子则不能落子
		{   cout<<"wrong\n";
			return ;
		}


		if(!(win->step%2) )  //若为奇数步，则为黑方执子
		{
			cout<<"black\n";
		
			
		win->board_address[tempx][tempy]->image(*black1_img);
		win->board_address[tempx][tempy]->show();
		win->redraw();
		win->qipan[tempx][tempy]=1;
		win->xsequence.push_back(tempx);
		win->ysequence.push_back(tempy);
		win->step++;//步数++
		return  ;
		}
		else
		{   
			//若为偶数步，则为白方执子
        cout<<"white\n";
		win->qipan[tempx][tempy]=2;
		win->board_address[tempx][tempy]->image(white1_img);
		win->board_address[tempx][tempy]->show();
		win->xsequence.push_back(tempx);
		win->ysequence.push_back(tempy);
		win->step++;//步数++
		return ;
		}
}


void  board:: show_black_win()//当黑方赢，弹出提示框
{
	    win->someone_win=1;
	        FSOUND_SAMPLE* handle1;
		    FSOUND_Init(44100,32,0);
     		handle1=FSOUND_Sample_Load (0,"lion.wav",0, 0);//同时放出音乐
		    FSOUND_PlaySound (0,handle1); 
	fl_alert("Black Win !");
}

void board::  show_white_win()//当白方赢，弹出提示框
{
	        win->someone_win=1;

	        FSOUND_SAMPLE* handle1;
		    FSOUND_Init(44100,32,0);
     		handle1=FSOUND_Sample_Load (0,"tiger.wav",0, 0);//同时放出音乐
		    FSOUND_PlaySound (0,handle1); 

	fl_alert("White Win !");
}

void  board:: check_white_win()//简单的算法检验是否出现白棋五子连珠
{
for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
	{	
		
		if(win->qipan[i][j]==win->qipan[i][j+1] &&win->qipan[i][j]==win->qipan[i][j+2] 
		&&win->qipan[i][j]==win->qipan[i][j+3] &&win->qipan[i][j]==win->qipan[i][j+4] &&win->qipan[i][j]==2)//水平方向上
			{
				show_white_win();
			}

		if(win->qipan[i][j]==win->qipan[i+1][j] &&win->qipan[i][j]==win->qipan[i+2][j] 
		&&win->qipan[i][j]==win->qipan[i+3][j] &&win->qipan[i][j]==win->qipan[i+4][j] &&win->qipan[i][j]==2)//竖直方向上
			{
				show_white_win();
			}
		if(win->qipan[i][j]==win->qipan[i+1][j+1] &&win->qipan[i][j]==win->qipan[i+2][j+2] 
		&&win->qipan[i][j]==win->qipan[i+3][j+3] &&win->qipan[i][j]==win->qipan[i+4][j+4] &&win->qipan[i][j]==2)//斜向下
			{
				show_white_win();
			}
		if(win->qipan[i][j]==win->qipan[i+1][j-1] &&win->qipan[i][j]==win->qipan[i+2][j-2] 
		&&win->qipan[i][j]==win->qipan[i+3][j-3] &&win->qipan[i][j]==win->qipan[i+4][j-4] &&win->qipan[i][j]==2)//斜向上
			{
				show_white_win();
			}
	}
}
         
}

void  board:: check_black_win()//简单的算法检验是否出现黑棋五子连珠
{
for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
	{	
		
		if(win->qipan[i][j]==win->qipan[i][j+1] &&win->qipan[i][j]==win->qipan[i][j+2] 
		&&win->qipan[i][j]==win->qipan[i][j+3] &&win->qipan[i][j]==win->qipan[i][j+4] &&win->qipan[i][j]==1)//水平方向上
			{
				show_black_win();
			}

		if(win->qipan[i][j]==win->qipan[i+1][j] &&win->qipan[i][j]==win->qipan[i+2][j] 
		&&win->qipan[i][j]==win->qipan[i+3][j] &&win->qipan[i][j]==win->qipan[i+4][j] &&win->qipan[i][j]==1)//竖直方向上
			{
			show_black_win();
			}
		if(win->qipan[i][j]==win->qipan[i+1][j+1] &&win->qipan[i][j]==win->qipan[i+2][j+2] 
		&&win->qipan[i][j]==win->qipan[i+3][j+3] &&win->qipan[i][j]==win->qipan[i+4][j+4] &&win->qipan[i][j]==1)//斜向下
		{
				show_black_win();
			}
		if(win->qipan[i][j]==win->qipan[i+1][j-1] &&win->qipan[i][j]==win->qipan[i+2][j-2] 
		&&win->qipan[i][j]==win->qipan[i+3][j-3] &&win->qipan[i][j]==win->qipan[i+4][j-4] &&win->qipan[i][j]==1)//斜向上
			{
				show_black_win();
			}
	}

   }
}     


void board:: shadow(int x,int y)//当鼠标在棋盘内，画出红色方框提示鼠标所在的方框
{
    int tempx=(x-81)/39;
	int tempy=(y-81)/39;
	
	tempx=tempx*39+100;
	tempy=tempy*39+100;
	
	win->redraw();
	win->current();
	fl_rect(tempx-19,tempy-19,39,39,FL_RED);
	
    win->redraw();
}



 
void backgroud()    //背景  函数
{
	cout<<"change picture111\n";
	cout<<"picture====="<<win->picture<<"   ====\n";

 

	 Fl_Box *box1_board2=new Fl_Box(375,373,0,0); 
     cout<< box1_board2<<endl;

  switch(win->picture%3)
	{
  case  0: {cout<<"1\n";box1_board2->image(board2_img);break;}
  case  1: { cout<<"2\n";box1_board2->image(board3_img);break;}
  case  2: { cout<<"3\n";box1_board2->image(board1_img);break;}
  default: {break;}
  }
  win->add(box1_board2);
  box1_board2->box(FL_DOWN_BOX);
  box1_board2->show();
  win->redraw();
}



void board::  set_address()//设立并初始化一个数组 board_address[][]，内存了window上所有能放棋子的box的地址
{
	cout<<"set address\n";
	for(int i=0;i<N;i++)
	{
       for(int j=0;j<N;j++)
	   {
	       Fl_Box *box2=new  Fl_Box(i*39+100,j*39+100,0,0); 
		  win->board_address[i][j]=box2;
		 win->add(  win->board_address[i][j]);
	   }
	}
}



 
#endif
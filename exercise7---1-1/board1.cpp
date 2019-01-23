
#ifndef BOARD_CPP
#define BOARD_CPP

#include"board1.h"


#pragma comment(lib,"Fmodvc.lib")                        //����Fmod��Ƶ��������
#include <conio.h>
#include "Fmod.h"


extern   Fl_GIF_Image *white1_img; 
extern	Fl_GIF_Image *black1_img;
extern	Fl_JPEG_Image *board1_img;
extern	Fl_JPEG_Image *board2_img;
extern	Fl_JPEG_Image *board3_img;
extern void change_picture()   ;
extern game_window *win;



//----------��board��ĺ������ж���--------------------------------------------------
board::board(int x1 ,int y1,int x, int y,int n)//��ʼ��board��
	:Fl_Widget (x1,y1,x,y,"")
{
	line_num=n;
	 set_address();
	
};

int board::handle(int e)//��׽����˶���handle����
{
	
	
	switch(e)
	{
		case  FL_PUSH://���������ˣ��Ϳ�ʼ����
			{
				int x=Fl::event_x();
				int y=Fl::event_y();
                cout<<x<<"    "<<y<<endl;
				 if(100<x && x<100+39*(N-1) && 100<y && y<100+39*(N-1))
				 {

				switch (win->mode)//������ѡ��Modeѡ��ͬ�����巽ʽ
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
		
		case FL_MOVE:{  //�������ƶ����򻭳���ɫС������
			     
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



void board::draw()//����������
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


void board::  xiaqi(int x,int y)//�������庯��
{      
	    int tempx=(x-81)/39;//�����ϵ�����Ϊtempx��tempy
		int tempy=(y-81)/39;
		cout<<tempx<<"  and   "<<tempy<<endl;
		if(win->qipan[tempx][tempy]!=0|| win->someone_win==1)//���Ѿ��ֳ�ʤ�������������Ѿ������¹�����������
		{   cout<<"wrong\n";
			return ;
		}


		if(!(win->step%2) )  //��Ϊ����������Ϊ�ڷ�ִ��
		{
			cout<<"black\n";
		
			
		win->board_address[tempx][tempy]->image(*black1_img);
		win->board_address[tempx][tempy]->show();
		win->redraw();
		win->qipan[tempx][tempy]=1;
		win->xsequence.push_back(tempx);
		win->ysequence.push_back(tempy);
		win->step++;//����++
		return  ;
		}
		else
		{   
			//��Ϊż��������Ϊ�׷�ִ��
        cout<<"white\n";
		win->qipan[tempx][tempy]=2;
		win->board_address[tempx][tempy]->image(white1_img);
		win->board_address[tempx][tempy]->show();
		win->xsequence.push_back(tempx);
		win->ysequence.push_back(tempy);
		win->step++;//����++
		return ;
		}
}


void  board:: show_black_win()//���ڷ�Ӯ��������ʾ��
{
	    win->someone_win=1;
	        FSOUND_SAMPLE* handle1;
		    FSOUND_Init(44100,32,0);
     		handle1=FSOUND_Sample_Load (0,"lion.wav",0, 0);//ͬʱ�ų�����
		    FSOUND_PlaySound (0,handle1); 
	fl_alert("Black Win !");
}

void board::  show_white_win()//���׷�Ӯ��������ʾ��
{
	        win->someone_win=1;

	        FSOUND_SAMPLE* handle1;
		    FSOUND_Init(44100,32,0);
     		handle1=FSOUND_Sample_Load (0,"tiger.wav",0, 0);//ͬʱ�ų�����
		    FSOUND_PlaySound (0,handle1); 

	fl_alert("White Win !");
}

void  board:: check_white_win()//�򵥵��㷨�����Ƿ���ְ�����������
{
for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
	{	
		
		if(win->qipan[i][j]==win->qipan[i][j+1] &&win->qipan[i][j]==win->qipan[i][j+2] 
		&&win->qipan[i][j]==win->qipan[i][j+3] &&win->qipan[i][j]==win->qipan[i][j+4] &&win->qipan[i][j]==2)//ˮƽ������
			{
				show_white_win();
			}

		if(win->qipan[i][j]==win->qipan[i+1][j] &&win->qipan[i][j]==win->qipan[i+2][j] 
		&&win->qipan[i][j]==win->qipan[i+3][j] &&win->qipan[i][j]==win->qipan[i+4][j] &&win->qipan[i][j]==2)//��ֱ������
			{
				show_white_win();
			}
		if(win->qipan[i][j]==win->qipan[i+1][j+1] &&win->qipan[i][j]==win->qipan[i+2][j+2] 
		&&win->qipan[i][j]==win->qipan[i+3][j+3] &&win->qipan[i][j]==win->qipan[i+4][j+4] &&win->qipan[i][j]==2)//б����
			{
				show_white_win();
			}
		if(win->qipan[i][j]==win->qipan[i+1][j-1] &&win->qipan[i][j]==win->qipan[i+2][j-2] 
		&&win->qipan[i][j]==win->qipan[i+3][j-3] &&win->qipan[i][j]==win->qipan[i+4][j-4] &&win->qipan[i][j]==2)//б����
			{
				show_white_win();
			}
	}
}
         
}

void  board:: check_black_win()//�򵥵��㷨�����Ƿ���ֺ�����������
{
for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
	{	
		
		if(win->qipan[i][j]==win->qipan[i][j+1] &&win->qipan[i][j]==win->qipan[i][j+2] 
		&&win->qipan[i][j]==win->qipan[i][j+3] &&win->qipan[i][j]==win->qipan[i][j+4] &&win->qipan[i][j]==1)//ˮƽ������
			{
				show_black_win();
			}

		if(win->qipan[i][j]==win->qipan[i+1][j] &&win->qipan[i][j]==win->qipan[i+2][j] 
		&&win->qipan[i][j]==win->qipan[i+3][j] &&win->qipan[i][j]==win->qipan[i+4][j] &&win->qipan[i][j]==1)//��ֱ������
			{
			show_black_win();
			}
		if(win->qipan[i][j]==win->qipan[i+1][j+1] &&win->qipan[i][j]==win->qipan[i+2][j+2] 
		&&win->qipan[i][j]==win->qipan[i+3][j+3] &&win->qipan[i][j]==win->qipan[i+4][j+4] &&win->qipan[i][j]==1)//б����
		{
				show_black_win();
			}
		if(win->qipan[i][j]==win->qipan[i+1][j-1] &&win->qipan[i][j]==win->qipan[i+2][j-2] 
		&&win->qipan[i][j]==win->qipan[i+3][j-3] &&win->qipan[i][j]==win->qipan[i+4][j-4] &&win->qipan[i][j]==1)//б����
			{
				show_black_win();
			}
	}

   }
}     


void board:: shadow(int x,int y)//������������ڣ�������ɫ������ʾ������ڵķ���
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



 
void backgroud()    //����  ����
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



void board::  set_address()//��������ʼ��һ������ board_address[][]���ڴ���window�������ܷ����ӵ�box�ĵ�ַ
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
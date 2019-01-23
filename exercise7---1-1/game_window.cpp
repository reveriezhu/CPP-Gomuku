#ifndef  GAMEWIN_CPP
#define  GAMEWIN_CPP

#include"game_window.h"



 game_window* win=new game_window (50,50,800,670," by  spt");//定义一个全局变量 *win

game_window::game_window(int x2 ,int y2,int w2, int h2,const char *lable)//初始化board类
	:Fl_Double_Window (x2,y2,w2,h2,lable)
{

	step=0;
	someone_win=0;
	
	mode=1;
	memset(qipan,0,sizeof(qipan));
	picture=3;
};

#endif
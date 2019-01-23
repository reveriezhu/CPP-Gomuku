#ifndef BUTTON_H
#define BUTTON_H



class Toolbar;
#include"board1.h"
#include<FL/Fl_Menu_Bar.H>
extern   Fl_GIF_Image *white1_img; 
extern	Fl_GIF_Image *black1_img;

extern game_window* win;


class Toolbar : public Fl_Button 
{
	                                    //建立一个button类，内含所有的button
public:
	     Fl_Button *quit;//退出
         Fl_Button *restart;//重新开始
		 Fl_Button *retract;//悔棋
		 Fl_Button *save;//存盘
		 Fl_Button *reload;//复盘
		 Fl_Menu_Bar *game_mode;//游戏模式的选择
		
		 static void cb_quit(Fl_Widget*, void*);//回调函数 们
		 static void cb_restart(Fl_Widget*, void*);
		 static void cb_retract(Fl_Widget*, void*);
		 static void cb_save(Fl_Widget*, void*);
		 static void cb_reload(Fl_Widget*, void*);
		 static void cb_game_mode1(Fl_Widget*, void*);
		 static void cb_game_mode2(Fl_Widget*, void*);
		 static void cb_game_mode3(Fl_Widget*, void*);


		static void  fun_restart(game_window *win);//回调函数的主体函数
		static void  fun_retract(game_window *win);
		static void  fun_save(game_window *win);
		static void  fun_reload(game_window  *win);
		static void  fun_game_mode1(game_window  *win);
		static void  fun_game_mode2(game_window  *win);
		static void  fun_game_mode3(game_window  *win);

		Toolbar(int Xpos, int Ypos, int Width, int Height);
};
#endif
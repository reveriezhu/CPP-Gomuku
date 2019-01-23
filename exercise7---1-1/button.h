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
	                                    //����һ��button�࣬�ں����е�button
public:
	     Fl_Button *quit;//�˳�
         Fl_Button *restart;//���¿�ʼ
		 Fl_Button *retract;//����
		 Fl_Button *save;//����
		 Fl_Button *reload;//����
		 Fl_Menu_Bar *game_mode;//��Ϸģʽ��ѡ��
		
		 static void cb_quit(Fl_Widget*, void*);//�ص����� ��
		 static void cb_restart(Fl_Widget*, void*);
		 static void cb_retract(Fl_Widget*, void*);
		 static void cb_save(Fl_Widget*, void*);
		 static void cb_reload(Fl_Widget*, void*);
		 static void cb_game_mode1(Fl_Widget*, void*);
		 static void cb_game_mode2(Fl_Widget*, void*);
		 static void cb_game_mode3(Fl_Widget*, void*);


		static void  fun_restart(game_window *win);//�ص����������庯��
		static void  fun_retract(game_window *win);
		static void  fun_save(game_window *win);
		static void  fun_reload(game_window  *win);
		static void  fun_game_mode1(game_window  *win);
		static void  fun_game_mode2(game_window  *win);
		static void  fun_game_mode3(game_window  *win);

		Toolbar(int Xpos, int Ypos, int Width, int Height);
};
#endif
#ifndef BOARD_H
#define BOARD_H
class board;

#include<iostream>
#include<FL/Fl.H>
#include<FL/Fl_Widget.H>
#include<FL/Fl_Double_Window.H>
#include<FL/fl_draw.H>
#include<FL/Fl_Button.H>
#include<FL/Fl_Box.H>
#include<FL/fl_ask.H>
#include<vector>

#include"game_window.h"

#define N 15

using namespace std;



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class board :public Fl_Widget//定义“棋盘类”，
{
private:
	int handle(int e);//内含对鼠标运动的捕捉
	int line_num;
	void draw();//画出棋盘线
	
	void xiaqi(int x,int y);//下棋函数

	void show_black_win();//当黑棋赢了时
	void show_white_win();
	void check_white_win();//检查是否白棋赢了
	void check_black_win();
	void shadow(int x,int y);//画出影子般的红色方框。。。。o(╯□╰)o
	
	void set_address();//设立一个box数组
	
public:
	
	void white_ai();//白棋的ai
	void black_ai();//黑棋的ai

	
board(int x1,int y1,int x, int y,int n);
};


#endif
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

class board :public Fl_Widget//���塰�����ࡱ��
{
private:
	int handle(int e);//�ں�������˶��Ĳ�׽
	int line_num;
	void draw();//����������
	
	void xiaqi(int x,int y);//���庯��

	void show_black_win();//������Ӯ��ʱ
	void show_white_win();
	void check_white_win();//����Ƿ����Ӯ��
	void check_black_win();
	void shadow(int x,int y);//����Ӱ�Ӱ�ĺ�ɫ���򡣡�����o(�s���t)o
	
	void set_address();//����һ��box����
	
public:
	
	void white_ai();//�����ai
	void black_ai();//�����ai

	
board(int x1,int y1,int x, int y,int n);
};


#endif
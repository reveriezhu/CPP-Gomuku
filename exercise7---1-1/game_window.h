#ifndef  GAMEWIN_H
#define  GAMEWIN_H

class game_window;
extern game_window* win;

#include<FL/Fl_Double_Window.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_GIF_Image.H>
#include<FL/Fl_Shared_Image.H>
#include<FL/Fl_JPEG_Image.H>
#include<FL/Fl_Image.H>

#include<iostream>
#include<string>

#include"board1.h"
#define N 15

using namespace std;
extern   Fl_GIF_Image *white1_img; 
extern	Fl_GIF_Image *black1_img;

class game_window :public Fl_Double_Window//定义“棋盘类”，
{
private:
 
 
public:
	friend class board;
	friend class Toolbar;
	game_window(int x2,int y2,int w2,int h2, const char *lable);//初始化
	int mode;//下棋模式：人人，人机，机人
	//int is_ai;//是否
	int picture;	//背景图片的选择
	
	Fl_Box* board_address[N][N];//记录棋盘的box的地址

	int step;//记录下棋的步数

    int qipan[N][N];//记录棋盘是否已经下了子，0为空，1为黑，2为白
	
	vector <int>xsequence;//一个vector用来记录每次下棋的x坐标
	vector <int>ysequence;//一个vector用来记录每次下棋的y坐标
	bool someone_win;//记录是否有人赢了
	
};





#endif
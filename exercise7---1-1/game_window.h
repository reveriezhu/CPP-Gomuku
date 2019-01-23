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

class game_window :public Fl_Double_Window//���塰�����ࡱ��
{
private:
 
 
public:
	friend class board;
	friend class Toolbar;
	game_window(int x2,int y2,int w2,int h2, const char *lable);//��ʼ��
	int mode;//����ģʽ�����ˣ��˻�������
	//int is_ai;//�Ƿ�
	int picture;	//����ͼƬ��ѡ��
	
	Fl_Box* board_address[N][N];//��¼���̵�box�ĵ�ַ

	int step;//��¼����Ĳ���

    int qipan[N][N];//��¼�����Ƿ��Ѿ������ӣ�0Ϊ�գ�1Ϊ�ڣ�2Ϊ��
	
	vector <int>xsequence;//һ��vector������¼ÿ�������x����
	vector <int>ysequence;//һ��vector������¼ÿ�������y����
	bool someone_win;//��¼�Ƿ�����Ӯ��
	
};





#endif
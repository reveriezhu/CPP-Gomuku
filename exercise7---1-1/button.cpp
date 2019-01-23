#ifndef BUTTON_CPP
#define BUTTON_CPP



#include"button.h"
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_File_Chooser.H>
#include <fstream>

#include<Windows.h>

#pragma comment(lib,"Fmodvc.lib")                        //引入Fmod音频播放引擎
#include <conio.h>
#include "Fmod.h"



extern game_window *win;
extern void change_picture();
extern  Fl_Box *box1_board2;
void Toolbar::cb_quit(Fl_Widget *w, void *data)//退出键的callback函数
{
	
	exit(0);
}

void Toolbar::fun_restart(game_window *win)//重新开始的主体函数
{

	 memset(win->qipan,0,sizeof(win->qipan));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
		win->board_address[i][j]->hide();
		}
	}
	
	win->someone_win=0;
	win->step=0;
	win->xsequence.clear();
	win->ysequence.clear();
}

void Toolbar::cb_restart(Fl_Widget *w, void *data)//重新开始键的callback函数
{
	cout<<"restart call back\n";
	fun_restart(win);
	
}

void Toolbar::fun_retract(game_window *win)//悔棋键的callback函数
{
	if(win->step==0)
	{
		fl_alert("You can't retract any more !");
		    FSOUND_SAMPLE* handle1;
		    FSOUND_Init(44100,32,0);
     		handle1=FSOUND_Sample_Load (0,"error.wav",0, 0);
		    FSOUND_PlaySound (0,handle1); 
	return;
	}
	int vsize=win->xsequence.size();
	
  win->step--;
  win->board_address[win->xsequence[vsize-1]][win->ysequence[vsize-1]]->hide();
  win->qipan[win->xsequence[vsize-1]][win->ysequence[vsize-1]]=0;
  win->someone_win=0;
  win->xsequence.pop_back();
  win->ysequence.pop_back();
}

void Toolbar::cb_retract(Fl_Widget *w, void *data)//悔棋键的callback函数
{
	if(win->mode==1)
	{
		fun_retract(win);
	    return;
	}
	if(win->mode==2 ||win->mode==3)
	{
		fun_retract(win);
		fun_retract(win);
	    return;
	}
	return;
}


void Toolbar::fun_save(game_window *win)//存盘 的callback函数
{

Fl_Native_File_Chooser *choose = new Fl_Native_File_Chooser();
choose->type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);   // 'saveas' browser
choose->title("Save As..");                               // optional title for chooser window
choose->directory("C:");                            // optional starting directory
choose->preset_file("untitled.txt");                      // optional default filename
choose->filter("Text Files\t*.txt"); 

choose->show();
	if(choose->filename()!=NULL)
	{
		const char* filename=choose->filename(0);
		win->label("Saveing");
		
		cout<<"Save File "<<filename<<endl;
		ofstream file(filename,ios::out);
		int i=0;
		while(i< win->step)
		{
		file<<i<<"\t"<<win->xsequence[i]<<"\t"<<win->ysequence[i]<<endl;
		cout<<i<<"\t"<<win->xsequence[i]<<"\t"<<win->ysequence[i]<<endl;
		i++;
		}
	}
}

void Toolbar::cb_save(Fl_Widget *w, void *data)//存盘键的callback函数
{
	fun_save(win);
}


void Toolbar::fun_reload(game_window *win)//复盘
{

Fl_Native_File_Chooser *choose = new Fl_Native_File_Chooser();
choose->type(Fl_Native_File_Chooser::BROWSE_FILE);   // 'saveas' browser
choose->title("Load As..");                               // optional title for chooser window
choose->directory("C:");                            // optional starting directory
choose->preset_file("untitled.txt");                      // optional default filename
choose->filter("Text Files\t*.txt"); 

choose->show();
	if(choose->filename()!=NULL)
	{
	const char* filename=choose->filename(0);
	win->label("Loading");
	//win->redraw();
	cout<<"Load File "<<filename<<endl;
	fun_restart(win);

	ifstream file(filename,ios::in);
		int i=0;
		int in_step,x,y;
		
		while(file>> in_step>>x>>y)
		{        Sleep(300);
			     Fl::flush();
			win->step=in_step+1;
			win->xsequence.push_back(x);
			win->ysequence.push_back(y);
			if(win->step%2)
			{
				 Sleep(300);
			     Fl::flush();
				win->qipan[x][y]=1;
				win->board_address[x][y]->image(black1_img);//在棋盘上贴上棋子
	         win->board_address[x][y]->show();
			
			
			}
			else
			{   Fl::flush();
			    Sleep(300);
				win->redraw();
				win->qipan[x][y]=2;
			    win->board_address[x][y]->image(white1_img);//在棋盘上贴上棋子
	            win->board_address[x][y]->show();
               
			}
			win->redraw();
 		}
		
	}
}

void Toolbar::cb_reload(Fl_Widget *w, void *data)// 复盘键的callback函数
{
	fun_reload(win);
}


void Toolbar::fun_game_mode1(game_window  *win)// mode1
{
	cout<<"m vs m\n";
	fun_restart(win);
	win->mode=1;
}

void Toolbar::cb_game_mode1(Fl_Widget *w, void *data)// mode1的callback函数
{
	fun_game_mode1(win);
}

void Toolbar::fun_game_mode2(game_window  *win)// mode2
{
	cout<<"m vs ai\n";
	fun_restart(win);
	win->mode=2;
}

void Toolbar::cb_game_mode2(Fl_Widget *w, void *data)// mode2的callback函数
{
	fun_game_mode2(win);
}


void Toolbar::fun_game_mode3(game_window  *win)// mode3
{
	cout<<"ai vs m\n";
	fun_restart(win);
	win->board_address[7][7]->image(*black1_img);
		win->board_address[7][7]->show();

		win->qipan[7][7]=1;
		win->xsequence.push_back(7);
		win->ysequence.push_back(7);
		win->step++;//步数++
	    win->mode=3;
}

void Toolbar::cb_game_mode3(Fl_Widget *w, void *data)// mode3的callback函数
{
	fun_game_mode3(win);
}


Toolbar::Toolbar(int Xpos, int Ypos, int Width, int Height) ://构造器，对6个按钮进行初始化
Fl_Button(Xpos, Ypos, Width, Height)
{
quit = new Fl_Button(Xpos, Ypos, Width, Height,"Quit");  
restart = new Fl_Button(Xpos+Width+20, Ypos, Width, Height,"Restart");
retract = new Fl_Button(Xpos+2*Width +40, Ypos, Width, Height,"Undo");
save = new Fl_Button(Xpos+3*Width+60, Ypos, Width, Height,"Save");
reload = new Fl_Button(Xpos+4*Width+80, Ypos, Width, Height,"Load");
game_mode = new Fl_Menu_Bar(Xpos+5*Width+100, Ypos, Width, Height,"Mode");

quit->callback(cb_quit,(void*)win);
restart->callback(cb_restart,(void*)win);
retract->callback(cb_retract,(void*)win);
save->callback(cb_save,(void*)win);
reload->callback(cb_reload,(void*)win);
game_mode->add("&\tMode/& \tMvsM",0,cb_game_mode1);
game_mode->add("&\tMode/& \tMvsAI",0,cb_game_mode2);
game_mode->add("&\tMode/& \tAIvsM",0,cb_game_mode3);
}

#endif
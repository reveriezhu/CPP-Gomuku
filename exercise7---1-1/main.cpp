#ifndef MAIN
#define  MAIN



#include"button.h"

//------------------------------------------------------------------------
    Fl_GIF_Image *white1_img=new Fl_GIF_Image("white22.gif");//�����ȫ�ֵ�ͼƬ
	
	 Fl_GIF_Image *black1_img=new Fl_GIF_Image("black.gif");
	
	Fl_JPEG_Image *board1_img=new Fl_JPEG_Image("board1.jpg");
	
	 Fl_JPEG_Image *board2_img=new Fl_JPEG_Image("green1.jpg");
	
	 Fl_JPEG_Image *board3_img=new Fl_JPEG_Image("clothes.jpg");
//-------------------------------------------------------------------------------



extern game_window *win; //�����ȫ�ֵ�win��ָ��
extern void backgroud()   ;

//----------------------------------------------------
int main()
{ 
	backgroud();//��������
	
	

	win->begin();
    win->color(FL_WHITE);
	
	board *chessboard=new board (20,20,100+39*(N-1),100+39*(N-1),N);
	Toolbar tool(0,30,100,30);//�ں�����button
	win->end();
    win->show();
	chessboard->show();
	return Fl::run();

}

#endif


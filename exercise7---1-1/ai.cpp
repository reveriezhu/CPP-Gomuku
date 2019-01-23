#ifndef AI_H
#define AI_H

/*���ֹ���
           *������ҷ������Ӽ����̱��ߣ�+�����λ��o����Ai������
		     + o +              1   ��  ����
			 + o o +            10  ��  ˫��
			 + o o o *          5  ��  ����
			 + o o o +          50 ��  ����
			 + o o o o *        2000��  ����
			 + o o o o +        500��  ����
			 o o o o o          5000�� ��������
			 �����������ӽ������֣���o��*����������ȡ�����ɡ�
*/


#include"board1.h"
#include"game_window.h"

extern game_window *win;//�ⲿ����

void board::black_ai()//�����ai
{
	if( win->someone_win==1)//���Ѿ��ֳ�ʤ�������������Ѿ������¹�����������
		{   cout<<"wrong\n";
			return  ;}

	 int   a_qipan[N][N]={
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
	{0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
	{0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
	{0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
	{0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
	{0,1,2,3,4,5,6,7,6,5,4,3,2,1,0},
	{0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
	{0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
	{0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
	{0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
	{0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};//��ʼ��


	 for(int i=0;i<N;i++)
	 {
		 for(int j=0;j<N;j++)
		 {//1�����
		    if( win->qipan[i][j-1]==1 || win->qipan[i][j+1]==1 || 
				win->qipan[i-1][j]==1 || win->qipan[i+1][j]==1 || 
				win->qipan[i-1][j-1]==1 || win->qipan[i+1][j+1]==0 || 
				win->qipan[i-1][j+1]==1 || win->qipan[i+1][j-1]==1 ) 
                    a_qipan[i][j]+=1;
            //2�����
			if(win->qipan[i-2][j]==1 && win->qipan[i-1][j]==1) 
				  a_qipan[i][j]+=5;
		    if(win->qipan[i+2][j]==1 && win->qipan[i+1][j]==1) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i][j-2]==1 && win->qipan[i][j-1]==1) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i][j+2]==1 && win->qipan[i][j+1]==1) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i+2][j+2]==1 && win->qipan[i+1][j+1]==1) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i-2][j+2]==1 && win->qipan[i-1][j+1]==1) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i+2][j-2]==1 && win->qipan[i+1][j-1]==1) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i-2][j-2]==1 && win->qipan[i-1][j-1]==1) 
				  a_qipan[i][j]+=5;

			if(win->qipan[i+1][j-1]==1 && win->qipan[i-1][j+1]==1) 
				  a_qipan[i][j]+=10;
			if(win->qipan[i+1][j]==1 && win->qipan[i-1][j]==1) 
				  a_qipan[i][j]+=10;
			if(win->qipan[i][j-1]==1 && win->qipan[i][j+1]==1) 
				  a_qipan[i][j]+=10;
			if(win->qipan[i+1][j+1]==1 && win->qipan[i-1][j-1]==1) 
				  a_qipan[i][j]+=10;
			//3
			if(win->qipan[i][j+3]==1 && win->qipan[i][j+2]==1 && win->qipan[i][j+1]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i][j-3]==1 && win->qipan[i][j-2]==1 && win->qipan[i][j-1]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-3][j]==1 && win->qipan[i-2][j]==1 && win->qipan[i-1][j]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+3][j]==1 && win->qipan[i+2][j]==1 && win->qipan[i+1][j]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+3][j+3]==1 && win->qipan[i+2][j+2]==1 && win->qipan[i+1][j+1]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-3][j+3]==1 &&win->qipan[i-2][j+2]==1 && win->qipan[i-1][j+1]==1) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+3][j-3]==1 &&win->qipan[i+2][j-2]==1 && win->qipan[i+1][j-1]==1) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-3][j-3]==1 &&win->qipan[i-2][j-2]==1 && win->qipan[i-1][j-1]==1) 
				  a_qipan[i][j]+=100;

			if(win->qipan[i][j-1]==1 && win->qipan[i][j+2]==1 && win->qipan[i][j+1]==1  ) 
				  a_qipan[i][j]+=100;
            if(win->qipan[i][j+1]==1 && win->qipan[i][j-2]==1 && win->qipan[i][j-1]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+1][j]==1 && win->qipan[i-2][j]==1 && win->qipan[i-1][j]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-1][j]==1 && win->qipan[i+2][j]==1 && win->qipan[i+1][j]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-1][j-1]==1 && win->qipan[i+2][j+2]==1 && win->qipan[i+1][j+1]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+1][j-1]==1 &&win->qipan[i-2][j+2]==1 && win->qipan[i-1][j+1]==1) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-1][j+1]==1 &&win->qipan[i+2][j-2]==1 && win->qipan[i+1][j-1]==1) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+1][j+11]==1 &&win->qipan[i+2][j+2]==1 && win->qipan[i+1][j+1]==1) 
				  a_qipan[i][j]+=100;


			//4�����
			if(win->qipan[i][j+4]==1 &&win->qipan[i][j+3]==1 && win->qipan[i][j+2]==1 && win->qipan[i][j+1]==1  ) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i][j-4]==1 &&win->qipan[i][j-3]==1 && win->qipan[i][j-2]==1 && win->qipan[i][j-1]==1  ) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i-4][j]==1 &&win->qipan[i-3][j]==1 && win->qipan[i-2][j]==1 && win->qipan[i-1][j]==1  ) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i+4][j]==1 &&win->qipan[i+3][j]==1 && win->qipan[i+2][j]==1 && win->qipan[i+1][j]==1  ) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i+4][j+4]==1 &&win->qipan[i+3][j+3]==1 && win->qipan[i+2][j+2]==1 && win->qipan[i+1][j+1]==1  ) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i-4][j+4]==1 &&win->qipan[i-3][j+3]==1 &&win->qipan[i-2][j+2]==1 && win->qipan[i-1][j+1]==1) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i+4][j-4]==1 &&win->qipan[i+3][j-3]==1 &&win->qipan[i+2][j-2]==1 && win->qipan[i+1][j-1]==1) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i-4][j-4]==1 &&win->qipan[i-3][j+3]==1 &&win->qipan[i-2][j-2]==1 && win->qipan[i-1][j-1]==1) 
				  a_qipan[i][j]+=50000;



			

			//defend�����
			//3
			if(win->qipan[i][j+3]==2 && win->qipan[i][j+2]==2 && win->qipan[i][j+1]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i][j-3]==2 && win->qipan[i][j-2]==2 && win->qipan[i][j-1]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i-3][j]==2 && win->qipan[i-2][j]==2 && win->qipan[i-1][j]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+3][j]==2 && win->qipan[i+2][j]==2 && win->qipan[i+1][j]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+3][j+3]==2 && win->qipan[i+2][j+2]==2 && win->qipan[i+1][j+1]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i-3][j+3]==2 &&win->qipan[i-2][j+2]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+3][j-3]==2 &&win->qipan[i+2][j-2]==2 && win->qipan[i+1][j-1]==2) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i-3][j-3]==2 &&win->qipan[i-2][j-2]==2 && win->qipan[i-1][j-1]==2) 
				  a_qipan[i][j]+=50;

			if(win->qipan[i][j-1]==2 && win->qipan[i][j+2]==2 && win->qipan[i][j+1]==2  ) 
				  a_qipan[i][j]+=50;
            if(win->qipan[i][j+1]==2 && win->qipan[i][j-2]==2 && win->qipan[i][j-1]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+1][j]==2 && win->qipan[i-2][j]==2 && win->qipan[i-1][j]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i-1][j]==2 && win->qipan[i+2][j]==2 && win->qipan[i+1][j]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i-1][j-1]==2 && win->qipan[i+2][j+2]==2 && win->qipan[i+1][j+1]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+1][j-1]==2 &&win->qipan[i-2][j+2]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i-1][j+1]==2 &&win->qipan[i+2][j-2]==2 && win->qipan[i+1][j-1]==2) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+1][j+1]==2 &&win->qipan[i+2][j+2]==2 && win->qipan[i+1][j+1]==2) 
				  a_qipan[i][j]+=50;

			//4
			if(win->qipan[i][j+4]==2 &&win->qipan[i][j+3]==2 && win->qipan[i][j+2]==1 && win->qipan[i][j+1]==2  ) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i][j-4]==2 &&win->qipan[i][j-3]==2 && win->qipan[i][j-2]==2 && win->qipan[i][j-1]==2  ) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i-4][j]==2 &&win->qipan[i-3][j]==2 && win->qipan[i-2][j]==2 && win->qipan[i-1][j]==2  ) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i+4][j]==2 &&win->qipan[i+3][j]==2 && win->qipan[i+2][j]==2 && win->qipan[i+1][j]==2  ) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i+4][j+4]==2 &&win->qipan[i+3][j+3]==2 && win->qipan[i+2][j+2]==2 && win->qipan[i+1][j+1]==2  ) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i-4][j+4]==2 &&win->qipan[i-3][j+3]==2 &&win->qipan[i-2][j+2]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i+4][j-4]==2 &&win->qipan[i+3][j-3]==2 &&win->qipan[i+2][j-2]==2 && win->qipan[i+1][j-1]==2) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i-4][j-4]==2 &&win->qipan[i-3][j-3]==2 &&win->qipan[i-2][j-2]==2 && win->qipan[i-1][j-1]==2) 
				  a_qipan[i][j]+=30000;
		 }
	 
	 
	 }

	 int max_x=0;
	 int max_y=0;
	 int max=win->qipan[0][0];

	  for(int i=0;i<N;i++)
	 {
		 for(int j=0;j<N;j++)
		 {
			  if(win->qipan[i][j]!=0)
			  { cout<<"x"<<"  ";}
			  else
			  {cout<<a_qipan[i][j]<<"  ";}
		 }
		 cout<<endl;
	  }

	  for(int i=0;i<N;i++)
	 {
		 for(int j=0;j<N;j++)
		 {
			 
			 if(win->qipan[i][j]!=0)
				cout<<" jump it\n";
			 else if(a_qipan[i][j]>max)
			 {
			   max=a_qipan[i][j];
			   max_x=i;
			   max_y=j;
			 }
         
		 }
   
      }
	  //--------------------------------------
	  int tempx=max_x; int tempy=max_y;

	  if(win->qipan[tempx][tempy]!=0|| win->someone_win==1)//���Ѿ��ֳ�ʤ�������������Ѿ������¹�����������
		{   cout<<"wrong\n";
			}


		if(!(win->step%2) )  //��Ϊ����������Ϊ�ڷ�ִ��
		{
			cout<<"black\n";
		
			
		win->board_address[tempx][tempy]->image(*black1_img);
		win->board_address[tempx][tempy]->show();

		win->qipan[tempx][tempy]=1;
		win->xsequence.push_back(tempx);
		win->ysequence.push_back(tempy);
		win->step++;//����++
	
		}
		else
		{   //��Ϊż��������Ϊ�׷�ִ��
      
			
	    cout<<"white\n";
		win->qipan[tempx][tempy]=2;
		
		
		win->board_address[tempx][tempy]->image(white1_img);
		win->board_address[tempx][tempy]->show();
		win->xsequence.push_back(tempx);
		win->ysequence.push_back(tempy);
		win->step++;//����++
		
	  //---------------------------------------
	    //win->is_ai = 0;
        }

}


//----------------------------------------------------------------------------------------
void board::white_ai()//�����ai��������˼·ͬ��
{
	if( win->someone_win==1)
		{   cout<<"wrong\n";
			return  ;}

	 int   a_qipan[N][N]={
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
	{0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
	{0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
	{0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
	{0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
	{0,1,2,3,4,5,6,7,6,5,4,3,2,1,0},
	{0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
	{0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
	{0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
	{0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
	{0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};


	 for(int i=0;i<N;i++)
	 {
		 for(int j=0;j<N;j++)
		 {//1
		    if( win->qipan[i][j-1]==2 || win->qipan[i][j+1]==2 || 
				win->qipan[i-1][j]==2 || win->qipan[i+1][j]==2 || 
				win->qipan[i-1][j-1]==2 || win->qipan[i+1][j+1]==2 || 
				win->qipan[i-1][j+1]==2 || win->qipan[i+1][j-1]==2 ) 
                    a_qipan[i][j]+=1;
			//2
			if(win->qipan[i-2][j]==2 && win->qipan[i-1][j]==2) 
				  a_qipan[i][j]+=5;
		    if(win->qipan[i+2][j]==2 && win->qipan[i+1][j]==2) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i][j-2]==2 && win->qipan[i][j-1]==2) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i][j+2]==2 && win->qipan[i][j+1]==2) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i+2][j+2]==2 && win->qipan[i+1][j+1]==2) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i-2][j+2]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i+2][j-2]==2 && win->qipan[i+1][j-1]==2) 
				  a_qipan[i][j]+=5;
			if(win->qipan[i-2][j+2]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=5;

			if(win->qipan[i+1][j-1]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=10;
			if(win->qipan[i+1][j]==2 && win->qipan[i-1][j]==2) 
				  a_qipan[i][j]+=10;
			if(win->qipan[i][j-1]==2 && win->qipan[i][j+1]==2) 
				  a_qipan[i][j]+=10;
			if(win->qipan[i+1][j+1]==2 && win->qipan[i-1][j-1]==2) 
				  a_qipan[i][j]+=10;
			//3
			if(win->qipan[i][j+3]==2 && win->qipan[i][j+2]==2 && win->qipan[i][j+1]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i][j-3]==2 && win->qipan[i][j-2]==2 && win->qipan[i][j-1]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i-3][j]==2 && win->qipan[i-2][j]==2 && win->qipan[i-1][j]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+3][j]==2 && win->qipan[i+2][j]==2 && win->qipan[i+1][j]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+3][j+3]==2 && win->qipan[i+2][j+2]==2 && win->qipan[i+1][j+1]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i-3][j+3]==2 &&win->qipan[i-2][j+2]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+3][j-3]==2 &&win->qipan[i+2][j-2]==2 && win->qipan[i+1][j-1]==2) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i][j+3]==2 &&win->qipan[i-2][j+2]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=50;

			if(win->qipan[i][j-1]==2 && win->qipan[i][j+2]==2 && win->qipan[i][j+1]==2  ) 
				  a_qipan[i][j]+=50;
            if(win->qipan[i][j+1]==2 && win->qipan[i][j-2]==2 && win->qipan[i][j-1]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+1][j]==2 && win->qipan[i-2][j]==2 && win->qipan[i-1][j]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i-1][j]==2 && win->qipan[i+2][j]==2 && win->qipan[i+1][j]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i-1][j-1]==2 && win->qipan[i+2][j+2]==2 && win->qipan[i+1][j+1]==2  ) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+1][j-1]==2 &&win->qipan[i-2][j+2]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i-1][j+1]==2 &&win->qipan[i+2][j-2]==2 && win->qipan[i+1][j-1]==2) 
				  a_qipan[i][j]+=50;
			if(win->qipan[i+1][j-1]==2 &&win->qipan[i-2][j+2]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=50;


			//4
			if(win->qipan[i][j+4]==2 &&win->qipan[i][j+3]==2 && win->qipan[i][j+2]==2 && win->qipan[i][j+1]==2  ) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i][j-4]==2 &&win->qipan[i][j-3]==2 && win->qipan[i][j-2]==2 && win->qipan[i][j-1]==2  ) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i-4][j]==2 &&win->qipan[i-3][j]==2 && win->qipan[i-2][j]==2 && win->qipan[i-1][j]==2  ) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i+4][j]==2 &&win->qipan[i+3][j]==2 && win->qipan[i+2][j]==2 && win->qipan[i+1][j]==2  ) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i+4][j+4]==2 &&win->qipan[i+3][j+3]==2 && win->qipan[i+2][j+2]==2 && win->qipan[i+1][j+1]==2  ) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i-4][j+4]==2 &&win->qipan[i-3][j+3]==2 &&win->qipan[i-2][j+2]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i+4][j-4]==2 &&win->qipan[i+3][j-3]==2 &&win->qipan[i+2][j-2]==2 && win->qipan[i+1][j-1]==2) 
				  a_qipan[i][j]+=30000;
			if(win->qipan[i-4][j+4]==2 &&win->qipan[i][j+3]==2 &&win->qipan[i-2][j+2]==2 && win->qipan[i-1][j+1]==2) 
				  a_qipan[i][j]+=30000;
			//defend
			//3
			if(win->qipan[i][j+3]==1 && win->qipan[i][j+2]==1 && win->qipan[i][j+1]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i][j-3]==1 && win->qipan[i][j-2]==1 && win->qipan[i][j-1]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-3][j]==1 && win->qipan[i-2][j]==1 && win->qipan[i-1][j]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+3][j]==1 && win->qipan[i+2][j]==1 && win->qipan[i+1][j]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+3][j+3]==1 && win->qipan[i+2][j+2]==1 && win->qipan[i+1][j+1]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-3][j+3]==1 &&win->qipan[i-2][j+2]==1 && win->qipan[i-1][j+1]==1) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+3][j-3]==1 &&win->qipan[i+2][j-2]==1 && win->qipan[i+1][j-1]==1) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-3][j-3]==1 &&win->qipan[i-2][j-2]==1 && win->qipan[i-1][j-1]==1) 
				  a_qipan[i][j]+=100;

			if(win->qipan[i][j-1]==1 && win->qipan[i][j+2]==1 && win->qipan[i][j+1]==1  ) 
				  a_qipan[i][j]+=100;
            if(win->qipan[i][j+1]==1 && win->qipan[i][j-2]==1 && win->qipan[i][j-1]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+1][j]==1 && win->qipan[i-2][j]==1 && win->qipan[i-1][j]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-1][j]==1 && win->qipan[i+2][j]==1 && win->qipan[i+1][j]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-1][j-1]==1 && win->qipan[i+2][j+2]==1 && win->qipan[i+1][j+1]==1  ) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+1][j-1]==1 &&win->qipan[i-2][j+2]==1 && win->qipan[i-1][j+1]==1) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i-1][j+1]==1 &&win->qipan[i+2][j-2]==1 && win->qipan[i+1][j-1]==1) 
				  a_qipan[i][j]+=100;
			if(win->qipan[i+1][j+11]==1 &&win->qipan[i+2][j+2]==1 && win->qipan[i+1][j+1]==1) 
				  a_qipan[i][j]+=100;


			//4�����
			if(win->qipan[i][j+4]==1 &&win->qipan[i][j+3]==1 && win->qipan[i][j+2]==1 && win->qipan[i][j+1]==1  ) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i][j-4]==1 &&win->qipan[i][j-3]==1 && win->qipan[i][j-2]==1 && win->qipan[i][j-1]==1  ) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i-4][j]==1 &&win->qipan[i-3][j]==1 && win->qipan[i-2][j]==1 && win->qipan[i-1][j]==1  ) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i+4][j]==1 &&win->qipan[i+3][j]==1 && win->qipan[i+2][j]==1 && win->qipan[i+1][j]==1  ) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i+4][j+4]==1 &&win->qipan[i+3][j+3]==1 && win->qipan[i+2][j+2]==1 && win->qipan[i+1][j+1]==1  ) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i-4][j+4]==1 &&win->qipan[i-3][j+3]==1 &&win->qipan[i-2][j+2]==1 && win->qipan[i-1][j+1]==1) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i+4][j-4]==1 &&win->qipan[i+3][j-3]==1 &&win->qipan[i+2][j-2]==1 && win->qipan[i+1][j-1]==1) 
				  a_qipan[i][j]+=50000;
			if(win->qipan[i-4][j-4]==1 &&win->qipan[i-3][j+3]==1 &&win->qipan[i-2][j-2]==1 && win->qipan[i-1][j-1]==1) 
				  a_qipan[i][j]+=50000;

		 }
	 
	 
	 }

	 int max_x=0;
	 int max_y=0;
	 int max=win->qipan[0][0];

	  for(int i=0;i<N;i++)
	 {
		 for(int j=0;j<N;j++)
		 {
			  if(win->qipan[i][j]!=0)
			  { cout<<"x"<<"  ";}
			  else
			  {cout<<a_qipan[i][j]<<"  ";}
		 }
		 cout<<endl;
	  }

	  for(int i=0;i<N;i++)
	 {
		 for(int j=0;j<N;j++)
		 {
			 
			 if(win->qipan[i][j]!=0)
				cout<<" jump it\n";
			 else if(a_qipan[i][j]>max)
			 {
			   max=a_qipan[i][j];
			   max_x=i;
			   max_y=j;
			 }
         
		 }
   
      }

	  cout<<max_x<<"     "<<max_y<<"-----"<<max<<endl;
	  //--------------------------------------
	  int tempx=max_x; int tempy=max_y;

	  if(win->qipan[tempx][tempy]!=0|| win->someone_win==1)//���Ѿ��ֳ�ʤ�������������Ѿ������¹�����������
		{   cout<<"wrong\n";
			}


		if(!(win->step%2) )  //��Ϊ����������Ϊ�ڷ�ִ��
		{
			cout<<"black\n";
		
			//cout<<win->board_address[tempx][tempy]<<endl;
		win->board_address[tempx][tempy]->image(*black1_img);
		win->board_address[tempx][tempy]->show();

		win->qipan[tempx][tempy]=1;
		win->xsequence.push_back(tempx);
		win->ysequence.push_back(tempy);
		win->step++;//����++
	
		}
		else
		{   //��Ϊż��������Ϊ�׷�ִ��
      
			
	    cout<<"white\n";
		win->qipan[tempx][tempy]=2;
		
		
		win->board_address[tempx][tempy]->image(white1_img);
		win->board_address[tempx][tempy]->show();
		win->xsequence.push_back(tempx);
		win->ysequence.push_back(tempy);
		win->step++;//����++
		
	  //---------------------------------------
	   // win->is_ai = 0;
        }

}











#endif
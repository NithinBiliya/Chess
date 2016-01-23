
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>

void mainmenu();

void board()
{ setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  int box[30];
  for(int i=0;i<=9;i++)
   if(i%2==0)
    box[i]=150;
   else
    box[i]=60;
  setcolor(WHITE);
  int sign=-1;
  while(box[1]<=400)
  { box[3]=box[1];
    box[5]=box[7];
    box[1]+=43;
    box[7]=box[1];
    box[9]=box[1];
    box[0]=box[2]=box[4]=150;
    while(box[4]<=490)
    { box[2]=box[4];
      box[8]=box[0];
      box[4]+=43;
      box[6]=box[4];
      if(sign<0)
       setfillstyle(SOLID_FILL,LIGHTGRAY);
      else
       setfillstyle(SOLID_FILL,DARKGRAY);
      fillpoly(5,box);
      box[0]=box[6];
      sign*=-1; }
    sign*=-1;  }
//    setfillstyle(SOLID_FILL,WHITE);
//    bar(0,getmaxy()-15,getmaxx(),getmaxy());
/*    setcolor(BLACK);
    bar(getmaxx()-40,getmaxy()-55,getmaxx(),getmaxy()-15);
    settextstyle(10,0,1);
    setcolor(BLUE);
/*    line(608,430,608,460);
    line(630,430,630,460);
    line(614,430,614,461);
    //outtextxy(getmaxx()-30,getmaxy()-55,"M");   }*/
	 }

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();
 board();
 char ch;
 ch=getch();
 if(ch=='m'||ch=='M')
  mainmenu();
//  cout<<getmaxx();
//  cout<<getmaxy();
 getch();
 closegraph();
}

void mainmenu()
{ float y;
  setcolor(RED);
  setfillstyle(10,RED);
  for(int x=640;x>=0;x--)
  { y=0.75*x;
    bar(x,y,640,480); }
  setfillstyle(10,BLACK);
  for(x=0,y=0;x<=640;x++)
  { y=0.75*x;
    bar(0,0,x,y); }}


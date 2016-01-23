
#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>

void mainmenu();

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();
 getch();
 mainmenu();
 getch();
 closegraph();
}

void mainmenu()
{ setfillstyle(10,RED);
  float m,x,y;
  x=getmaxx();
  y=getmaxy();
  m=y/x;
  while(y>=0)
  { bar(x,y,getmaxx(),getmaxy());
    y-=2;
    x=y/m; }
  x=y=0;
  setfillstyle(10,BLACK);
  while(y<=getmaxy())
  { bar(0,0,x,y);
    y+=2;
    x=y/m; }}
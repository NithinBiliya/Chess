
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>
//#include"H:\chess\function.cpp"

void draw();

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();

 draw();

 getch();
 closegraph();
}

void draw()
{ int x=350,y=300;
  setcolor(RED);
  line(x,y,x-50,y);
  line(x,y,x-5,y-20);
  line(x-50,y,x-45,y-20);

  line(x-45,y-20,x-5,y-20);
  line(x-45,y-22,x-5,y-22);
  line(x-45,y-20,x-40,y-100);
  line(x-5,y-20,x-10,y-100);

  line(x-40,y-100,x-10,y-100);
  line(x-40,y-98,x-10,y-98);
  line(x-40,y-100,x-45,y-115);
  line(x-10,y-100,x-5,y-115);

  setlinestyle(SOLID_LINE,
  line(x-45,y-115,x-5,y-115);
  line(x-25,y-115,x-25,y-125);
  line(x-30,y-120,x-20,y-120);

putpixel(350,300,YELLOW); }


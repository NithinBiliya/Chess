#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>
//#include"F:\chess\load.cpp"
#include"G:\chess\mouses.cpp"
//#include"F:\chess\function.cpp"
//#include"F:\chess\1stpg.cpp"


void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");

 { cleardevice();
  int x=100,y=0;
  float radiens,x1,y1;
  float rad,x2,y2;
  void balls(int &i,int &j,float &degree,float &deg,int r)
{
  if(i==getmaxx()/2)
  {
   radiens=(M_PI/180)*degree;
   x1=x*cos(radiens)+y*sin(radiens);
   y1=-x*sin(radiens)+y*cos(radiens);
   x1+=getmaxx()/2;
   y1+=getmaxy()/2;
   rad=(M_PI/180)*deg;
   x2=x*cos(rad)+y*sin(rad);
   y2=-x*sin(rad)+y*cos(rad);
   x2+=getmaxx()/2;
   y2+=getmaxy()/2;
   setfillstyle(SOLID_FILL,RED);
   setcolor(WHITE);
   circle(x1,y1,r);
   floodfill(x1,y1,WHITE);
   circle(x2,y2,r);
   floodfill(x2,y2,WHITE);
   delay(5);
   setfillstyle(SOLID_FILL,BLACK);
   setcolor(BLACK);
   floodfill(x1,y1,WHITE);
   floodfill(x2,y2,WHITE);
   circle(x1,y1,r);
   circle(x2,y2,r);
   degree++;
   deg++;
  }
  else
  {  setfillstyle(SOLID_FILL,RED);
     setcolor(WHITE);
     circle(i,(getmaxy()/2)-100,r);
     floodfill(i,(getmaxy()/2)-100,WHITE);
     circle(j,(getmaxy()/2)+100,r);
     floodfill(j,(getmaxy()/2)+100,WHITE);
     delay(5);
     setfillstyle(SOLID_FILL,BLACK);
     floodfill(i,(getmaxy()/2)-100,WHITE);
     floodfill(j,(getmaxy()/2)+100,WHITE);
     setcolor(BLACK);
     circle(i,(getmaxy()/2)-100,r);
     circle(j,(getmaxy()/2)+100,r);
     i--; j++;  }
}
 int i=getmaxx(),j=0;
 int a=getmaxx()+20,b=-20;
 int p=getmaxx()+38,q=-38;
 float degree1=90,deg1=270;
 float degree2=90,deg2=270;
 float degree3=90,deg3=270;
 while(!kbhit())
 {
       balls(i,j,degree1,deg1,10);
       balls(a,b,degree2,deg2,8);
       balls(p,q,degree3,deg3,6);
 }}



/* cleardevice();
 firstscreen();
 secondscreen(0);
 cleardevice();*/

 getch();
 closegraph();
}



#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>
#include<math.h>

void hand();

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();

 hand();

 getch();
 closegraph();
}

void hand()
{ float x1=300,y1=300,x2,y2,a=92;
  float d=300;
  bar(100,100,300,300);
  delay(2000);
  while(a>=90)
  { x2=x1+d*cos(a);
    y2=y1+d*sin(a);
    setcolor(RED);
    line(x1,y1,x2,y2);
//    delay(5);
    setcolor(BLACK);
    line(x1,y1,x2,y2);
    a-=0.0001; }
  while(a<=92)
  { x2=x1+d*cos(a);
    y2=y1+d*sin(a);
    setcolor(RED);
    line(x1,y1,x2,y2);
//    delay(5);
    setcolor(BLACK);
    line(x1,y1,x2,y2);
    a+=0.0001; }}







  /*float x1=300,y1=300;
  float x2=200,y2=200;
  float m=(y2-y1)/(x2-x1);
  float d=sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
  while(!kbhit())
  { x2=x1+(d/sqrt(1+m*m));
    y2=y1+((m*d)/sqrt(1+m*m));
    setcolor(RED);
    line(x1,y1,x2,y2);
//    delay(20);
    setcolor(BLACK);
    line(x1,y1,x2,y2);
    m--; }
  cout<<m; }


  */

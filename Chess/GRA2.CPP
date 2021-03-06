//	HELP
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
#include<math.h>
#include"G:\chess\mouses.cpp"
#include"G:\chess\1stpg.cpp"

void video(int,int,int);
void king(char [30]);
void hand(float x1,float x2,float a,float d);
void hand2(float x1,float x2,float a,float d);
void hand3(float x1,float x2,float a,float d);

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();
 char name[30]={"ch1"};
 king(name);
 hand3(375,215,92,30);
 int Mstatus = initmouse();
 int button,m,n;
 int z=0;
 if(Mstatus == 0 )
  outtextxy(50,50, "Mouse Support Not Available");
 settextstyle(2,0,4);
// changecursor(cursor);
 while(1)
{ showmouseptr();
  getmousepos(&button,&m,&n);
  if(m>245 && m<325 && n>220 && n<232)
  { setcolor(RED);
    outtextxy(250,220,"HOW TO PLAY"); }
  else
  { setcolor(WHITE);
    outtextxy(250,220,"HOW TO PLAY");
  if(m>245 && m<325 && n>240 && n<252)
  { setcolor(RED);
    outtextxy(250,240,"CONTROLS");  }
  else
  { setcolor(WHITE);
    outtextxy(250,240,"CONTROLS");
  if(m>245 && m<325 && n>260 && n<272)
  { setcolor(RED);
    outtextxy(250,260,"BACK");  }
  else
  { setcolor(WHITE);
    outtextxy(250,260,"BACK"); }}}
  if(button == 1)
  { if(m>245 && m<325 && n>220 && n<232)
    { hidemouseptr();
      video(450,150,0);  }
    if(m>245 && m<325 && n>240 && n<252)
    { hidemouseptr();
      video(450,150,0); }
    if(m>245 && m<325 && n>260 && n<272)
    { hidemouseptr();
      video(450,150,0);
      exit(0); }}}
 getch();
 closegraph();
}

void video(int x,int y,int p)
{ setcolor(WHITE);
/*  ellipse(x,y,140,40,25,25);
  rectangle(x-20,y-20,x+20,y-16);
  line(x-20,y-20,x-25,y-35);
  line(x+20,y-20,x+25,y-35);
  line(x-25,y-35,x-10,y-25);
  line(x+25,y-35,x+10,y-25);
  line(x-10,y-25,x,y-35);
  line(x+10,y-25,x,y-35);
  circle(x-8,y-7,3);
  circle(x+8,y-7,3);
  line(x,y-6,x-3,y+3);
  line(x-3,y+3,x+1,y+3);
  ellipse(x,y+5,180,360,10,10);

  line(x-50,y+25,x+50,y+25);
  line(x-50,y+25,x-75,y+65);
  line(x-40,y+50,x-75,y+100);
  line(x-40,y+50,x-35,y+125);

  line(x+50,y+25,x+75,y+75);
  line(x+40,y+50,x+55,y+75);
  line(x+55,y+75,x+36,y+110);
  line(x+75,y+75,x+36,y+130);

  line(x+40,y+50,x+35,y+125);
  line(x-35,y+125,x+35,y+125);
  line(x-35,y+125,x-40,y+225);
  line(x+35,y+125,x+40,y+225);
  line(x-40,y+225,x+40,y+225);

  ellipse(x-250,y-25,316,346,300,200);
  ellipse(x-275,y-25,323,346,300,200);*/
  x=x-75; y=y+65;
  line(x,y,x,y+35);
  line(x,y,x,y+35);
  x=x+75; y=y-65;
/*  setfillstyle(SOLID_FILL,RED);
  floodfill(x,y-30,WHITE);
  setfillstyle(SOLID_FILL,12);
  floodfill(x,y,WHITE);
  setfillstyle(SOLID_FILL,BLUE);
  floodfill(x,y+45,WHITE);
  setfillstyle(SOLID_FILL,GREEN);
  floodfill(x,y+65,WHITE);
  setfillstyle(SOLID_FILL,BLUE);
  floodfill(x,y+100,WHITE);
  setfillstyle(SOLID_FILL,BROWN);
  floodfill(x,y+150,WHITE);*/
  x=x-75; y=y+65;
  if(p==0)
  { hand3(x,y,92,30);
    hand(x,y,92,30); }
  else
   hand2(x,y,92,30);
}

void hand2(float x1,float y1,float a,float d)
{ setcolor(WHITE);
  float b=a;
  float x2,y2,x5,y5,x10,y10;
  float x3,y3,x4,y4,x9,y9,x11,y11;
  float x6,y6,x7,y7,x8,y8;
  { x2=x1+d*cos(a);
    y2=y1+d*sin(a);
    x3=x1+d*cos(a);
    y3=y1+35+(d*sin(a));
    x4=x1+(d+3)*cos(a);
    y4=y1+35+((d+3)*sin(a));
    x5=x1+(d+3)*cos(a);
    y5=y1+(d+3)*sin(a);
    x6=x1+(d+3)*cos(a);
    y6=(y1+18)+(d+3)*sin(a);
    x7=x1+(d+150)*cos(a);
    y7=(y1+18)+(d+150)*sin(a);
    x8=x1+(d+150)*cos(a);
    y8=(y1+10)+(d+150)*sin(a);
    x9=x1+(d+3)*cos(a);
    y9=(y1+10)+(d+3)*sin(a);
    x10=x1+(d+6)*cos(a);
    y10=(y1+15)+(d+10)*sin(a);
    x11=x1+(d-5)*cos(a);
    y11=(y1+15)+(d-5)*sin(a);
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(x10,y10,WHITE);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(x11,y11,WHITE);    }}

void hand3(float x1,float y1,float a,float d)
{ setcolor(WHITE);
  float b=a;
  float x2,y2,x5,y5,x10,y10;
  float x3,y3,x4,y4,x9,y9,x11,y11;
  float x6,y6,x7,y7,x8,y8;
  { x2=x1+d*cos(a);
    y2=y1+d*sin(a);
    x3=x1+d*cos(a);
    y3=y1+35+(d*sin(a));
    x4=x1+(d+3)*cos(a);
    y4=y1+35+((d+3)*sin(a));
    x5=x1+(d+3)*cos(a);
    y5=y1+(d+3)*sin(a);
    x6=x1+(d+3)*cos(a);
    y6=(y1+18)+(d+3)*sin(a);
    x7=x1+(d+150)*cos(a);
    y7=(y1+18)+(d+150)*sin(a);
    x8=x1+(d+150)*cos(a);
    y8=(y1+10)+(d+150)*sin(a);
    x9=x1+(d+3)*cos(a);
    y9=(y1+10)+(d+3)*sin(a);
    x10=x1+(d+6)*cos(a);
    y10=(y1+15)+(d+10)*sin(a);
    x11=x1+(d-5)*cos(a);
    y11=(y1+15)+(d-5)*sin(a);
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(x10,y10,WHITE);
    floodfill(x11,y11,WHITE);    }}

void hand(float x1,float y1,float a,float d)
{ float b=a;
  float x2,y2,x5,y5,x10,y10;
  float x3,y3,x4,y4,x9,y9,x11,y11;
  float x6,y6,x7,y7,x8,y8;
  delay(2000);
  while(a>=90)
  { x2=x1+d*cos(a);
    y2=y1+d*sin(a);
    x3=x1+d*cos(a);
    y3=y1+35+(d*sin(a));
    x4=x1+(d+3)*cos(a);
    y4=y1+35+((d+3)*sin(a));
    x5=x1+(d+3)*cos(a);
    y5=y1+(d+3)*sin(a);
    x6=x1+(d+3)*cos(a);
    y6=(y1+18)+(d+3)*sin(a);
    x7=x1+(d+150)*cos(a);
    y7=(y1+18)+(d+150)*sin(a);
    x8=x1+(d+150)*cos(a);
    y8=(y1+10)+(d+150)*sin(a);
    x9=x1+(d+3)*cos(a);
    y9=(y1+10)+(d+3)*sin(a);
    x10=x1+(d+6)*cos(a);
    y10=(y1+15)+(d+10)*sin(a);
    x11=x1+(d-5)*cos(a);
    y11=(y1+15)+(d-5)*sin(a);
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
//    delay(5);
    setcolor(BLACK);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
    a-=0.0001; }
  while(a<=b)
  { x2=x1+d*cos(a);
    y2=y1+d*sin(a);
    x3=x1+d*cos(a);
    y3=y1+35+(d*sin(a));
    x4=x1+(d+3)*cos(a);
    y4=y1+35+((d+3)*sin(a));
    x5=x1+(d+3)*cos(a);
    y5=y1+(d+3)*sin(a);
    x6=x1+(d+3)*cos(a);
    y6=(y1+18)+(d+3)*sin(a);
    x7=x1+(d+150)*cos(a);
    y7=(y1+18)+(d+150)*sin(a);
    x8=x1+(d+150)*cos(a);
    y8=(y1+10)+(d+150)*sin(a);
    x9=x1+(d+3)*cos(a);
    y9=(y1+10)+(d+3)*sin(a);
    x10=x1+(d+6)*cos(a);
    y10=(y1+15)+(d+10)*sin(a);
    x11=x1+(d-5)*cos(a);
    y11=(y1+15)+(d-5)*sin(a);
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
//    delay(5);
    setcolor(BLACK);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
    a+=0.0001;
    x2=x1+d*cos(a);
    y2=y1+d*sin(a);
    x3=x1+d*cos(a);
    y3=y1+35+(d*sin(a));
    x4=x1+(d+3)*cos(a);
    y4=y1+35+((d+3)*sin(a));
    x5=x1+(d+3)*cos(a);
    y5=y1+(d+3)*sin(a);
    x6=x1+(d+3)*cos(a);
    y6=(y1+18)+(d+3)*sin(a);
    x7=x1+(d+150)*cos(a);
    y7=(y1+18)+(d+150)*sin(a);
    x8=x1+(d+150)*cos(a);
    y8=(y1+10)+(d+150)*sin(a);
    x9=x1+(d+3)*cos(a);
    y9=(y1+10)+(d+3)*sin(a);
    x10=x1+(d+6)*cos(a);
    y10=(y1+15)+(d+10)*sin(a);
    x11=x1+(d-5)*cos(a);
    y11=(y1+15)+(d-5)*sin(a);
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
//    delay(5);
    setcolor(BLACK);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
    a+=0.0001;
    x2=x1+d*cos(a);
    y2=y1+d*sin(a);
    x3=x1+d*cos(a);
    y3=y1+35+(d*sin(a));
    x4=x1+(d+3)*cos(a);
    y4=y1+35+((d+3)*sin(a));
    x5=x1+(d+3)*cos(a);
    y5=y1+(d+3)*sin(a);
    x6=x1+(d+3)*cos(a);
    y6=(y1+18)+(d+3)*sin(a);
    x7=x1+(d+150)*cos(a);
    y7=(y1+18)+(d+150)*sin(a);
    x8=x1+(d+150)*cos(a);
    y8=(y1+10)+(d+150)*sin(a);
    x9=x1+(d+3)*cos(a);
    y9=(y1+10)+(d+3)*sin(a);
    x10=x1+(d+6)*cos(a);
    y10=(y1+15)+(d+10)*sin(a);
    x11=x1+(d-5)*cos(a);
    y11=(y1+15)+(d-5)*sin(a);
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
//    delay(5);
    setcolor(BLACK);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
    a+=0.0001; }
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7); }

void king(char name[30])                //  for king
{     fstream file;
      file.open(name,ios::binary|ios::in);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      unsigned color;
      file.read((char*)&color,sizeof(color));
      for(int i=0;i<getmaxx();i++)
       for(int j=0;j<getmaxy();j++)
       { putpixel(i,j,color);
	 file.read((char*)&color,sizeof(color)); }
      putpixel(i,j,color);
      file.close();  }
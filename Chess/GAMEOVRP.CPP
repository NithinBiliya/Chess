//		Game over -- Puzzles

#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>
#include"H:\chess\video.cpp"

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();
 char name[30];
 strcpy(name,"ch pic6");
 king(name);
 strcpy(name,"ch ani1");
 animationvideo(name);
 getch();
}
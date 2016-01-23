//		CREDITS

#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>
#include<string.h>
#include"H:\chess\video.cpp"

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();
 char name[30];
 delay(500);
 strcpy(name,"ch pic8");
 king(name);
 delay(500);
 strcpy(name,"ch pic7");
 king(name);
 delay(500);
 strcpy(name,"ch pic9");
 king(name);
 delay(500);
 strcpy(name,"ch ani2");
 animationvideo(name);
 delay(200);
 strcpy(name,"ch pic10");
 king(name);
 getch();
}
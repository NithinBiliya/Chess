//	HELP

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
#include<math.h>
#include"H:\chess\mouses.cpp"
#include"H:\chess\video.cpp"

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();
 king("ch1");
 int Mstatus = initmouse();
 int button,m,n;
 if(Mstatus == 0 )
  outtextxy(50,50, "Mouse Support Not Available");
 settextstyle(2,0,4);
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
      video(450,150);
      spawnl(P_WAIT,"help.exe", NULL);
      king("ch1"); }  // How to play
    if(m>245 && m<325 && n>240 && n<252)
    { hidemouseptr();
      video(450,150);
      spawnl(P_WAIT,"menu3.exe", NULL); } // Controls
//      exit(0); }
    if(m>245 && m<325 && n>260 && n<272)
    { hidemouseptr();
      video(450,150);
  //    spawnl(P_WAIT,"g:\\exe\\menu1.exe", NULL);  // back to main menu
      break; }}}
}

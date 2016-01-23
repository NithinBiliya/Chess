//	CONTROLS

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
 settextstyle(2,0,4);
 outtextxy(230,130,"KEYBOARD");
 outtextxy(220,150,"Top left  : Q/7");
 outtextxy(220,165,"Top       : W/8");
 outtextxy(220,180,"Top right : E/9");
 outtextxy(220,195,"Left      : A/4");
 outtextxy(220,210,"Right     : D/6");
 outtextxy(220,225,"Bottom left : Z/1");
 outtextxy(220,240,"Bottom    : X/2");
 outtextxy(220,255,"Bottom right: C/3");
 outtextxy(220,270,"Select    : S/5");
 outtextxy(220,285,"Disselect : S/5");
 outtextxy(220,300,"Main menu : M");
 if(Mstatus == 0 )
  outtextxy(50,50, "Mouse Support Not Available");
 while(!kbhit())
{ showmouseptr();
  getmousepos(&button,&m,&n);
  if(m>245 && m<325 && n>320 && n<332)
  { setcolor(RED);
    outtextxy(250,320,"BACK"); }
  else
  { setcolor(WHITE);
    outtextxy(250,320,"BACK"); }
  if(button == 1)
  { if(m>245 && m<325 && n>320 && n<332)
    { hidemouseptr();
      video(450,150);
      break;  }}}}
//      spawnl(P_WAIT,"g:\\exe\\menu2.exe", NULL);  // back to help menu
//      exit(0);	}}}}

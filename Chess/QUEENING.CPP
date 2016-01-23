//     Queening of a pawn

#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<graphics.h>
#include<conio.h>
#include"F:\c__~1\chess\mouses.cpp"
#include"F:\chess\function.cpp"

void main()
{
 int gdriver = DETECT, gmode, errorcode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();

 settextstyle(1,0,1);
 setbkcolor(RED);
 setfillstyle(SOLID_FILL,BLUE);
 bar(180,150,220+43*3+70,323);
 outtextxy(220,180,"SELECT YOUR COIN");
 rook(220,230,black);
 knight(220+43,230,black);
 bishop(220+43*2,230,black);
 queen(220+43*3,230,black);

 int Mstatus = initmouse();
 int button,m,n;
 if(Mstatus == 0 )
  outtextxy(50,50, "Mouse Support Not Available");
// changecursor(cursor);
 while(!kbhit())
{ showmouseptr();
  getmousepos(&button,&m,&n);
  if(m>220 && m<220+42 && n>230 && n<230+43)
   rook(220,230,null);
  else
   rook(220,230,black);
  if(m>220+43 && m<220+43*2-1 && n>230 && n<230+43)
   knight(220+43,230,null);
  else
   knight(220+43,230,black);
  if(m>220+43*2 && m<220+43*3-1 && n>230 && n<230+43)
   bishop(220+43*2,230,null);
  else
   bishop(220+43*2,230,black);
  if(m>220+43*3 && m<220+43*4-1 && n>230 && n<230+43)
   queen(220+43*3,230,null);
  else
   queen(220+43*3,230,black);
  if(button == 1)
 {if(m>220 && m<220+42 && n>230 && n<230+43)
   exit(0);
  else if(m>220+43 && m<220+43*2-1 && n>230 && n<230+43)
   exit(0);
  else if(m>220+43*2 && m<220+43*3-1 && n>230 && n<230+43)
   exit(0);
  else if(m>220+43*3 && m<220+43*4-1 && n>230 && n<230+43)
   exit(0);    }}


 getch();
 closegraph();
}


//		2nd screen
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

struct box
{ int x,y;
  char coin;
  int color;
  int occblack;
  int occwhite;  }A[8][8];
int sign;

void createnewfile();

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
    outtextxy(250,220,"PLAYER vs PLAYER"); }
  else
  { setcolor(WHITE);
    outtextxy(250,220,"PLAYER vs PLAYER");
  if(m>245 && m<325 && n>240 && n<252)
  { setcolor(RED);
    outtextxy(250,240,"CHESS PUZZLES");  }
  else
  { setcolor(WHITE);
    outtextxy(250,240,"CHESS PUZZLES");
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
      createnewfile();
      spawnl(P_WAIT,"load.exe", NULL);  // load
      spawnl(P_WAIT,"chess.exe", NULL);  // player vs player
      cleardevice();
      king("ch1"); }
    if(m>245 && m<325 && n>240 && n<252)
    { hidemouseptr();
      video(450,150);
      spawnl(P_WAIT,"menu6.exe", NULL); } // chess puzzles menu
//      exit(0); }
    if(m>245 && m<325 && n>260 && n<272)
    { hidemouseptr();
      video(450,150);
//      spawnl(P_WAIT,"g:\\exe\\menu1.exe", NULL);  // back to main menu
      break; }}}}

void createnewfile()
{   fstream f1,f2;
    f1.open("NEWFILE.txt",ios::in|ios::binary);
    if(!f1)
     outtextxy(10,10,"Couldnt open");
    f2.open("temp.txt",ios::out|ios::binary);
    if(!f2)
     outtextxy(10,10,"Couldnt open");
    f1.read((char*)&A,sizeof(A));
    f1.read((char*)&sign,sizeof(sign));
    f2.write((char*)&A,sizeof(A));
    f2.write((char*)&sign,sizeof(sign));
    f1.close();
    f2.close();
    remove("slot0.txt");
    rename("NEWFILE.txt","slot0.txt");
    rename("temp.txt","NEWFILE.txt"); }
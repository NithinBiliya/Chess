//		LOADING

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
#include<string.h>
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

void loadgame(int);

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();
 king("ch1");
 int Mstatus = initmouse();
 int button,m,n,slot;
 settextstyle(2,0,4);
 outtextxy(230,130,"LOADING");
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
    outtextxy(250,320,"BACK");
  if(m>215 && m<300 && n>164 && n<177)
  { setcolor(RED);
    outtextxy(220,165,"Slot 1"); }
  else
  { setcolor(WHITE);
    outtextxy(220,165,"Slot 1");
  if(m>215 && m<300 && n>179 && n<192)
  { setcolor(RED);
    outtextxy(220,180,"Slot 2"); }
  else
  { setcolor(WHITE);
    outtextxy(220,180,"Slot 2");
  if(m>215 && m<300 && n>194 && n<207)
  { setcolor(RED);
    outtextxy(220,195,"Slot 3"); }
  else
  { setcolor(WHITE);
    outtextxy(220,195,"Slot 3");
  if(m>215 && m<300 && n>209 && n<222)
  { setcolor(RED);
    outtextxy(220,210,"Slot 4"); }
  else
  { setcolor(WHITE);
    outtextxy(220,210,"Slot 4");

  if(m>215 && m<300 && n>224 && n<237)
  { setcolor(RED);
    outtextxy(220,225,"Slot 5"); }
  else
  { setcolor(WHITE);
    outtextxy(220,225,"Slot 5");

  if(m>215 && m<300 && n>239 && n<252)
  { setcolor(RED);
    outtextxy(220,240,"Slot 6"); }
  else
  { setcolor(WHITE);
    outtextxy(220,240,"Slot 6");

  if(m>215 && m<300 && n>254 && n<267)
  { setcolor(RED);
    outtextxy(220,255,"Slot 7"); }
  else
  { setcolor(WHITE);
    outtextxy(220,255,"Slot 7");

  if(m>215 && m<300 && n>269 && n<282)
  { setcolor(RED);
    outtextxy(220,270,"Slot 8"); }
  else
  { setcolor(WHITE);
    outtextxy(220,270,"Slot 8");

  if(m>215 && m<300 && n>284 && n<297)
  { setcolor(RED);
    outtextxy(220,285,"Slot 9"); }
  else
  { setcolor(WHITE);
    outtextxy(220,285,"Slot 9");

  if(m>215 && m<300 && n>299 && n<312)
  { setcolor(RED);
    outtextxy(220,300,"Slot 10"); }
  else
  { setcolor(WHITE);
    outtextxy(220,300,"Slot 10");
  }}}}}}}}}}}
  if(button == 1)
  { if(m>245 && m<325 && n>320 && n<332)
    { hidemouseptr();
      video(450,150);
//      spawnl(P_WAIT,"g:\\exe\\menu1.exe", NULL);  // back to main menu
      break;  }
    if(m>215 && m<300 && n>164 && n<177)
    { hidemouseptr();
      video(450,150);
      slot=1;
      loadgame(slot);  }
  if(m>215 && m<300 && n>179 && n<192)
  { hidemouseptr();
      video(450,150);
      slot=2;
      loadgame(slot);  }
  if(m>215 && m<300 && n>194 && n<207)
  { hidemouseptr();
      video(450,150);
      slot=3;
      loadgame(slot);  }
  if(m>215 && m<300 && n>209 && n<222)
  { hidemouseptr();
      video(450,150);
      slot=4;
      loadgame(slot); }
  if(m>215 && m<300 && n>224 && n<237)
  { hidemouseptr();
      video(450,150);
      slot=5;
      loadgame(slot);}
  if(m>215 && m<300 && n>239 && n<252)
  {hidemouseptr();
      video(450,150);
      slot=6;
      loadgame(slot);}
  if(m>215 && m<300 && n>254 && n<267)
  {hidemouseptr();
      video(450,150);
      slot=7;
      loadgame(slot);}
  if(m>215 && m<300 && n>269 && n<282)
  {hidemouseptr();
      video(450,150);
      slot=8;
      loadgame(slot);}
  if(m>215 && m<300 && n>284 && n<297)
  {hidemouseptr();
      video(450,150);
      slot=9;
      loadgame(slot);}
  if(m>215 && m<300 && n>299 && n<312)
  {hidemouseptr();
      video(450,150);
      slot=10;
      loadgame(slot);}}}}

void loadgame(int slot)
{ char name[30];
  switch(slot)
  { case 1:strcpy(name,"slot1.txt");
	   break;
    case 2:strcpy(name,"slot2.txt");
	   break;
    case 3:strcpy(name,"slot3.txt");
	   break;
    case 4:strcpy(name,"slot4.txt");
	   break;
    case 5:strcpy(name,"slot5.txt");
	   break;
    case 6:strcpy(name,"slot6.txt");
	   break;
    case 7:strcpy(name,"slot7.txt");
	   break;
    case 8:strcpy(name,"slot8.txt");
	   break;
    case 9:strcpy(name,"slot9.txt");
	   break;
    case 10:strcpy(name,"slot10.txt");
	   break; }
    fstream f1,f2;
    f1.open(name,ios::in|ios::binary);
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
    rename(name,"slot0.txt");
    rename("temp.txt",name);
    outtextxy(220,150,"DONE"); }
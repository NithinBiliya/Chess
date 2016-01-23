//	inside chess puzzles

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
#include<math.h>
#include<string.h>
#include"H:\chess\mouses.cpp"
#include"H:\chess\video.cpp"

void jumptolev(char [30]);

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
    outtextxy(250,220,"START"); }
  else
  { setcolor(WHITE);
    outtextxy(250,220,"START");
  if(m>245 && m<325 && n>240 && n<252)
  { setcolor(RED);
    outtextxy(250,240,"PASSWORD");  }
  else
  { setcolor(WHITE);
    outtextxy(250,240,"PASSWORD");
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
      int level=1;
      fstream file;
      file.open("levels.txt",ios::binary|ios::out);
      if(!file)
       cout<<"Couldnt open the file";
      file.write((char*)&level,sizeof(level));
      file.close();
      spawnl(P_WAIT,"load.exe", NULL);  // load
      spawnl(P_WAIT,"puzzle.exe", NULL);  // Start the puzzles
      cleardevice();
      king("ch1"); }
    if(m>245 && m<325 && n>240 && n<252)
    { hidemouseptr();
      video(450,150);
      char text[30];
      outtextxy(235,200,"Enter password");
      for(int k=0;k<20;k++)
      { text[k]=getch();
	if(text[k]=='\r')
	{ text[k]='\0';
	  break; }
	text[k+1]='\0';
	outtextxy(250,250,text); }
      jumptolev(text); }
    if(m>245 && m<325 && n>260 && n<272)
    { hidemouseptr();
      video(450,150);
  //    spawnl(P_WAIT,"g:\\exe\\menu1.exe", NULL);  // back to sec. main menu
      break; }}}
}

void jumptolev(char cheat[30])
{ int level=0;
  if(!strcmp(cheat,"krashnaw"))
   level=1;
  else if(!strcmp(cheat,"leastwanted"))
   level=2;
  else if(!strcmp(cheat,"tendlekar"))
   level=3;
  else if(!strcmp(cheat,"thendela"))
   level=4;
  else if(!strcmp(cheat,"tribal"))
   level=5;
  else if(!strcmp(cheat,"chinchan"))
   level=6;
  else if(!strcmp(cheat,"lemonjuice"))
   level=7;
  else if(!strcmp(cheat,"meooow"))
   level=8;
  else if(!strcmp(cheat,"bowie"))
   level=9;
  else if(!strcmp(cheat,"shetre"))
   level=10;
  else if(!strcmp(cheat,"overloaded"))
   level=11;
  else if(!strcmp(cheat,"watboy?"))
   level=12;
  else if(!strcmp(cheat,"theyatheya"))
   level=13;
  else if(!strcmp(cheat,"goymare"))
   level=14;
  else if(!strcmp(cheat,"cummon"))
   level=15;
  if(level!=0)
  { cout<<level;
    fstream file;
    file.open("levels.txt",ios::binary|ios::out);
    if(!file)
     cout<<"Couldnt open the file";
    file.write((char*)&level,sizeof(level));
    file.close();
    spawnl(P_WAIT,"load.exe", NULL);  // load
    spawnl(P_WAIT,"puzzle.exe", NULL);  // Start the puzzles
    cleardevice();
    king("ch1"); }
  else
  { outtextxy(230,270,"Wrong Password !!");
    video(450,150); }}
//	How To Play -- Help

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
#include<math.h>
#include"H:\chess\mouses.cpp"

enum{ null=-1,black,white };
enum{ yes,no };

struct box
{ int x,y;
  char coin;
  int color;
  int occblack;
  int occwhite;  };
box A[8][8];
fstream file;
int x,y;

void typeon();
void setvalues();
void board();
void coins();
void pawn(int,int,int);
void rook(int,int,int);
void bishop(int,int,int);
void knight(int,int,int);
void king(int,int,int);
void queen(int,int,int);
void pic(char[30]);


void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();
// char str[1]; str[1]='\0';
 file.open("Info.TXT",ios::in|ios::binary);
 if(!file)
  cout<<"File couldnt be opened";
 x=20; y=getmaxy()-70;
 settextstyle(2,0,5);
 setvalues();
 board();
 coins();
 getch();
 typeon();
 getch();
 cleardevice();
 x=20; y=200;
 pic("ch pic");
 typeon();
 y+=20;
 typeon();
 getch();
 cleardevice();
 pic("ch pic2");
 x=20; y=200;
 typeon();
 getch();
 cleardevice();
 king(getmaxx()/2-30,30,1);
 x=20; y=100;
 typeon();
 getch();
 cleardevice();
 rook(getmaxx()/2-30,30,1);
 x=20; y=100;
 typeon();
 getch();
 cleardevice();
 bishop(getmaxx()/2-30,30,1);
 x=20; y=100;
 typeon();
 getch();
 cleardevice();
 queen(getmaxx()/2-30,30,1);
 x=20; y=100;
 typeon();
 getch();
 cleardevice();
 knight(getmaxx()/2-30,30,1);
 x=20; y=100;
 typeon();
 getch();
 cleardevice();
 pawn(getmaxx()/2-30,30,1);
 x=20; y=100;
 typeon();
 getch();
 cleardevice();
 pic("ch pic3");
 x=20; y=50;
 typeon();
 getch();
 file.close();
 closegraph();
}

void typeon()
{ char str[1]; str[1]='\0';
  file.get(str[0]);
  while(!file.eof())
  { if(str[0]=='*')
     break;
    if(str[0]=='\n')
    { y+=20; x=10; }
    outtextxy(x,y,str);
    delay(50);
    file.get(str[0]);
    x+=8; }}


void pic(char name[30])                //  for picture
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

void setvalues()                     // set initial values
{ for(int i=0,n=0;i<8;i++,n+=43)
   for(int j=0,m=0;j<8;j++,m+=43)
   { A[i][j].x=150+m;
     A[i][j].y=60+n; }
  A[0][0].coin='R';
  A[0][1].coin='H';
  A[0][2].coin='B';
  A[0][3].coin='K';
  A[0][4].coin='Q';
  A[0][5].coin='B';
  A[0][6].coin='H';
  A[0][7].coin='R';
  A[7][0].coin='R';
  A[7][1].coin='H';
  A[7][2].coin='B';
  A[7][3].coin='K';
  A[7][4].coin='Q';
  A[7][5].coin='B';
  A[7][6].coin='H';
  A[7][7].coin='R';
  for(i=0;i<8;i++)
   for(j=0;j<8;j++)
   { if(i==0 || i==1)
      A[i][j].color=black;
     if(i>1 && i<6)
     { A[i][j].color=null;
       A[i][j].coin='N'; }
     if(i==6 || i==7)
      A[i][j].color=white;
     if(i==1 || i==6)
      A[i][j].coin='P';  }}

void board()                                // draw board
{ setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  int box[30];
  for(int i=0;i<=9;i++)
   if(i%2==0)
    box[i]=150;
   else
    box[i]=60;
  setcolor(WHITE);
  int sign=-1;
  while(box[1]<=400)
  { box[3]=box[1];
    box[5]=box[7];
    box[1]+=43;
    box[7]=box[1];
    box[9]=box[1];
    box[0]=box[2]=box[4]=150;
    while(box[4]<=490)
    { box[2]=box[4];
      box[8]=box[0];
      box[4]+=43;
      box[6]=box[4];
      if(sign<0)
       setfillstyle(SOLID_FILL,LIGHTGRAY);
      else
       setfillstyle(SOLID_FILL,DARKGRAY);
      fillpoly(5,box);
      box[0]=box[6];
      sign*=-1; }
    sign*=-1;  }}

void coins()                            // draw coins
{ for(int i=0;i<8;i++)
   for(int j=0;j<8;j++)
   { if(A[i][j].coin=='R')
      rook(A[i][j].x,A[i][j].y,A[i][j].color);
     if(A[i][j].coin=='H')
      knight(A[i][j].x,A[i][j].y,A[i][j].color);
     if(A[i][j].coin=='B')
      bishop(A[i][j].x,A[i][j].y,A[i][j].color);
     if(A[i][j].coin=='K')
      king(A[i][j].x,A[i][j].y,A[i][j].color);
     if(A[i][j].coin=='Q')
      queen(A[i][j].x,A[i][j].y,A[i][j].color);
     if(A[i][j].coin=='P')
      pawn(A[i][j].x,A[i][j].y,A[i][j].color);  }}

void pawn(int x,int y,int z)
{ moveto(x,y);
  if(z==0)
   setcolor(BLACK);
  else if(z==1)
   setcolor(WHITE);
  else if(z==-1)
   setcolor(RED);
  setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  x+=21;  y+=13;
  circle(x,y,5);
  line(x-2,y+2,x-4,y+17);
  line(x+2,y+2,x+4,y+17);
  y+=17;
  rectangle(x-10,y,x+10,y+5);  }

void rook(int x,int y,int z)
{ moveto(x,y);
  if(z==0)
   setcolor(BLACK);
  else if(z==1)
   setcolor(WHITE);
  else if(z==-1)
   setcolor(RED);
  setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  x+=10;  y+=10;
  rectangle(x,y-5,x+4,y);
  rectangle(x+17,y-5,x+21,y);
  rectangle(x+8,y-5,x+12,y);
  rectangle(x-4,y+5,x+25,y);
  line(x+1,y+7,x+1,y+20);
  line(x+20,y+7,x+20,y+20);
  rectangle(x-4,y+20,x+25,y+28);   }

void bishop(int x,int y,int z)
{ moveto(x,y);
  if(z==0)
   setcolor(BLACK);
  else if(z==1)
   setcolor(WHITE);
  else if(z==-1)
   setcolor(RED);
  setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  x+=21;  y+=5;
  circle(x,y,2);
  y+=8;
  arc(x,y,315,225,6);
  rectangle(x-10,y+5,x+9,y+3);
  line(x-4,y+2,x-6,y+17);
  line(x+4,y+2,x+6,y+17);
  rectangle(x-12,y+17,x+12,y+23);  }

void knight(int x,int y,int z)
{ moveto(x,y);
  if(z==0)
   setcolor(BLACK);
  else if(z==1)
   setcolor(WHITE);
  else if(z==-1)
   setcolor(RED);
  setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  x+=20;  y+=20;
  arc(x,y,45,200,15);
  arc(x+5,y+5,60,180,15);
  line(x-10,y+7,x-15,y+7);
  line(x-15,y+7,x+5,y+7);
  line(x+5,y+7,x+5,y+3);
  line(x+5,y+3,x+10,y+5);
  line(x+10,y+5,x+15,y);
  line(x+15,y,x+12,y-7);
  line(x-10,y+5,x-15,y+15);
  line(x-15,y+15,x+7,y+15);
  line(x+7,y+15,x+3,y+5);
  circle(x+7,y-5,1);  }

void king(int x,int y,int z)
{ moveto(x,y);
  if(z==0)
   setcolor(BLACK);
  else if(z==1)
   setcolor(WHITE);
  else if(z==-1)
   setcolor(RED);
  setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  x+=10;  y+=10;
  rectangle(x-4,y+7,x+25,y+2);
  line(x+1,y+7,x-2,y+20);
  line(x+20,y+7,x+23,y+20);
  rectangle(x-7,y+22,x+28,y+28);
  line(x+10,y-8,x+10,y);
  line(x+2,y-4,x+18,y-4);  }

void queen(int x,int y,int z)
{ moveto(x,y);
  if(z==0)
   setcolor(BLACK);
  else if(z==1)
   setcolor(WHITE);
  else if(z==-1)
   setcolor(RED);
  setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  x+=10;  y+=10;
  rectangle(x-4,y+7,x+25,y+2);
  line(x+1,y+7,x-2,y+20);
  line(x+20,y+7,x+23,y+20);
  rectangle(x-7,y+22,x+28,y+28);
  circle(x+8,y-1,3);
  circle(x+13,y-1,3);
  circle(x+11,y-6,3);  }

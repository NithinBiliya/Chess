//	       First level

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>
#include"F:\chess\load.cpp"
#include"F:\chess\mouses.cpp"
#include"F:\chess\function.cpp"
#include"F:\chess\1stpg.cpp"

void select(int&,int&);
//	white to play and win in three moves !!!
 char s='9';
void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");

 setlinestyle(SOLID_LINE,0,THICK_WIDTH);
 board();
// setvalues();
 {
 for(int i=0,n=0;i<8;i++,n+=43)
  for(int j=0,m=0;j<8;j++,m+=43)
  { A[i][j].x=150+m;
    A[i][j].y=60+n; }}
 A[0][6].color=white;
 A[0][6].coin='B';
 A[1][3].color=black;
 A[1][3].coin='R';
 A[1][4].color=black;
 A[1][4].coin='R';
 A[2][0].color=white;
 A[2][0].coin='Q';
 A[2][4].color=black;
 A[2][4].coin='P';
 A[3][0].color=black;
 A[3][0].coin='P';
 A[3][2].color=black;
 A[3][2].coin='P';
 A[3][3].color=black;
 A[3][3].coin='K';
 A[4][5].color=white;
 A[4][5].coin='B';
 A[5][3].color=white;
 A[5][3].coin='K';
 A[5][7].color=black;
 A[5][7].coin='P';


 coins();

 int i=7,j=0,c;
 setcolor(RED);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
 while(1)
 {
  if(select(i,j)=='5')
  { if(i==4&&j==5)
    { settextstyle(2,0,4);
      outtextxy(10,getmaxy()-15,"It is black chance to play !!");  }
    if(A[i][j].color!=c && c==white)
    { settextstyle(2,0,4);
      outtextxy(10,getmaxy()-15,"It is white chance to play !!");  }
    if(A[i][j].coin=='P' && A[i][j].color==c)
     PAWN(i,j);
    if(A[i][j].coin=='R' && A[i][j].color==c)
     ROOK(i,j);
    if(A[i][j].coin=='H' && A[i][j].color==c)
     KNIGHT(i,j);
    if(A[i][j].coin=='B' && A[i][j].color==c)
     BISHOP(i,j);
    if(A[i][j].coin=='Q' && A[i][j].color==c)
     QUEEN(i,j);
    if(A[i][j].coin=='K' && A[i][j].color==c)
     KING(i,j);
    setcolor(RED);
    rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);     }}

char select(int& i,int& j)
{ s=getch();
  setcolor(WHITE);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  if(s=='0')
   exit(0);
  if(s=='8')
   i--;
  if(s=='2')
   i++;
  if(s=='4')
   j--;
  if(s=='6')
   j++;
  if(i==-1 && s=='8')
   i++;
  if(i==8 && s=='2')
   i--;
  if(j==-1 && s=='4')
   j++;
  if(j==8 && s=='6')
   j--;
  setcolor(RED);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  setfillstyle(SOLID_FILL,WHITE);
  bar(0,getmaxy()-15,getmaxx(),getmaxy());
  return s;	}





 getch();
 closegraph();
}
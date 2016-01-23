//	Chess Puzzles

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
#include"H:\chess\fnx.cpp"

class GAME
{ unsigned level;
  unsigned lives;
  public :
  GAME()
  { level=1;
    lives=3; }
  ~GAME()
  {  }
  friend void main();
  void level1();
  void level2();
  void level3();
  void level4();
  void level5();
  void level6();
  void level7();
  void level8();
  void level9();
  void level10();
  void level11();
  void level12();
  void level13();
  void level14();
  void level15();
  int common();
  void change(int,int,int,int); }game;

void drawextra(unsigned,unsigned);

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 fstream file;
 file.open("levels.txt",ios::binary|ios::in);
 if(!file)
  cout<<"Couldnt open the file";
 file.read((char*)&game.level,sizeof(game.level));
 file.close();
 cleardevice();
 while(game.level<16)
 { if(game.level==1)
   { game.level1();
     drawextra(game.level,game.lives); }
   else if(game.level==2)
   { game.level2();
     drawextra(game.level,game.lives); }
   else if(game.level==3)
   { game.level3();
     drawextra(game.level,game.lives); }
   else if(game.level==4)
   { game.level4();
     drawextra(game.level,game.lives); }
   else if(game.level==5)
   { game.level5();
     drawextra(game.level,game.lives); }
   else if(game.level==6)
   { game.level6();
     drawextra(game.level,game.lives); }
   else if(game.level==7)
   { game.level7();
     drawextra(game.level,game.lives); }
   else if(game.level==8)
   { game.level8();
     drawextra(game.level,game.lives); }
   else if(game.level==9)
   { game.level9();
     drawextra(game.level,game.lives); }
   else if(game.level==10)
   { game.level10();
     drawextra(game.level,game.lives); }
   else if(game.level==11)
   { game.level11();
     drawextra(game.level,game.lives); }
   else if(game.level==12)
   { game.level12();
     drawextra(game.level,game.lives); }
   else if(game.level==13)
   { game.level13();
     drawextra(game.level,game.lives); }
   else if(game.level==14)
   { game.level14();
     drawextra(game.level,game.lives); }
   else if(game.level==15)
   { game.level15();
     drawextra(game.level,game.lives); }
   game.common(); }
 if(game.level==16)
 { spawnl(P_WAIT,"winpuzzl.exe",NULL);
   cleardevice();
   exit(0); }
 closegraph();
}

void drawextra(unsigned level,unsigned lives)
{ cleardevice();
  board(); coins();
  settextstyle(3,0,1);
  setcolor(LIGHTGRAY);
  outtextxy(60,10,"LEVEL : ");
  outtextxy(350,10,"PASSWORD : ");
  outtextxy(200,10,"LIVES : ");
  switch(level)
  { case 1: outtextxy(140,10,"1");
	    outtextxy(480,10,"krashnaw");
	    break;
    case 2: outtextxy(140,10,"2");
	    outtextxy(480,10,"leastwanted");
	    break;
    case 3: outtextxy(140,10,"3");
	    outtextxy(480,10,"tendlekar");
	    break;
    case 4: outtextxy(140,10,"4");
	    outtextxy(480,10,"thendela");
	    break;
    case 5: outtextxy(140,10,"5");
	    outtextxy(480,10,"tribal");
	    break;
    case 6: outtextxy(140,10,"6");
	    outtextxy(480,10,"chinchan");
	    break;
    case 7: outtextxy(140,10,"7");
	    outtextxy(480,10,"lemonjuice");
	    break;
    case 8: outtextxy(140,10,"8");
	    outtextxy(480,10,"meooow");
	    break;
    case 9: outtextxy(140,10,"9");
	    outtextxy(480,10,"bowie");
	    break;
    case 10: outtextxy(140,10,"10");
	     outtextxy(480,10,"shetre");
	     break;
    case 11: outtextxy(140,10,"11");
	     outtextxy(480,10,"overloaded");
	     break;
    case 12: outtextxy(140,10,"12");
	     outtextxy(480,10,"watboy?");
	     break;
    case 13: outtextxy(140,10,"13");
	     outtextxy(480,10,"theyatheya");
	     break;
    case 14: outtextxy(140,10,"14");
	     outtextxy(480,10,"goymare");
	     break;
    case 15: outtextxy(140,10,"15");
	     outtextxy(480,10,"cummon");
	     break; }
  switch(lives)
  { case 0: outtextxy(270,10,"0");
	    break;
    case 1: outtextxy(270,10,"1");
	    break;
    case 2: outtextxy(270,10,"2");
	    break;
    case 3: outtextxy(270,10,"3");
	    break;  }}


int GAME :: common()
{  board();
   coins();
   char s;
   int i=7,j=0;
 while(1)
{ setcolor(RED);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  s=getch();
  setcolor(WHITE);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  getpos(i,j,s);
  redraw();
  setcolor(RED);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  setfillstyle(SOLID_FILL,WHITE);
  bar(0,getmaxy()-15,getmaxx(),getmaxy());
  settextstyle(2,0,4);
  outtextxy(10,getmaxy()-15,"White to play and mate in 1 move ...");
  if(s=='5')
  { if(A[i][j].color==null)
    { setfillstyle(SOLID_FILL,WHITE);
      bar(0,getmaxy()-15,getmaxx(),getmaxy());
      settextstyle(2,0,4);
      outtextxy(10,getmaxy()-15,"Select a coin to make a move !!");  }
    else if(A[i][j].color==black)
    { setfillstyle(SOLID_FILL,WHITE);
      bar(0,getmaxy()-15,getmaxx(),getmaxy());
      settextstyle(2,0,4);
      outtextxy(10,getmaxy()-15,"It is white chance to play !!");  }
    else if(A[i][j].color==white)
    { stop=0;
      setcolor(YELLOW);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
      int p=i,q=j;
      while(stop==0)
     { s=getch();
       setcolor(WHITE);
       rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
       setcolor(YELLOW);
       rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
       getpos(p,q,s);
       setcolor(RED);
       rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
       setfillstyle(SOLID_FILL,WHITE);
       bar(0,getmaxy()-15,getmaxx(),getmaxy());
       settextstyle(2,0,4);
       outtextxy(10,getmaxy()-15,"White to play and mate in 1 move ...");
  if(s=='5')
  { if(level==1 && i==1 && j==5 &&
       A[i][j].coin=='R' && A[i][j].color==white
       && p==1&&q==2 )
    { change(i,j,p,q);
      return 0; }
    else if(level==2 && i==3&&j==7 && A[i][j].coin=='R'
	    && A[i][j].color==white && p==0&&q==7 )
    { change(i,j,p,q);
      return 0; }
    else if(level==3 && i==6&&j==6 && A[i][j].coin=='B'
	    && A[i][j].color==white && p==3&&q==3 )
    { change(i,j,p,q);
      return 0; }
    else if(level==4 && i==2&&j==4 && A[i][j].coin=='R'
	    && A[i][j].color==white && p==2&&q==7 )
    { change(i,j,p,q);
      return 0; }
    else if(level==5 && i==4&&j==4 && A[i][j].coin=='H'
	    && A[i][j].color==white && p==5&&q==6 )
    { change(i,j,p,q);
      return 0; }
    else if(level==6 && i==0&&j==7 && A[i][j].coin=='Q'
	    && A[i][j].color==white && p==0&&q==4 )
    { change(i,j,p,q);
      return 0; }
    else if(level==7 && i==1&&j==0 && A[i][j].coin=='Q'
	    && A[i][j].color==white && p==5&&q==0 )
    { change(i,j,p,q);
      return 0; }
    else if(level==8 && i==6&&j==3 && A[i][j].coin=='B'
	    && A[i][j].color==white && p==3&&q==6 )
    { change(i,j,p,q);
      return 0; }
    else if(level==9 && i==6&&j==4 && A[i][j].coin=='P'
	    && A[i][j].color==white && p==5&&q==4 )
    { change(i,j,p,q);
      return 0; }
    else if(level==10 && i==4&&j==4 && A[i][j].coin=='H'
	    && A[i][j].color==white && p==2&&q==3 )
    { change(i,j,p,q);
      return 0; }
    else if(level==11 && i==2&&j==6 && A[i][j].coin=='Q'
	    && A[i][j].color==white && p==2&&q==5 )
    { change(i,j,p,q);
      return 0; }
    else if(level==12 && i==3&&j==3 && A[i][j].coin=='H'
	    && A[i][j].color==white && p==1&&q==2 )
    { change(i,j,p,q);
      return 0; }
    else if(level==13 && i==2&&j==7 && A[i][j].coin=='Q'
	    && A[i][j].color==white && p==1&&q==6 )
    { change(i,j,p,q);
      return 0; }
    else if(level==14 && i==3&&j==7 && A[i][j].coin=='Q'
	    && A[i][j].color==white && p==1&&q==5 )
    { change(i,j,p,q);
      return 0; }
    else if(level==15 && i==4&&j==5 && A[i][j].coin=='H'
	    && A[i][j].color==white && p==2&&q==6 )
    { change(i,j,p,q);
      getch();
      return 0; }
    else if(p==i && q==j)
    { setcolor(RED);
      rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
      stop++;  }
    else
    {   setfillstyle(SOLID_FILL,WHITE);
	bar(0,getmaxy()-15,getmaxx(),getmaxy());
	settextstyle(2,0,4);
	outtextxy(10,getmaxy()-15,"Nope ... Try again ... ");
	getch();
	setcolor(WHITE);
	rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
	rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
	stop++;  lives--;
	drawextra(level,lives);
	if(lives==0)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  settextstyle(2,0,4);
	  setcolor(RED);
	  outtextxy(10,getmaxy()-15,"GAME OVER !! ");
	  getch();
	  spawnl(P_WAIT,"gameovrp.exe",NULL);
	  cleardevice();
	  exit(0);  }
	i=p; j=q;  }}}}}}}

void GAME :: change(int i,int j,int p,int q)
{ A[p][q].coin=A[i][j].coin;
  A[p][q].color=A[i][j].color;
  A[i][j].coin='N';
  A[i][j].color=null;
  board();
  coins();
  setfillstyle(SOLID_FILL,WHITE);
  bar(0,getmaxy()-15,getmaxx(),getmaxy());
  settextstyle(2,0,4);
  setcolor(RED);
  outtextxy(10,getmaxy()-15,"Congrats !! You advance to next level !!");
  level++;
  getch(); }

void GAME :: level1()
{  dontsetvalues();
   A[0][7].coin='R';
   A[2][7].coin='P';
   A[2][3].coin='P';
   A[2][2].coin='K';
   A[3][1].coin='Q';
   A[4][2].coin='H';
   A[5][7].coin='P';
   A[6][2].coin='B';
   A[0][7].color=black;
   A[2][7].color=black;
   A[2][3].color=black;
   A[2][2].color=black;
   A[3][1].color=black;
   A[4][2].color=black;
   A[5][7].color=black;
   A[6][2].color=black;
   A[0][6].coin='Q';
   A[1][5].coin='R';
   A[2][1].coin='P';
   A[3][3].coin='H';
   A[3][4].coin='B';
   A[3][6].coin='P';
   A[5][6].coin='P';
   A[7][5].coin='K';
   A[0][6].color=white;
   A[1][5].color=white;
   A[2][1].color=white;
   A[3][3].color=white;
   A[3][4].color=white;
   A[3][6].color=white;
   A[5][6].color=white;
   A[7][5].color=white;  }

void GAME :: level2()
{  dontsetvalues();
   A[0][5].coin='K';
   A[1][5].coin='P';
   A[3][0].coin='Q';
   A[3][1].coin='P';
   A[4][2].coin='R';
   A[4][5].coin='P';
   A[6][4].coin='H';
   A[6][7].coin='B';
   A[0][5].color=black;
   A[1][5].color=black;
   A[3][0].color=black;
   A[3][1].color=black;
   A[4][2].color=black;
   A[4][5].color=black;
   A[6][4].color=black;
   A[6][7].color=black;
   A[0][4].coin='H';
   A[1][2].coin='P';
   A[2][6].coin='B';
   A[3][7].coin='R';
   A[4][1].coin='P';
   A[4][4].coin='Q';
   A[5][7].coin='K';
   A[6][1].coin='P';
   A[0][4].color=white;
   A[1][2].color=white;
   A[2][6].color=white;
   A[3][7].color=white;
   A[4][1].color=white;
   A[4][4].color=white;
   A[5][7].color=white;
   A[6][1].color=white;  }

void GAME :: level3()
{ dontsetvalues();
   A[0][1].coin='R';
   A[0][4].coin='B';
   A[1][5].coin='K';
   A[1][6].coin='P';
   A[4][0].coin='H';
   A[4][5].coin='Q';
   A[5][3].coin='P';
   A[6][0].coin='P';
   A[0][1].color=black;
   A[0][4].color=black;
   A[1][5].color=black;
   A[1][6].color=black;
   A[4][0].color=black;
   A[4][5].color=black;
   A[5][3].color=black;
   A[6][0].color=black;
   A[1][2].coin='H';
   A[3][1].coin='P';
   A[3][6].coin='P';
   A[3][7].coin='P';
   A[5][0].coin='Q';
   A[5][4].coin='R';
   A[6][6].coin='B';
   A[7][4].coin='K';
   A[1][2].color=white;
   A[3][1].color=white;
   A[3][6].color=white;
   A[3][7].color=white;
   A[5][0].color=white;
   A[5][4].color=white;
   A[6][6].color=white;
   A[7][4].color=white;  }

void GAME :: level4()
{ dontsetvalues();
   A[0][5].coin='H';
   A[2][1].coin='P';
   A[2][7].coin='R';
   A[3][7].coin='K';
   A[4][4].coin='B';
   A[5][0].coin='P';
   A[5][2].coin='Q';
   A[6][5].coin='P';
   A[0][5].color=black;
   A[2][1].color=black;
   A[2][7].color=black;
   A[3][7].color=black;
   A[4][4].color=black;
   A[5][0].color=black;
   A[5][2].color=black;
   A[6][5].color=black;
   A[1][4].coin='B';
   A[2][4].coin='R';
   A[3][0].coin='Q';
   A[3][6].coin='P';
   A[4][5].coin='P';
   A[4][7].coin='P';
   A[5][4].coin='H';
   A[6][7].coin='K';
   A[1][4].color=white;
   A[2][4].color=white;
   A[3][0].color=white;
   A[3][6].color=white;
   A[4][5].color=white;
   A[4][7].color=white;
   A[5][4].color=white;
   A[6][7].color=white;  }

void GAME :: level5()
{ dontsetvalues();
   A[0][0].coin='R';
   A[0][1].coin='B';
   A[0][6].coin='Q';
   A[3][5].coin='K';
   A[3][6].coin='P';
   A[5][0].coin='P';
   A[5][6].coin='H';
   A[6][3].coin='P';
   A[0][0].color=black;
   A[0][1].color=black;
   A[0][6].color=black;
   A[3][5].color=black;
   A[3][6].color=black;
   A[5][0].color=black;
   A[5][6].color=black;
   A[6][3].color=black;
   A[1][2].coin='Q';
   A[2][1].coin='P';
   A[2][2].coin='R';
   A[2][7].coin='P';
   A[4][1].coin='K';
   A[4][4].coin='H';
   A[5][4].coin='B';
   A[5][7].coin='P';
   A[1][2].color=white;
   A[2][1].color=white;
   A[2][2].color=white;
   A[2][7].color=white;
   A[4][1].color=white;
   A[4][4].color=white;
   A[5][4].color=white;
   A[5][7].color=white;  }

void GAME :: level6()
{ dontsetvalues();
   A[1][4].coin='K';
   A[2][4].coin='B';
   A[4][1].coin='R';
   A[4][2].coin='Q';
   A[4][5].coin='P';
   A[5][0].coin='H';
   A[5][7].coin='P';
   A[6][0].coin='R';
   A[1][4].color=black;
   A[2][4].color=black;
   A[4][1].color=black;
   A[4][2].color=black;
   A[4][5].color=black;
   A[5][0].color=black;
   A[5][7].color=black;
   A[6][0].color=black;
   A[0][7].coin='Q';
   A[1][5].coin='P';
   A[2][2].coin='R';
   A[4][0].coin='P';
   A[4][4].coin='H';
   A[5][4].coin='P';
   A[6][7].coin='K';
   A[7][5].coin='B';
   A[0][7].color=white;
   A[1][5].color=white;
   A[2][2].color=white;
   A[4][0].color=white;
   A[4][4].color=white;
   A[5][4].color=white;
   A[6][7].color=white;
   A[7][5].color=white;  }

void GAME :: level7()
{  dontsetvalues();
   A[0][2].coin='R';
   A[0][7].coin='R';
   A[1][2].coin='P';
   A[1][4].coin='K';
   A[1][5].coin='P';
   A[1][6].coin='P';
   A[1][7].coin='P';
   A[2][1].coin='P';
   A[2][4].coin='B';
   A[2][5].coin='Q';
   A[5][4].coin='P';
   A[0][2].color=black;
   A[0][7].color=black;
   A[1][2].color=black;
   A[1][4].color=black;
   A[1][5].color=black;
   A[1][6].color=black;
   A[1][7].color=black;
   A[2][1].color=black;
   A[2][4].color=black;
   A[2][5].color=black;
   A[5][4].color=black;
   A[1][0].coin='Q';
   A[2][2].coin='B';
   A[5][2].coin='H';
   A[6][0].coin='P';
   A[6][1].coin='P';
   A[6][2].coin='P';
   A[6][6].coin='P';
   A[6][7].coin='P';
   A[7][1].coin='K';
   A[7][3].coin='R';
   A[1][0].color=white;
   A[2][2].color=white;
   A[5][2].color=white;
   A[6][0].color=white;
   A[6][1].color=white;
   A[6][2].color=white;
   A[6][6].color=white;
   A[6][7].color=white;
   A[7][1].color=white;
   A[7][3].color=white; }

void GAME :: level8()
{  dontsetvalues();
   A[0][0].coin='R';
   A[0][3].coin='K';
   A[0][4].coin='Q';
   A[0][5].coin='B';
   A[0][7].coin='R';
   A[1][0].coin='P';
   A[1][1].coin='P';
   A[1][2].coin='P';
   A[1][5].coin='P';
   A[1][6].coin='P';
   A[1][7].coin='P';
   A[3][4].coin='P';
   A[6][5].coin='H';
   A[0][0].color=black;
   A[0][3].color=black;
   A[0][4].color=black;
   A[0][5].color=black;
   A[0][7].color=black;
   A[1][0].color=black;
   A[1][1].color=black;
   A[1][2].color=black;
   A[1][5].color=black;
   A[1][6].color=black;
   A[1][7].color=black;
   A[3][4].color=black;
   A[6][5].color=black;
   A[0][2].coin='B';
   A[5][2].coin='H';
   A[6][0].coin='P';
   A[6][1].coin='P';
   A[6][3].coin='B';
   A[6][4].coin='H';
   A[6][6].coin='P';
   A[6][7].coin='P';
   A[7][0].coin='R';
   A[7][1].coin='K';
   A[7][3].coin='Q';
   A[7][5].coin='B';
   A[7][7].coin='R';
   A[0][2].color=white;
   A[5][2].color=white;
   A[6][0].color=white;
   A[6][1].color=white;
   A[6][3].color=white;
   A[6][4].color=white;
   A[6][6].color=white;
   A[6][7].color=white;
   A[7][0].color=white;
   A[7][1].color=white;
   A[7][3].color=white;
   A[7][5].color=white;
   A[7][7].color=white; }

void GAME :: level9()
{  dontsetvalues();
   A[0][0].coin='R';
   A[0][4].coin='Q';
   A[0][5].coin='B';
   A[0][6].coin='H';
   A[0][7].coin='R';
   A[1][1].coin='P';
   A[1][5].coin='P';
   A[1][6].coin='P';
   A[1][7].coin='P';
   A[2][0].coin='P';
   A[2][2].coin='B';
   A[3][1].coin='K';
   A[3][3].coin='P';
   A[4][4].coin='P';
   A[0][0].color=black;
   A[0][4].color=black;
   A[0][5].color=black;
   A[0][6].color=black;
   A[0][7].color=black;
   A[1][1].color=black;
   A[1][5].color=black;
   A[1][6].color=black;
   A[1][7].color=black;
   A[2][0].color=black;
   A[2][2].color=black;
   A[3][1].color=black;
   A[3][3].color=black;
   A[4][4].color=black;
   A[3][0].coin='B';
   A[5][2].coin='Q';
   A[6][1].coin='P';
   A[6][2].coin='P';
   A[6][4].coin='P';
   A[6][5].coin='P';
   A[6][6].coin='P';
   A[6][7].coin='P';
   A[7][0].coin='R';
   A[7][1].coin='H';
   A[7][3].coin='K';
   A[7][5].coin='B';
   A[7][7].coin='R';
   A[3][0].color=white;
   A[5][2].color=white;
   A[6][1].color=white;
   A[6][2].color=white;
   A[6][4].color=white;
   A[6][5].color=white;
   A[6][6].color=white;
   A[6][7].color=white;
   A[7][0].color=white;
   A[7][1].color=white;
   A[7][3].color=white;
   A[7][5].color=white;
   A[7][7].color=white; }

void GAME :: level10()
{  dontsetvalues();
   A[0][0].coin='R';
   A[0][2].coin='B';
   A[0][3].coin='Q';
   A[0][4].coin='K';
   A[0][5].coin='B';
   A[0][7].coin='R';
   A[1][0].coin='P';
   A[1][1].coin='P';
   A[1][3].coin='H';
   A[1][4].coin='P';
   A[1][5].coin='P';
   A[1][6].coin='P';
   A[1][7].coin='P';
   A[2][2].coin='P';
   A[2][5].coin='H';
   A[0][0].color=black;
   A[0][2].color=black;
   A[0][3].color=black;
   A[0][4].color=black;
   A[0][5].color=black;
   A[0][7].color=black;
   A[1][0].color=black;
   A[1][1].color=black;
   A[1][3].color=black;
   A[1][4].color=black;
   A[1][5].color=black;
   A[1][6].color=black;
   A[1][7].color=black;
   A[2][2].color=black;
   A[2][5].color=black;
   A[4][3].coin='P';
   A[4][4].coin='H';
   A[6][0].coin='P';
   A[6][1].coin='P';
   A[6][2].coin='P';
   A[6][4].coin='Q';
   A[6][5].coin='P';
   A[6][6].coin='P';
   A[6][7].coin='P';
   A[7][0].coin='R';
   A[7][2].coin='B';
   A[7][4].coin='K';
   A[7][5].coin='B';
   A[7][6].coin='H';
   A[7][7].coin='R';
   A[4][3].color=white;
   A[4][4].color=white;
   A[6][0].color=white;
   A[6][1].color=white;
   A[6][2].color=white;
   A[6][4].color=white;
   A[6][5].color=white;
   A[6][6].color=white;
   A[6][7].color=white;
   A[7][0].color=white;
   A[7][2].color=white;
   A[7][4].color=white;
   A[7][5].color=white;
   A[7][6].color=white;
   A[7][7].color=white; }

void GAME :: level11()
{  dontsetvalues();
   A[0][4].coin='R';
   A[0][5].coin='K';
   A[0][6].coin='R';
   A[1][0].coin='P';
   A[1][4].coin='P';
   A[1][6].coin='H';
   A[2][1].coin='P';
   A[2][2].coin='P';
   A[2][7].coin='P';
   A[3][6].coin='P';
   A[5][5].coin='P';
   A[5][7].coin='Q';
   A[0][4].color=black;
   A[0][5].color=black;
   A[0][6].color=black;
   A[1][0].color=black;
   A[1][4].color=black;
   A[1][6].color=black;
   A[2][1].color=black;
   A[2][2].color=black;
   A[2][7].color=black;
   A[3][6].color=black;
   A[5][5].color=black;
   A[5][7].color=black;
   A[2][6].coin='Q';
   A[5][0].coin='B';
   A[5][1].coin='P';
   A[5][6].coin='P';
   A[6][0].coin='P';
   A[6][5].coin='P';
   A[6][7].coin='P';
   A[7][5].coin='H';
   A[7][6].coin='K';
   A[2][6].color=white;
   A[5][0].color=white;
   A[5][1].color=white;
   A[5][6].color=white;
   A[6][0].color=white;
   A[6][5].color=white;
   A[6][7].color=white;
   A[7][5].color=white;
   A[7][6].color=white; }

void GAME :: level12()
{  dontsetvalues();
   A[0][0].coin='K';
   A[0][1].coin='B';
   A[1][0].coin='P';
   A[1][1].coin='R';
   A[1][5].coin='P';
   A[2][6].coin='P';
   A[4][1].coin='H';
   A[5][0].coin='Q';
   A[0][0].color=black;
   A[0][1].color=black;
   A[1][0].color=black;
   A[1][1].color=black;
   A[1][5].color=black;
   A[2][6].color=black;
   A[4][1].color=black;
   A[5][0].color=black;
   A[0][7].coin='R';
   A[3][3].coin='H';
   A[4][3].coin='K';
   A[4][5].coin='P';
   A[5][1].coin='P';
   A[5][6].coin='P';
   A[6][3].coin='Q';
   A[6][6].coin='B';
   A[7][1].coin='R';
   A[0][7].color=white;
   A[3][3].color=white;
   A[4][3].color=white;
   A[4][5].color=white;
   A[5][1].color=white;
   A[5][6].color=white;
   A[6][3].color=white;
   A[6][6].color=white;
   A[7][1].color=white; }

void GAME :: level13()
{  dontsetvalues();
   A[0][4].coin='R';
   A[1][1].coin='P';
   A[1][5].coin='K';
   A[2][0].coin='P';
   A[2][4].coin='B';
   A[3][6].coin='P';
   A[5][5].coin='Q';
   A[0][4].color=black;
   A[1][1].color=black;
   A[1][5].color=black;
   A[2][0].color=black;
   A[2][4].color=black;
   A[3][6].color=black;
   A[5][5].color=black;
   A[2][7].coin='Q';
   A[5][0].coin='P';
   A[5][2].coin='B';
   A[6][1].coin='P';
   A[6][2].coin='P';
   A[6][7].coin='P';
   A[7][1].coin='K';
   A[2][7].color=white;
   A[5][0].color=white;
   A[5][2].color=white;
   A[6][1].color=white;
   A[6][2].color=white;
   A[6][7].color=white;
   A[7][1].color=white; }

void GAME :: level14()
{  dontsetvalues();
   A[1][3].coin='K';
   A[2][0].coin='Q';
   A[2][1].coin='P';
   A[2][3].coin='R';
   A[2][7].coin='P';
   A[3][3].coin='P';
   A[3][6].coin='P';
   A[4][0].coin='P';
   A[4][4].coin='B';
   A[1][3].color=black;
   A[2][0].color=black;
   A[2][1].color=black;
   A[2][3].color=black;
   A[2][7].color=black;
   A[3][3].color=black;
   A[3][6].color=black;
   A[4][0].color=black;
   A[4][4].color=black;
   A[0][1].coin='R';
   A[3][7].coin='Q';
   A[4][3].coin='H';
   A[4][0].coin='P';
   A[5][1].coin='P';
   A[5][6].coin='P';
   A[6][0].coin='K';
   A[0][1].color=white;
   A[3][7].color=white;
   A[4][3].color=white;
   A[4][0].color=white;
   A[5][1].color=white;
   A[5][6].color=white;
   A[6][0].color=white; }

void GAME :: level15()
{  dontsetvalues();
   A[0][0].coin='R';
   A[0][4].coin='R';
   A[0][5].coin='K';
   A[0][6].coin='Q';
   A[1][0].coin='P';
   A[1][1].coin='P';
   A[1][2].coin='P';
   A[1][4].coin='B';
   A[1][6].coin='P';
   A[2][2].coin='H';
   A[2][4].coin='B';
   A[2][5].coin='H';
   A[3][3].coin='P';
   A[3][5].coin='P';
   A[0][0].color=black;
   A[0][4].color=black;
   A[0][5].color=black;
   A[0][6].color=black;
   A[1][0].color=black;
   A[1][1].color=black;
   A[1][2].color=black;
   A[1][4].color=black;
   A[1][6].color=black;
   A[2][2].color=black;
   A[2][4].color=black;
   A[2][5].color=black;
   A[3][3].color=black;
   A[3][5].color=black;
   A[3][6].coin='H';
   A[3][7].coin='P';
   A[4][5].coin='H';
   A[5][2].coin='Q';
   A[5][3].coin='P';
   A[5][6].coin='P';
   A[6][0].coin='P';
   A[6][1].coin='P';
   A[6][2].coin='P';
   A[6][4].coin='P';
   A[7][1].coin='K';
   A[7][2].coin='R';
   A[7][5].coin='B';
   A[7][7].coin='R';
   A[3][6].color=white;
   A[3][7].color=white;
   A[4][5].color=white;
   A[5][2].color=white;
   A[5][3].color=white;
   A[5][6].color=white;
   A[6][0].color=white;
   A[6][1].color=white;
   A[6][2].color=white;
   A[6][4].color=white;
   A[7][1].color=white;
   A[7][2].color=white;
   A[7][5].color=white;
   A[7][7].color=white; }
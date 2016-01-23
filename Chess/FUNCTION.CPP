//     Functions

enum{ null=-1,black,white };
enum{ yes,no };
struct box
{ int x,y;
  char coin;
  int color;
  int occblack;
  int occwhite;  }A[8][8];
int stop,sign=-1,c,tempcolor,castling=0,checkcheck=yes,
    moveR1B=no,moveR2B=no,moveR1W=no,moveR2W=no,moveBK=no,moveWK=no,
    help=no,blackcheck=no,whitecheck=no;
char tempcoin;

void pawn(int,int,int);
void rook(int,int,int);
void bishop(int,int,int);
void knight(int,int,int);
void king(int,int,int);
void queen(int,int,int);
void queening(int&,int&);
void redraw();
void occ();
void check();
void main();
void getpos(int&,int&,char&);
void save();
void open();
void board();
void coins();
void mainmenu();

void getpos(int &i,int &j,char &s)
{ if(s=='0')
   exit(0);
  if(s=='m' || s=='M')
   mainmenu();
  else if(s=='r' || s=='R')
  { sign=-1;
    main(); }
  else if(s=='t'||s=='T')
  { if(help==yes) help=no;
    else help=yes; }
  else if(s=='S' || s=='s')
   s='5';
  else if(s=='8' || s=='W' || s=='w')
   i--;
  else if(s=='2' || s=='X' || s=='x')
   i++;
  else if(s=='4' || s=='A' || s=='a')
   j--;
  else if(s=='6' || s=='D' || s=='d')
   j++;
  else if(s=='7' || s=='Q' || s=='q')
  { j--; i--; }
  else if(s=='9' || s=='E' || s=='e')
  { j++; i--; }
  else if(s=='1' || s=='Z' || s=='z')
  { j--; i++; }
  else if(s=='3' || s=='C' || s=='c')
  { j++; i++; }
  if(i==-1)
   i++;
  if(i==8)
   i--;
  if(j==-1)
   j++;
  if(j==8)
   j--; }

void mainmenu()
{ save();
  setfillstyle(SOLID_FILL,BLACK);
  bar(195,150,450,300);
  outtextxy(250,200,"Black king is in check !!");
  settextstyle(1,0,1);
  if(!(blackcheck==yes || whitecheck==yes))
   exit(0);
  else
  { if(blackcheck==yes)
     outtextxy(215,170," Black accepts defeat ?");
    else if(whitecheck==yes)
     outtextxy(215,170," White accepts defeat ?");
  char ch;
  outtextxy(250,200,"1.YES");
  outtextxy(250,230,"2.NO");
  ch=getch();
  if(ch=='1')
//  { spawnl(P_WAIT,"gameovr.exe", NULL);  // game over
    exit(0);
  else
  { board(); coins(); }}}
  /*
void mainmenu()
{ setfillstyle(10,RED);
  float m,x,y;
  x=getmaxx();
  y=getmaxy();
  m=y/x;
  while(y>=0)
  { bar(x,y,getmaxx(),getmaxy());
    y-=2;
    x=y/m; }
  x=y=0;
  setfillstyle(10,BLACK);
  while(y<=getmaxy())
  { bar(0,0,x,y);
    y+=2;
    x=y/m; }}
    */
void open()                      //   Loading a saved game
{ fstream file;
  file.open("slot0.txt",ios::binary|ios::in);
  if(!file)
  { settextstyle(2,0,4);
    setcolor(RED);
    outtextxy(10,getmaxy()-15,"Unable to open");  }
  else
  { file.read((char*)&A,sizeof(A));
    file.read((char*)&sign,sizeof(sign));
    settextstyle(2,0,4);
    setfillstyle(SOLID_FILL,WHITE);
    bar(0,getmaxy()-15,getmaxx(),getmaxy());
    setcolor(RED);
    outtextxy(10,getmaxy()-15,"Loading complete");  }
  file.close();
  board();
  coins();  }

void save()                      //   Saving the game
{ fstream file;
  file.open("slot0.txt",ios::binary|ios::out);
  if(!file)
  { settextstyle(2,0,4);
    setcolor(RED);
    getch();
    outtextxy(10,getmaxy()-15,"Unable to save");  }
  else
  { file.write((char*)&A,sizeof(A));
    file.write((char*)&sign,sizeof(sign));
    settextstyle(2,0,4);
    setfillstyle(SOLID_FILL,WHITE);
    bar(0,getmaxy()-15,getmaxx(),getmaxy());
    setcolor(RED);
    outtextxy(10,getmaxy()-15,"Game saved"); }
  file.close();  }
					 /*
void dontsetvalues()
{ for(int i=0,n=0;i<8;i++,n+=43)
   for(int j=0,m=0;j<8;j++,m+=43)
   { A[i][j].x=150+m;
     A[i][j].y=60+n;
     A[i][j].coin='N';
     A[i][j].color=null;
     A[i][j].occblack=no;
     A[i][j].occwhite=no; }}

void setvalues()
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
	    */
void board()
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

void coins()
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

void PAWN(int &i,int &j)
{ redraw();
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  int p=i,q=j;
  char s;
 while(stop==0)
 {
  s=getch();
  setcolor(WHITE);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  getpos(p,q,s);
  setfillstyle(SOLID_FILL,WHITE);
  bar(0,getmaxy()-15,getmaxx(),getmaxy());
  setcolor(RED);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  if(s=='5')
  { if(i==p && j==q)
    { setcolor(RED);
      rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
      break;  }
    else if(A[i][j].color==black)
    { if(i==1 && p==i+2 && q==j && A[i+1][j].coin=='N'
	 && A[p][q].coin=='N' )
	 stop++;
      else if(p==i+1 && q==j && A[p][q].coin=='N' )
	      stop++;
      else if(p==i+1 && q==j+1 && A[p][q].color==white)
	      stop++;
      else if(p==i+1 && q==j-1 && A[p][q].color==white)
	      stop++;  }
    else if(A[i][j].color==white)
    { if(i==6 && p==i-2 && q==j && A[i-1][j].coin=='N'
	 && A[p][q].coin=='N' )
	 stop++;
      else if(p==i-1 && q==j && A[p][q].coin=='N' )
	      stop++;
      else if(p==i-1 && q==j+1 && A[p][q].color==black)
	      stop++;
      else if(p==i-1 && q==j-1 && A[p][q].color==black)
	      stop++;  }
    if(stop==0)
    { settextstyle(2,0,4);
      outtextxy(10,getmaxy()-15,"You cannot place the coin there !!");  }
    else
    { char tempcoin;
      int m=i,n=j;
      tempcolor=A[p][q].color;
      tempcoin=A[p][q].coin;
      A[p][q].color=A[i][j].color;
      A[p][q].coin=A[i][j].coin;
      A[i][j].color=null;
      A[i][j].coin='N';
      setcolor(WHITE);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
      i=p; j=q;
      if(A[i][j].color==black && i==7)
      { queening(i,j);
	settextstyle(2,0,4);
	setcolor(RED);
	outtextxy(10,getmaxy()-15,"Congrats!! Your pawn has evolved to ");
	if(A[i][j].coin=='R')
	 outtextxy(220,getmaxy()-15,"a rook.");
	else if(A[i][j].coin=='H')
	 outtextxy(220,getmaxy()-15,"a knight.");
	else if(A[i][j].coin=='Q')
	 outtextxy(220,getmaxy()-15,"a queen.");
	else if(A[i][j].coin=='B')
	 outtextxy(220,getmaxy()-15,"a bishop.");  }
      else if(A[i][j].color==white && i==0)
      { queening(i,j);
	settextstyle(2,0,4);
	setcolor(RED);
	outtextxy(10,getmaxy()-15,"Congrats!! Your pawn has evolved to ");
	if(A[i][j].coin=='R')
	 outtextxy(220,getmaxy()-15,"a rook.");
	else if(A[i][j].coin=='H')
	 outtextxy(220,getmaxy()-15,"a knight.");
	else if(A[i][j].coin=='Q')
	 outtextxy(220,getmaxy()-15,"a queen.");
	else if(A[i][j].coin=='B')
	 outtextxy(220,getmaxy()-15,"a bishop.");  }
      if(c==black)
      { occ();  check();
	if(blackcheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[m][n].coin='P';
	  A[m][n].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  i=m; j=n;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"Black king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}
      else if(c==white)
      { occ(); check();
	if(whitecheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[m][n].coin='P';
	  A[m][n].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  i=m; j=n;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"White king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}
      sign*=-1;
      board();
      coins();
      setcolor(RED);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);   }}}}

void ROOK(int &i,int &j)
{ redraw();
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  int p=i,q=j;
  char s;
 while(stop==0)
 {
  s=getch();
  setcolor(WHITE);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  getpos(p,q,s);
  setfillstyle(SOLID_FILL,WHITE);
  bar(0,getmaxy()-15,getmaxx(),getmaxy());
  setcolor(RED);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  if(s=='5')
  { if(i==p && j==q)
    { setcolor(RED);
      rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
      break;  }
    else if(A[i][j].color==black)
    { for(int k=i+1;k<8;k++)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ if(k==p && j==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==k && q==j)
	{ stop++;  break;  }}
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ if(k==p && j==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==k && q==j)
	{ stop++;  break;  }}
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ if(i==p && k==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==i && q==k)
	{ stop++;  break;  }}
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ if(i==p && k==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==i && q==k)
	{ stop++;  break;  }}}
    else if(A[i][j].color==white)
    { for(int k=i+1;k<8;k++)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ if(k==p && j==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==k && q==j)
	{ stop++;  break;  }}
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ if(k==p && j==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==k && q==j)
	{ stop++;  break;  }}
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ if(i==p && k==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==i && q==k)
	{ stop++;  break;  }}
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ if(i==p && k==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==i && q==k)
	{ stop++;  break;  }}}
    if(stop==0)
    { settextstyle(2,0,4);
      outtextxy(10,getmaxy()-15,"You cannot place the coin there !!");  }
    else
    { char tempcoin;
      tempcolor=A[p][q].color;
      tempcoin=A[p][q].coin;
      A[p][q].color=A[i][j].color;
      A[p][q].coin=A[i][j].coin;
      A[i][j].color=null;
      A[i][j].coin='N';
      if(c==black)
      { occ();  check();
	if(blackcheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[i][j].coin=A[p][q].coin;
	  A[i][j].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"Black king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}
      else if(c==white)
      { occ(); check();
	if(whitecheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[i][j].coin=A[p][q].coin;
	  A[i][j].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"White king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}
      setcolor(WHITE);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
      i=p; j=q;
      sign*=-1;
      board();
      coins();
      setcolor(RED);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);  }}}}

void KNIGHT(int &i,int &j)
{ redraw();
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  int p=i,q=j;
  char s;
 while(stop==0)
 {
  s=getch();
  setcolor(WHITE);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  getpos(p,q,s);
  setfillstyle(SOLID_FILL,WHITE);
  bar(0,getmaxy()-15,getmaxx(),getmaxy());
  setcolor(RED);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  if(s=='5')
  { if(i==p && j==q)
    { setcolor(RED);
      rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
      break;  }
    else if(A[i][j].color==black)
    { if(i-2==p && j+1==q && A[p][q].color!=black)
       stop++;
      else if(i-2==p && j-1==q && A[p][q].color!=black)
       stop++;
      else if(i-1==p && j+2==q && A[p][q].color!=black)
       stop++;
      else if(i-1==p && j-2==q && A[p][q].color!=black)
       stop++;
      else if(i+1==p && j+2==q && A[p][q].color!=black)
       stop++;
      else if(i+1==p && j-2==q && A[p][q].color!=black)
       stop++;
      else if(i+2==p && j+1==q && A[p][q].color!=black)
       stop++;
      else if(i+2==p && j-1==q && A[p][q].color!=black)
       stop++;   }
    else if(A[i][j].color==white)
    { if(i-2==p && j+1==q && A[p][q].color!=white)
       stop++;
      else if(i-2==p && j-1==q && A[p][q].color!=white)
       stop++;
      else if(i-1==p && j+2==q && A[p][q].color!=white)
       stop++;
      else if(i-1==p && j-2==q && A[p][q].color!=white)
       stop++;
      else if(i+1==p && j+2==q && A[p][q].color!=white)
       stop++;
      else if(i+1==p && j-2==q && A[p][q].color!=white)
       stop++;
      else if(i+2==p && j+1==q && A[p][q].color!=white)
       stop++;
      else if(i+2==p && j-1==q && A[p][q].color!=white)
       stop++;   }
    if(stop==0)
    { settextstyle(2,0,4);
      outtextxy(10,getmaxy()-15,"You cannot place the coin there !!");  }
    else
    { char tempcoin;
      tempcolor=A[p][q].color;
      tempcoin=A[p][q].coin;
      A[p][q].color=A[i][j].color;
      A[p][q].coin=A[i][j].coin;
      A[i][j].color=null;
      A[i][j].coin='N';
      if(c==black)
      { occ();  check();
	if(blackcheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[i][j].coin=A[p][q].coin;
	  A[i][j].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"Black king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}
      else if(c==white)
      { occ(); check();
	if(whitecheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[i][j].coin=A[p][q].coin;
	  A[i][j].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"White king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}
      setcolor(WHITE);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
      i=p; j=q;
      sign*=-1;
      board();
      coins();
      setcolor(RED);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);   }}}}

void BISHOP(int &i,int &j)
{ redraw();
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  int p=i,q=j;
  char s;
 while(stop==0)
 {
  s=getch();
  setcolor(WHITE);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  getpos(p,q,s);
  setfillstyle(SOLID_FILL,WHITE);
  bar(0,getmaxy()-15,getmaxx(),getmaxy());
  setcolor(RED);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  if(s=='5')
  { if(i==p && j==q)
    { setcolor(RED);
      rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
      break;  }
    else if(A[i][j].color==black)
    { for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}}
    else if(A[i][j].color==white)
    { for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}}
    if(stop==0)
    { settextstyle(2,0,4);
      outtextxy(10,getmaxy()-15,"You cannot place the coin there !!");  }
    else
    { char tempcoin;
      tempcolor=A[p][q].color;
      tempcoin=A[p][q].coin;
      A[p][q].color=A[i][j].color;
      A[p][q].coin=A[i][j].coin;
      A[i][j].color=null;
      A[i][j].coin='N';
      if(c==black)
      { occ();  check();
	if(blackcheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[i][j].coin=A[p][q].coin;
	  A[i][j].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"Black king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}
      else if(c==white)
      { occ(); check();
	if(whitecheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[i][j].coin=A[p][q].coin;
	  A[i][j].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"White king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}
      setcolor(WHITE);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
      i=p; j=q;
      sign*=-1;
      board();
      coins();
      setcolor(RED);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);  }}}}

void QUEEN(int &i,int &j)
{ redraw();
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  int p=i,q=j;
  char s;
 while(stop==0)
 {
  s=getch();
  setcolor(WHITE);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  getpos(p,q,s);
  setfillstyle(SOLID_FILL,WHITE);
  bar(0,getmaxy()-15,getmaxx(),getmaxy());
  setcolor(RED);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  if(s=='5')
  { if(i==p && j==q)
    { setcolor(RED);
      rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
      break;  }
    else if(A[i][j].color==black)
    { for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(int k=i+1;k<8;k++)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ if(k==p && j==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==k && q==j)
	{ stop++;  break;  }}
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ if(k==p && j==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==k && q==j)
	{ stop++;  break;  }}
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ if(i==p && k==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==i && q==k)
	{ stop++;  break;  }}
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ if(i==p && k==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==i && q==k)
	{ stop++;  break;  }}}
    else if(A[i][j].color==white)
    { for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ if(u==p && v==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==u && q==v)
	{ stop++;  break;  }}
      for(int k=i+1;k<8;k++)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ if(k==p && j==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==k && q==j)
	{ stop++;  break;  }}
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ if(k==p && j==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==k && q==j)
	{ stop++;  break;  }}
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ if(i==p && k==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==i && q==k)
	{ stop++;  break;  }}
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ if(i==p && k==q)
	  { stop++;  break;  }
	  else
	   break;  }
	else if(p==i && q==k)
	{ stop++;  break;  }}}
    if(stop==0)
    { settextstyle(2,0,4);
      outtextxy(10,getmaxy()-15,"You cannot place the coin there !!");  }
    else
    { char tempcoin;
      tempcolor=A[p][q].color;
      tempcoin=A[p][q].coin;
      A[p][q].color=A[i][j].color;
      A[p][q].coin=A[i][j].coin;
      A[i][j].color=null;
      A[i][j].coin='N';
      if(c==black)
      { occ();  check();
	if(blackcheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[i][j].coin=A[p][q].coin;
	  A[i][j].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"Black king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}
      else if(c==white)
      { occ(); check();
	if(whitecheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[i][j].coin=A[p][q].coin;
	  A[i][j].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"White king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}
      setcolor(WHITE);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
      i=p; j=q;
      sign*=-1;
      board();
      coins();
      setcolor(RED);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);  }}}}

void KING(int &i,int &j)
{ redraw();
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  int p=i,q=j;
  char s;
  castling=0;
 while(stop==0)
 {
  s=getch();
  setcolor(WHITE);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  setcolor(YELLOW);
  rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
  getpos(p,q,s);
  setfillstyle(SOLID_FILL,WHITE);
  bar(0,getmaxy()-15,getmaxx(),getmaxy());
  setcolor(RED);
  rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
  if(s=='5')
  { if(i==p && j==q)
    { setcolor(RED);
      rectangle(A[p][q].x,A[p][q].y,A[p][q].x+43,A[p][q].y+43);
      break;  }
    else if(A[i][j].color==black)
    { if(i-1==p && j-1==q && A[p][q].color!=black)
       stop++;
      else if(i-1==p && j==q && A[p][q].color!=black)
       stop++;
      else if(i-1==p && j+1==q && A[p][q].color!=black)
       stop++;
      else if(i==p && j-1==q && A[p][q].color!=black)
       stop++;
      else if(i==p && j+1==q && A[p][q].color!=black)
       stop++;
      else if(i+1==p && j-1==q && A[p][q].color!=black)
       stop++;
      else if(i+1==p && j==q && A[p][q].color!=black)
       stop++;
      else if(i+1==p && j+1==q && A[p][q].color!=black)
       stop++;
      else if(i==0 && j==3 && p==0 && q==1)
       if(blackcheck==no && A[0][2].occwhite==no &&
	   A[0][1].occwhite==no && moveR1B==no && moveBK==no &&
	   A[0][1].coin=='N' && A[0][2].coin=='N')
	{  settextstyle(2,0,4);
	   outtextxy(10,getmaxy()-15,"Castling successful !!");
	   A[0][0].coin='N';
	   A[0][0].color=null;
	   A[0][2].coin='R';
	   A[0][2].color=black;
	   checkcheck=no;
	   castling++;
	   stop++; }
      if(i==0 && j==3 && p==0 && q==6)
       if(blackcheck==no && A[0][4].occwhite==no &&
	   A[0][5].occwhite==no && A[0][6].occwhite==no &&
	   moveR2B==no && moveBK==no && A[0][4].coin=='N' &&
	   A[0][5].coin=='N' && A[0][6].coin=='N')
	{  settextstyle(2,0,4);
	   outtextxy(10,getmaxy()-15,"Castling successful !!");
	   A[0][7].coin='N';
	   A[0][7].color=null;
	   A[0][5].coin='R';
	   A[0][5].color=black;
	   checkcheck=no;
	   castling++;
	   stop++; }}
    else if(A[i][j].color==white)
    { if(i-1==p && j-1==q && A[p][q].color!=white)
       stop++;
      else if(i-1==p && j==q && A[p][q].color!=white)
       stop++;
      else if(i-1==p && j+1==q && A[p][q].color!=white)
       stop++;
      else if(i==p && j-1==q && A[p][q].color!=white)
       stop++;
      else if(i==p && j+1==q && A[p][q].color!=white)
       stop++;
      else if(i+1==p && j-1==q && A[p][q].color!=white)
       stop++;
      else if(i+1==p && j==q && A[p][q].color!=white)
       stop++;
      else if(i+1==p && j+1==q && A[p][q].color!=white)
       stop++;
      else if(i==7 && j==3 && p==7 && q==1)
       if(whitecheck==no && A[7][2].occblack==no &&
	   A[7][1].occblack==no && moveR1W==no && moveWK==no &&
	   A[7][1].coin=='N' && A[7][2].coin=='N')
	{  settextstyle(2,0,4);
	   outtextxy(10,getmaxy()-15,"Castling successful !!");
	   A[7][0].coin='N';
	   A[7][0].color=null;
	   A[7][2].coin='R';
	   A[7][2].color=white;
	   checkcheck=no;
	   castling++;
	   stop++; }
      if(i==7 && j==3 && p==7 && q==6)
       if(whitecheck==no && A[7][4].occblack==no &&
	   A[7][5].occblack==no && A[7][6].occblack==no &&
	   moveR2W==no && moveWK==no  && A[7][4].coin=='N' &&
	   A[7][5].coin=='N' && A[7][6].coin=='N')
	{  settextstyle(2,0,4);
	   outtextxy(10,getmaxy()-15,"Castling successful !!");
	   A[7][7].coin='N';
	   A[7][7].color=null;
	   A[7][5].coin='R';
	   A[7][5].color=white;
	   checkcheck=no;
	   castling++;
	   stop++; }}
    if(stop==0)
    { settextstyle(2,0,4);
      outtextxy(10,getmaxy()-15,"You cannot place the coin there !!");  }
    else
    { char tempcoin;
      tempcolor=A[p][q].color;
      tempcoin=A[p][q].coin;
      A[p][q].color=A[i][j].color;
      A[p][q].coin=A[i][j].coin;
      A[i][j].color=null;
      A[i][j].coin='N';
      if(castling==0) {
      if(c==black)
      { occ();  check();
	if(blackcheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[i][j].coin=A[p][q].coin;
	  A[i][j].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"Black king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}
      else if(c==white)
      { occ(); check();
	if(whitecheck==yes)
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());
	  A[i][j].coin=A[p][q].coin;
	  A[i][j].color=A[p][q].color;
	  A[p][q].coin=tempcoin;
	  A[p][q].color=tempcolor;
	  settextstyle(2,0,4);
	  outtextxy(10,getmaxy()-15,"White king will be in check !!");
	  checkcheck=no;
	  sign*=-1;  }
	else
	{ setfillstyle(SOLID_FILL,WHITE);
	  bar(0,getmaxy()-15,getmaxx(),getmaxy());  }}}
      setcolor(WHITE);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);
      i=p; j=q;
      sign*=-1;
      board();
      coins();
      setcolor(RED);
      rectangle(A[i][j].x,A[i][j].y,A[i][j].x+43,A[i][j].y+43);   }}}}

void queening(int &i,int &j)
{
 settextstyle(1,0,1);
 setfillstyle(SOLID_FILL,BLACK);
 bar(180,150,220+43*3+70,323);
 outtextxy(220,180,"SELECT YOUR COIN");
/* rook(220,230,A[i][j].color);
 knight(220+43,230,A[i][j].color);
 bishop(220+43*2,230,A[i][j].color);
 queen(220+43*3,230,A[i][j].color);*/
 int Mstatus = initmouse();
 int button,m,n;
 if(Mstatus == 0 )
  outtextxy(50,50, "Mouse Support Not Available");
 while(!kbhit())
{ showmouseptr();
  getmousepos(&button,&m,&n);
  if(m>220 && m<220+42 && n>230 && n<230+43)
   rook(220,230,null);
  else
   rook(220,230,A[i][j].color);
  if(m>220+43 && m<220+43*2-1 && n>230 && n<230+43)
   knight(220+43,230,null);
  else
   knight(220+43,230,A[i][j].color);
  if(m>220+43*2 && m<220+43*3-1 && n>230 && n<230+43)
   bishop(220+43*2,230,null);
  else
   bishop(220+43*2,230,A[i][j].color);
  if(m>220+43*3 && m<220+43*4-1 && n>230 && n<230+43)
   queen(220+43*3,230,null);
  else
   queen(220+43*3,230,A[i][j].color);
  if(button == 1)
 {if(m>220 && m<220+42 && n>230 && n<230+43)
  { A[i][j].coin='R';
    break;  }
  else if(m>220+43 && m<220+43*2-1 && n>230 && n<230+43)
  { A[i][j].coin='H';
    break;  }
  else if(m>220+43*2 && m<220+43*3-1 && n>230 && n<230+43)
  { A[i][j].coin='B';
    break;  }
  else if(m>220+43*3 && m<220+43*4-1 && n>230 && n<230+43)
  { A[i][j].coin='Q';
    break;  }    }}
 hidemouseptr();   }

void check()
{ if(c==black)
  { int a,b;
    for(int u=0;u<8;u++)
     for(int v=0;v<8;v++)
      if(A[u][v].coin=='K' && A[u][v].color==black)
      { a=u; b=v;
	break; }
    if(A[a][b].occwhite==yes)
    { setfillstyle(SOLID_FILL,WHITE);
      bar(0,getmaxy()-15,getmaxx(),getmaxy());
      settextstyle(2,0,4);
      setcolor(RED);
      outtextxy(10,getmaxy()-15,"Black is in check !!");
      blackcheck=yes;  }
    else
     blackcheck=no;  }
  else if(c==white)
  { int a,b;
    for(int u=0;u<8;u++)
     for(int v=0;v<8;v++)
      if(A[u][v].coin=='K' && A[u][v].color==white)
      { a=u; b=v;
	break; }
    if(A[a][b].occblack==yes)
    { setfillstyle(SOLID_FILL,WHITE);
      bar(0,getmaxy()-15,getmaxx(),getmaxy());
      settextstyle(2,0,4);
      setcolor(RED);
      outtextxy(10,getmaxy()-15,"White is in check !!");
      whitecheck=yes;  }
    else
     whitecheck=no;  }}

void redraw()
{ setcolor(WHITE);
  for(int a=0;a<8;a++)
   for(int b=0;b<8;b++)
    rectangle(A[a][b].x,A[a][b].y,A[a][b].x+43,A[a][b].y+43);  }

void boxes(int &i,int &j)
{ setcolor(RED);
     if(A[i][j].coin=='P' && A[i][j].color==black)   // Black pawn
     { if(A[i+1][j].coin=='N' && i+1<=7)
	rectangle(A[i+1][j].x,A[i+1][j].y,A[i+1][j].x+43,A[i+1][j].y+43);
       if(i==1 && A[i+2][j].coin=='N' && A[i+1][j].coin=='N' && i+2<=7)
	rectangle(A[i+2][j].x,A[i+2][j].y,A[i+2][j].x+43,A[i+2][j].y+43);
       if(A[i+1][j+1].color==white && i+1<=7 && j+1<=7)
	rectangle(A[i+1][j+1].x,A[i+1][j+1].y,A[i+1][j+1].x+43,A[i+1][j+1].y+43);
       if(A[i+1][j-1].color==white && i+1<=7 && j-1>=0)
	rectangle(A[i+1][j-1].x,A[i+1][j-1].y,A[i+1][j-1].x+43,A[i+1][j-1].y+43);  }
     else if(A[i][j].coin=='P' && A[i][j].color==white)   // White pawn
     { if(A[i-1][j].coin=='N' && i-1>=0)
	rectangle(A[i-1][j].x,A[i-1][j].y,A[i-1][j].x+43,A[i-1][j].y+43);
       if(i==6 && A[i-2][j].coin=='N' && A[i-1][j].coin=='N' && i-2>=0)
	rectangle(A[i-2][j].x,A[i-2][j].y,A[i-2][j].x+43,A[i-2][j].y+43);
       if(A[i-1][j+1].color==black && i-1>=0 && j+1<=7)
	rectangle(A[i-1][j+1].x,A[i-1][j+1].y,A[i-1][j+1].x+43,A[i-1][j+1].y+43);
       if(A[i-1][j-1].color==black && i-1>=0 && j-1>=0)
	rectangle(A[i-1][j-1].x,A[i-1][j-1].y,A[i-1][j-1].x+43,A[i-1][j-1].y+43);  }
     else if(A[i][j].coin=='H' && A[i][j].color==black)   // Black knight
     { if(A[i-2][j-1].color!=black && (i-2>=0&&j-1>=0))
	rectangle(A[i-2][j-1].x,A[i-2][j-1].y,A[i-2][j-1].x+43,A[i-2][j-1].y+43);
       if(A[i-2][j+1].color!=black && (i-2>=0&&j+1<=7))
	rectangle(A[i-2][j+1].x,A[i-2][j+1].y,A[i-2][j+1].x+43,A[i-2][j+1].y+43);
       if(A[i+2][j-1].color!=black && (i+2<=7&&j>=0))
	rectangle(A[i+2][j-1].x,A[i+2][j-1].y,A[i+2][j-1].x+43,A[i+2][j-1].y+43);
       if(A[i+2][j+1].color!=black && (i+2<=7&&j+1<=7))
	rectangle(A[i+2][j+1].x,A[i+2][j+1].y,A[i+2][j+1].x+43,A[i+2][j+1].y+43);
       if(A[i-1][j-2].color!=black && (i-1>=0&&j-2>=0))
	rectangle(A[i-1][j-2].x,A[i-1][j-2].y,A[i-1][j-2].x+43,A[i-1][j-2].y+43);
       if(A[i-1][j+2].color!=black && (i-1>=0&&j+2<=7))
	rectangle(A[i-1][j+2].x,A[i-1][j+2].y,A[i-1][j+2].x+43,A[i-1][j+2].y+43);
       if(A[i+1][j-2].color!=black && (i+1<=7&&j-2>=0))
	rectangle(A[i+1][j-2].x,A[i+1][j-2].y,A[i+1][j-2].x+43,A[i+1][j-2].y+43);
       if(A[i+1][j+2].color!=black && (i+1<=7&&j+2<=7))
	rectangle(A[i+1][j+2].x,A[i+1][j+2].y,A[i+1][j+2].x+43,A[i+1][j+2].y+43);  }
     else if(A[i][j].coin=='H' && A[i][j].color==white)    // White knight
     { if(A[i-2][j-1].color!=white && i-2>=0 && j-1>=0)
	rectangle(A[i-2][j-1].x,A[i-2][j-1].y,A[i-2][j-1].x+43,A[i-2][j-1].y+43);
       if(A[i-2][j+1].color!=white && i-2>=0 && j+1<=7)
	rectangle(A[i-2][j+1].x,A[i-2][j+1].y,A[i-2][j+1].x+43,A[i-2][j+1].y+43);
       if(A[i+2][j-1].color!=white && i+2<=7 && j-1>=0)
	rectangle(A[i+2][j-1].x,A[i+2][j-1].y,A[i+2][j-1].x+43,A[i+2][j-1].y+43);
       if(A[i+2][j+1].color!=white && i+2<=7 && j+1<=7)
	rectangle(A[i+2][j+1].x,A[i+2][j+1].y,A[i+2][j+1].x+43,A[i+2][j+1].y+43);
       if(A[i-1][j-2].color!=white && i-1>=0 && j-2>=0)
	rectangle(A[i-1][j-2].x,A[i-1][j-2].y,A[i-1][j-2].x+43,A[i-1][j-2].y+43);
       if(A[i-1][j+2].color!=white && i-1>=0 && j+2<=7)
	rectangle(A[i-1][j+2].x,A[i-1][j+2].y,A[i-1][j+2].x+43,A[i-1][j+2].y+43);
       if(A[i+1][j-2].color!=white && i+1<=7 && j-2>=0)
	rectangle(A[i+1][j-2].x,A[i+1][j-2].y,A[i+1][j-2].x+43,A[i+1][j-2].y+43);
       if(A[i+1][j+2].color!=white && i+1<=7 && j+2<=7)
	rectangle(A[i+1][j+2].x,A[i+1][j+2].y,A[i+1][j+2].x+43,A[i+1][j+2].y+43);  }
     else if(A[i][j].coin=='R' && A[i][j].color==black)    // Black rook
     {for(int k=i+1;k<8;k++)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);
	  break;  }
	else
	 rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);  }
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);
	  break;  }
	else
	 rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);  }
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);
	  break;  }
	else
	 rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);  }
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);
	  break;  }
	else
	 rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);  }}
     else if(A[i][j].coin=='R' && A[i][j].color==white)    // White rook
     {for(int k=i+1;k<8;k++)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);
	  break;  }
	else
	 rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);  }
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);
	  break;  }
	else
	 rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);  }
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);
	  break;  }
	else
	 rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);  }
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);
	  break;  }
	else
	 rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);  }}
     else if(A[i][j].coin=='B' && A[i][j].color==black)    // Black bishop
     {for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }}
     else if(A[i][j].coin=='B' && A[i][j].color==white)    // White bishop
     {for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }}
     else if(A[i][j].coin=='Q' && A[i][j].color==black)    // Black Queen
     {for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(int k=i+1;k<8;k++)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);
	  break;  }
	else
	 rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);  }
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);
	  break;  }
	else
	 rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);  }
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);
	  break;  }
	else
	 rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);  }
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);
	  break;  }
	else
	 rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);  }}
     else if(A[i][j].coin=='Q' && A[i][j].color==white)   // White Queen
     {for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);
	  break;  }
	else
	 rectangle(A[u][v].x,A[u][v].y,A[u][v].x+43,A[u][v].y+43);  }
      for(int k=i+1;k<8;k++)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);
	  break;  }
	else
	 rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);  }
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);
	  break;  }
	else
	 rectangle(A[k][j].x,A[k][j].y,A[k][j].x+43,A[k][j].y+43);  }
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);
	  break;  }
	else
	 rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);  }
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);
	  break;  }
	else
	 rectangle(A[i][k].x,A[i][k].y,A[i][k].x+43,A[i][k].y+43);  }}
     else if(A[i][j].coin=='K' && A[i][j].color==black)   // Black king
     { if(A[i-1][j-1].color!=black && i-1>=0 && j-1>=0)
	rectangle(A[i-1][j-1].x,A[i-1][j-1].y,A[i-1][j-1].x+43,A[i-1][j-1].y+43);
       if(A[i-1][j].color!=black && i-1>=0)
	rectangle(A[i-1][j].x,A[i-1][j].y,A[i-1][j].x+43,A[i-1][j].y+43);
       if(A[i-1][j+1].color!=black && i-1>=0 && j+1<=7)
	rectangle(A[i-1][j+1].x,A[i-1][j+1].y,A[i-1][j+1].x+43,A[i-1][j+1].y+43);
       if(A[i][j-1].color!=black && j-1>=0)
	rectangle(A[i][j-1].x,A[i][j-1].y,A[i][j-1].x+43,A[i][j-1].y+43);
       if(A[i][j+1].color!=black && j+1<=7)
	rectangle(A[i][j+1].x,A[i][j+1].y,A[i][j+1].x+43,A[i][j+1].y+43);
       if(A[i+1][j-1].color!=black && i+1<=7 && j-1>=0)
	rectangle(A[i+1][j-1].x,A[i+1][j-1].y,A[i+1][j-1].x+43,A[i+1][j-1].y+43);
       if(A[i+1][j].color!=black && i+1<=7)
	rectangle(A[i+1][j].x,A[i+1][j].y,A[i+1][j].x+43,A[i+1][j].y+43);
       if(A[i+1][j+1].color!=black && i+1<=7 && j+1<=7)
	rectangle(A[i+1][j+1].x,A[i+1][j+1].y,A[i+1][j+1].x+43,A[i+1][j+1].y+43);
       if(blackcheck==no && A[0][2].occwhite==no &&
	   A[0][1].occwhite==no && moveR1B==no && moveBK==no &&
	   A[0][1].coin=='N' && A[0][2].coin=='N' &&
	   i==0 && j==3)
	 rectangle(A[0][1].x,A[0][1].y,A[0][1].x+43,A[0][1].y+43);
       if(blackcheck==no && A[0][4].occwhite==no &&
	   A[0][5].occwhite==no && A[0][6].occwhite==no &&
	   moveR2B==no && moveBK==no && A[0][4].coin=='N' &&
	   A[0][5].coin=='N' && A[0][6].coin=='N' &&
	   i==0 && j==3)
	 rectangle(A[0][6].x,A[0][6].y,A[0][6].x+43,A[0][6].y+43);  }
     else if(A[i][j].coin=='K' && A[i][j].color==white)   // White king
     { if(A[i-1][j-1].color!=white && i-1>=0 && j-1>=0)
	rectangle(A[i-1][j-1].x,A[i-1][j-1].y,A[i-1][j-1].x+43,A[i-1][j-1].y+43);
       if(A[i-1][j].color!=white && i-1>=0)
	rectangle(A[i-1][j].x,A[i-1][j].y,A[i-1][j].x+43,A[i-1][j].y+43);
       if(A[i-1][j+1].color!=white && i-1>=0 && j+1<=7)
	rectangle(A[i-1][j+1].x,A[i-1][j+1].y,A[i-1][j+1].x+43,A[i-1][j+1].y+43);
       if(A[i][j-1].color!=white && j-1>=0)
	rectangle(A[i][j-1].x,A[i][j-1].y,A[i][j-1].x+43,A[i][j-1].y+43);
       if(A[i][j+1].color!=white && j+1<=7)
	rectangle(A[i][j+1].x,A[i][j+1].y,A[i][j+1].x+43,A[i][j+1].y+43);
       if(A[i+1][j-1].color!=white && i+1<=7 && j-1>=0)
	rectangle(A[i+1][j-1].x,A[i+1][j-1].y,A[i+1][j-1].x+43,A[i+1][j-1].y+43);
       if(A[i+1][j].color!=white && i+1<=7)
	rectangle(A[i+1][j].x,A[i+1][j].y,A[i+1][j].x+43,A[i+1][j].y+43);
       if(A[i+1][j+1].color!=white && i+1<=7 && j+1<=7)
	rectangle(A[i+1][j+1].x,A[i+1][j+1].y,A[i+1][j+1].x+43,A[i+1][j+1].y+43);
       if(whitecheck==no && A[7][2].occblack==no &&
	   A[7][1].occblack==no && moveR1W==no && moveWK==no &&
	   A[7][1].coin=='N' && A[7][2].coin=='N' &&
	   i==7 && j==3)
	 rectangle(A[7][1].x,A[7][1].y,A[7][1].x+43,A[7][1].y+43);
       if(whitecheck==no && A[7][4].occblack==no &&
	   A[7][5].occblack==no && A[7][6].occblack==no &&
	   moveR2W==no && moveWK==no && A[7][4].coin=='N' &&
	   A[7][5].coin=='N' && A[7][6].coin=='N' &&
	   i==7 && j==3)
	 rectangle(A[7][6].x,A[7][6].y,A[7][6].x+43,A[7][6].y+43);  }}

void occ()
{ for(int a=0;a<8;a++)
   for(int b=0;b<8;b++)
   { A[a][b].occblack=no;
     A[a][b].occwhite=no; }
  for(int i=0;i<8;i++)
   for(int j=0;j<8;j++)
   { if(A[i][j].coin=='P' && A[i][j].color==black)   // Black pawn
     { if(A[i+1][j].coin=='N')
	A[i+1][j].occblack=yes;
       if(i==1 && A[i+2][j].coin=='N')
	A[i+2][j].occblack=yes;
       if(A[i+1][j+1].color==white)
	A[i+1][j+1].occblack=yes;
       if(A[i+1][j-1].color==white)
	A[i+1][j-1].occblack=yes; }
     else if(A[i][j].coin=='P' && A[i][j].color==white)   // White pawn
     { if(A[i-1][j].coin=='N')
	A[i-1][j].occwhite=yes;
       if(i==6 && A[i-2][j].coin=='N')
	A[i-2][j].occwhite=yes;
       if(A[i-1][j+1].color==black)
	A[i-1][j+1].occwhite=yes;
       if(A[i-1][j-1].color==black)
	A[i-1][j-1].occwhite=yes; }
     else if(A[i][j].coin=='H' && A[i][j].color==black)   // Black knight
     { if(A[i-2][j-1].color!=black)
	A[i-2][j-1].occblack=yes;
       if(A[i-2][j+1].color!=black)
	A[i-2][j+1].occblack=yes;
       if(A[i+2][j-1].color!=black)
	A[i+2][j-1].occblack=yes;
       if(A[i+2][j+1].color!=black)
	A[i+2][j+1].occblack=yes;
       if(A[i-1][j-2].color!=black)
	A[i-1][j-2].occblack=yes;
       if(A[i-1][j+2].color!=black)
	A[i-1][j+2].occblack=yes;
       if(A[i+1][j-2].color!=black)
	A[i+1][j-2].occblack=yes;
       if(A[i+1][j+2].color!=black)
	A[i+1][j+2].occblack=yes; }
     else if(A[i][j].coin=='H' && A[i][j].color==white)    // White knight
     { if(A[i-2][j-1].color!=white)
	A[i-2][j-1].occwhite=yes;
       if(A[i-2][j+1].color!=white)
	A[i-2][j+1].occwhite=yes;
       if(A[i+2][j-1].color!=white)
	A[i+2][j-1].occwhite=yes;
       if(A[i+2][j+1].color!=white)
	A[i+2][j+1].occwhite=yes;
       if(A[i-1][j-2].color!=white)
	A[i-1][j-2].occwhite=yes;
       if(A[i-1][j+2].color!=white)
	A[i-1][j+2].occwhite=yes;
       if(A[i+1][j-2].color!=white)
	A[i+1][j-2].occwhite=yes;
       if(A[i+1][j+2].color!=white)
	A[i+1][j+2].occwhite=yes; }
     else if(A[i][j].coin=='R' && A[i][j].color==black)    // Black rook
     {for(int k=i+1;k<8;k++)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ A[k][j].occblack=yes;
	  break;  }
	else
	 A[k][j].occblack=yes;  }
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ A[k][j].occblack=yes;
	  break;  }
	  else
	 A[k][j].occblack=yes;  }
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ A[i][k].occblack=yes;
	  break;  }
	else
	 A[i][k].occblack=yes;  }
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ A[i][k].occblack=yes;
	  break;  }
	else
	 A[i][k].occblack=yes;  }}
     else if(A[i][j].coin=='R' && A[i][j].color==white)    // White rook
     {for(int k=i+1;k<8;k++)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ A[k][j].occwhite=yes;
	  break;  }
	else
	 A[k][j].occwhite=yes;  }
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ A[k][j].occwhite=yes;
	  break;  }
	else
	 A[k][j].occwhite=yes;  }
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ A[i][k].occwhite=yes;
	  break;  }
	else
	 A[i][k].occwhite=yes;  }
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ A[i][k].occwhite=yes;
	  break;  }
	else
	 A[i][k].occwhite=yes;  }}
     else if(A[i][j].coin=='B' && A[i][j].color==black)    // Black bishop
     {for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ A[u][v].occblack=yes;
	   break;  }
	else
	 A[u][v].occblack=yes;  }
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ A[u][v].occblack=yes;
	   break;  }
	else
	 A[u][v].occblack=yes;  }
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ A[u][v].occblack=yes;
	   break;  }
	else
	 A[u][v].occblack=yes;  }
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ A[u][v].occblack=yes;
	   break;  }
	else
	 A[u][v].occblack=yes;  }}
     else if(A[i][j].coin=='B' && A[i][j].color==white)    // White bishop
     {for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ A[u][v].occwhite=yes;
	  break;  }
	else
	 A[u][v].occwhite=yes;  }
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ A[u][v].occwhite=yes;
	  break;  }
	else
	 A[u][v].occwhite=yes;  }
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ A[u][v].occwhite=yes;
	  break;  }
	else
	 A[u][v].occwhite=yes;  }
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ A[u][v].occwhite=yes;
	  break;  }
	else
	 A[u][v].occwhite=yes;  }}
     else if(A[i][j].coin=='Q' && A[i][j].color==black)    // Black Queen
     {for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ A[u][v].occblack=yes;
	   break;  }
	else
	 A[u][v].occblack=yes;  }
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ A[u][v].occblack=yes;
	   break;  }
	else
	 A[u][v].occblack=yes;  }
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ A[u][v].occblack=yes;
	   break;  }
	else
	 A[u][v].occblack=yes;  }
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==black)
	 break;
	else if(A[u][v].color==white)
	{ A[u][v].occblack=yes;
	   break;  }
	else
	 A[u][v].occblack=yes;  }
      for(int k=i+1;k<8;k++)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ A[k][j].occblack=yes;
	   break;  }
	else
	 A[k][j].occblack=yes;  }
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==black)
	 break;
	else if(A[k][j].color==white)
	{ A[k][j].occblack=yes;
	   break;  }
	else
	 A[k][j].occblack=yes;  }
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ A[i][k].occblack=yes;
	   break;  }
	else
	 A[i][k].occblack=yes;  }
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==black)
	 break;
	else if(A[i][k].color==white)
	{ A[i][k].occblack=yes;
	   break;  }
	else
	 A[i][k].occblack=yes;  }}
     else if(A[i][j].coin=='Q' && A[i][j].color==white)   // White Queen
     {for(int u=i+1,v=j+1;u<8 && v<8;u++,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ A[u][v].occwhite=yes;
	  break;  }
	else
	 A[u][v].occwhite=yes;  }
      for(u=i-1,v=j-1;u>-1 && v>-1;u--,v--)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ A[u][v].occwhite=yes;
	  break;  }
	else
	 A[u][v].occwhite=yes;  }
      for(u=i-1,v=j+1;u>-1 && v<8;u--,v++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ A[u][v].occwhite=yes;
	  break;  }
	else
	 A[u][v].occwhite=yes;  }
      for(u=i+1,v=j-1;v>-1 && u<8;v--,u++)
      { if(A[u][v].color==white)
	 break;
	else if(A[u][v].color==black)
	{ A[u][v].occwhite=yes;
	  break;  }
	else
	 A[u][v].occwhite=yes;  }
      for(int k=i+1;k<8;k++)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ A[k][j].occwhite=yes;
	  break;  }
	else
	 A[k][j].occwhite=yes;  }
      for(k=i-1;k>-1;k--)
      { if(A[k][j].color==white)
	 break;
	else if(A[k][j].color==black)
	{ A[k][j].occwhite=yes;
	  break;  }
	else
	 A[k][j].occwhite=yes;  }
      for(k=j+1;k<8;k++)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ A[i][k].occwhite=yes;
	  break;  }
	else
	 A[i][k].occwhite=yes;  }
      for(k=j-1;k>-1;k--)
      { if(A[i][k].color==white)
	 break;
	else if(A[i][k].color==black)
	{ A[i][k].occwhite=yes;
	  break;  }
	else
	 A[i][k].occwhite=yes;  }}
      if(A[i][j].coin=='K' && A[i][j].color==black)   // Black king
     { if(A[i-1][j-1].color!=black)
	A[i-1][j-1].occblack=yes;
       if(A[i-1][j].color!=black)
	A[i-1][j].occblack=yes;
       if(A[i-1][j+1].color!=black)
	A[i-1][j+1].occblack=yes;
       if(A[i][j-1].color!=black)
	A[i][j-1].occblack=yes;
       if(A[i][j+1].color!=black)
	A[i][j+1].occblack=yes;
       if(A[i+1][j-1].color!=black)
	A[i+1][j-1].occblack=yes;
       if(A[i+1][j].color!=black)
	A[i+1][j].occblack=yes;
       if(A[i+1][j+1].color!=black)
	A[i+1][j+1].occblack=yes;  }
     else if(A[i][j].coin=='K' && A[i][j].color==white)   // White king
     { if(A[i-1][j-1].color!=white)
	A[i-1][j-1].occwhite=yes;
       if(A[i-1][j].color!=white)
	A[i-1][j].occwhite=yes;
       if(A[i-1][j+1].color!=white)
	A[i-1][j+1].occwhite=yes;
       if(A[i][j-1].color!=white)
	A[i][j-1].occwhite=yes;
       if(A[i][j+1].color!=white)
	A[i][j+1].occwhite=yes;
       if(A[i+1][j-1].color!=white)
	A[i+1][j-1].occwhite=yes;
       if(A[i+1][j].color!=white)
	A[i+1][j].occwhite=yes;
       if(A[i+1][j+1].color!=white)
	A[i+1][j+1].occwhite=yes;  }}}
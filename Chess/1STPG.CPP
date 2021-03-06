/*   Screen    */

enum{ null=-1,black,white };

void pawn(int,int,int);
void rook(int,int,int);
void bishop(int,int,int);
void knight(int,int,int);
void king(int,int,int);
void queen(int,int,int);

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


void HELP(int);
void controls(int);
void howtoplay(int);
void circle();

void drawkq(float m)
{int x,y,x1,y1;
 int a=getmaxx()/2-200;
 int b=a;
 setlinestyle(SOLID_LINE,0,THICK_WIDTH);
 setcolor(RED);
 setfillstyle(SOLID_FILL,DARKGRAY);
 x=getmaxx()/2-a;  y=getmaxy()/2;
 arc(x-50,y+160,0,43,40);
 arc(x-=50,y+=160,180-43,180,40);
 line(x-40,y,x+40,y);
 x=getmaxx()/2-a;  y=getmaxy()/2;
 ellipse(x,y,170,250,40,140);
 ellipse(x-100,y,290,10,40,140);
 ellipse(x-=50,y+94,255,285,140,40);
 line(x-25,y-25,x+25,y-25);
 line(x-25,y-25,x-30,y-50);
 line(x+25,y-25,x+30,y-50);
 line(x-30,y-50,x+30,y-50);
 arc(x,y-60,335,205,20);
 if(m>157)
  floodfill(x,m+2,RED);
 line(x-1,y-79,x-1,y-100);
 line(x+1,y-79,x+1,y-100);
 line(x-10,y-89,x+10,y-89);
 line(x-10,y-90,x+10,y-90);
 ellipse(x,y+60,258,282,100,40);
 ellipse(x,y+56,258,282,100,40);
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 x1=getmaxx()-b;  y1=getmaxy()/2;
 arc(x1-50,y1+160,0,43,40);
 arc(x1-=50,y1+=160,180-43,180,40);
 line(x1-40,y1,x1+40,y1);
 x1=getmaxx()-b;  y1=getmaxy()/2;
 ellipse(x1,y1,170,250,40,140);
 ellipse(x1-100,y1,290,10,40,140);
 ellipse(x1-=50,y1+94,255,285,140,40);
 line(x1-25,y1-25,x1+25,y1-25);
 line(x1-25,y1-25,x1-30,y1-50);
 line(x1+25,y1-25,x1+30,y1-50);
 line(x1-30,y1-50,x1+30,y1-50);
 arc(x1,y1-60,335,205,20);
 circle(x1,y1-85,5);
 if(m>148)
  floodfill(x1,m+2,RED);
 ellipse(x1,y1+60,258,282,100,40);
 ellipse(x1,y1+56,258,282,100,40);
 }


void drawkq()
{int x,y,x1,y1;
 int a=getmaxx()/2-200;
 int b=a;
 setlinestyle(SOLID_LINE,0,THICK_WIDTH);
 setcolor(RED);
 setfillstyle(SOLID_FILL,DARKGRAY);
 x=getmaxx()/2-a;  y=getmaxy()/2;
 arc(x-50,y+160,0,43,40);
 arc(x-=50,y+=160,180-43,180,40);
 line(x-40,y,x+40,y);
 x=getmaxx()/2-a;  y=getmaxy()/2;
 ellipse(x,y,170,250,40,140);
 ellipse(x-100,y,290,10,40,140);
 ellipse(x-=50,y+94,255,285,140,40);
 line(x-25,y-25,x+25,y-25);
 line(x-25,y-25,x-30,y-50);
 line(x+25,y-25,x+30,y-50);
 line(x-30,y-50,x+30,y-50);
 arc(x,y-60,335,205,20);
 floodfill(x,y-65,RED);
 floodfill(x,y-45,RED);
 floodfill(x,y+150,RED);
 floodfill(x,y,RED);
 line(x-1,y-79,x-1,y-100);
 line(x+1,y-79,x+1,y-100);
 line(x-10,y-89,x+10,y-89);
 line(x-10,y-90,x+10,y-90);
 ellipse(x,y+60,258,282,100,40);
 ellipse(x,y+56,258,282,100,40);
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 x1=getmaxx()-b;  y1=getmaxy()/2;
 arc(x1-50,y1+160,0,43,40);
 arc(x1-=50,y1+=160,180-43,180,40);
 line(x1-40,y1,x1+40,y1);
 x1=getmaxx()-b;  y1=getmaxy()/2;
 ellipse(x1,y1,170,250,40,140);
 ellipse(x1-100,y1,290,10,40,140);
 ellipse(x1-=50,y1+94,255,285,140,40);
 line(x1-25,y1-25,x1+25,y1-25);
 line(x1-25,y1-25,x1-30,y1-50);
 line(x1+25,y1-25,x1+30,y1-50);
 line(x1-30,y1-50,x1+30,y1-50);
 arc(x1,y1-60,335,205,20);
 floodfill(x1,y1-65,RED);
 floodfill(x1,y1-45,RED);
 floodfill(x1,y1+150,RED);
 floodfill(x1,y1,RED);
 circle(x1,y1-85,5);
 floodfill(x1,y1-85,RED);
 ellipse(x1,y1+60,258,282,100,40);
 ellipse(x1,y1+56,258,282,100,40);
 }

void firstscreen()
{
 cleardevice();
 int x,y,x1,y1;
 setlinestyle(SOLID_LINE,0,THICK_WIDTH);
 int a=getmaxx()/2 , b=-100 ;
 settextstyle(3,0,4);
 x=220;  y=-10;
 while(1)
{ setcolor(BLUE);
  outtextxy(x,y," THE ART OF ");
  if(y==150)
   break;
  delay(100);
  setcolor(BLACK);
  outtextxy(x,y," THE ART OF ");
  y+=5; }
 settextstyle(4,0,5);
 x=235;  y=500;
 while(1)
{ setcolor(BLUE);
  outtextxy(x,y," CHESS ");
  if(y==250)
   break;
  delay(100);
  setcolor(BLACK);
  outtextxy(x,y," CHESS ");
  y-=5; }
 while(1)
{setcolor(RED);
 setfillstyle(SOLID_FILL,DARKGRAY);
 x=getmaxx()/2-a;  y=getmaxy()/2;
 arc(x-50,y+160,0,43,40);
 arc(x-=50,y+=160,180-43,180,40);
 line(x-40,y,x+40,y);
 x=getmaxx()/2-a;  y=getmaxy()/2;
 ellipse(x,y,170,250,40,140);
 ellipse(x-100,y,290,10,40,140);
 ellipse(x-=50,y+94,255,285,140,40);
 line(x-25,y-25,x+25,y-25);
 line(x-25,y-25,x-30,y-50);
 line(x+25,y-25,x+30,y-50);
 line(x-30,y-50,x+30,y-50);
 arc(x,y-60,335,205,20);
 floodfill(x,y-65,RED);
 floodfill(x,y-45,RED);
 floodfill(x,y+150,RED);
 floodfill(x,y,RED);
 line(x-1,y-79,x-1,y-100);
 line(x+1,y-79,x+1,y-100);
 line(x-10,y-89,x+10,y-89);
 line(x-10,y-90,x+10,y-90);
 ellipse(x,y+60,258,282,100,40);
 ellipse(x,y+56,258,282,100,40);
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 x1=getmaxx()-b;  y1=getmaxy()/2;
 arc(x1-50,y1+160,0,43,40);
 arc(x1-=50,y1+=160,180-43,180,40);
 line(x1-40,y1,x1+40,y1);
 x1=getmaxx()-b;  y1=getmaxy()/2;
 ellipse(x1,y1,170,250,40,140);
 ellipse(x1-100,y1,290,10,40,140);
 ellipse(x1-=50,y1+94,255,285,140,40);
 line(x1-25,y1-25,x1+25,y1-25);
 line(x1-25,y1-25,x1-30,y1-50);
 line(x1+25,y1-25,x1+30,y1-50);
 line(x1-30,y1-50,x1+30,y1-50);
 arc(x1,y1-60,335,205,20);
 floodfill(x1,y1-65,RED);
 floodfill(x1,y1-45,RED);
 floodfill(x1,y1+150,RED);
 floodfill(x1,y1,RED);
 circle(x1,y1-85,5);
 floodfill(x1,y1-85,RED);
 ellipse(x1,y1+60,258,282,100,40);
 ellipse(x1,y1+56,258,282,100,40);
 delay(50);
 if(a<=getmaxx()/2-195)
  break;
 setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLACK);
 floodfill(x,y-65,RED);
 floodfill(x,y-45,RED);
 floodfill(x,y+150,RED);
 floodfill(x,y,RED);
 floodfill(x,y+98,RED);
 floodfill(x,y+110,RED);
 x=getmaxx()/2-a;  y=getmaxy()/2;
 arc(x-50,y+160,0,43,40);
 arc(x-=50,y+=160,180-43,180,40);
 line(x-40,y,x+40,y);
 x=getmaxx()/2-a;  y=getmaxy()/2;
 ellipse(x,y,170,250,40,140);
 ellipse(x-100,y,290,10,40,140);
 ellipse(x-=50,y+94,255,285,140,40);
 line(x-25,y-25,x+25,y-25);
 line(x-25,y-25,x-30,y-50);
 line(x+25,y-25,x+30,y-50);
 line(x-30,y-50,x+30,y-50);
 arc(x,y-60,335,205,20);
 line(x-1,y-79,x-1,y-100);
 line(x+1,y-79,x+1,y-100);
 line(x-10,y-89,x+10,y-89);
 line(x-10,y-90,x+10,y-90);
 ellipse(x,y+60,258,282,100,40);
 ellipse(x,y+56,258,282,100,40);
 floodfill(x1,y1-65,RED);
 floodfill(x1,y1-45,RED);
 floodfill(x1,y1+150,RED);
 floodfill(x1,y1,RED);
 floodfill(x1,y1-85,RED);
 floodfill(x1,y1+98,RED);
 floodfill(x1,y1+110,RED);
 x1=getmaxx()-b;  y1=getmaxy()/2;
 arc(x1-50,y1+160,0,43,40);
 arc(x1-=50,y1+=160,180-43,180,40);
 line(x1-40,y1,x1+40,y1);
 x1=getmaxx()-b;  y1=getmaxy()/2;
 ellipse(x1,y1,170,250,40,140);
 ellipse(x1-100,y1,290,10,40,140);
 ellipse(x1-=50,y1+94,255,285,140,40);
 line(x1-25,y1-25,x1+25,y1-25);
 line(x1-25,y1-25,x1-30,y1-50);
 line(x1+25,y1-25,x1+30,y1-50);
 line(x1-30,y1-50,x1+30,y1-50);
 arc(x1,y1-60,335,205,20);
 circle(x1,y1-85,5);
 ellipse(x1,y1+60,258,282,100,40);
 ellipse(x1,y1+56,258,282,100,40);
 a-=5;  b+=5;
}
 setcolor(RED);
 x=getmaxx()/2;
 y=400;
 setfillstyle(SOLID_FILL,BROWN);
 ellipse(x,y,61,119,300,50);
 ellipse(x,y,134,46,300,50);
 floodfill(x,y,RED);
 settextstyle(1,0,1);
 setcolor(BLACK);
 outtextxy(x-120,y,"Press any key to continue ... ");
 getch();
 cleardevice();
}

void load()
{
  cleardevice();
  int n;
//  setbkcolor(RED);

  setcolor(WHITE);
  settextstyle(1,0,1);
  outtextxy(275,220,"LOADING");
  randomize();
  int x=0,temp;
  char text[3];
  text[2]='\0';

  for(float y=getmaxy()-81;y>138&&!kbhit();y-=2.61,x++)
  {
    n=random(30);
    temp=x;
    setcolor(WHITE);
    text[1]=(char)(temp%10)+48;
    temp/=10;
    text[0]=(char)(temp%10)+48;
    if(x<10)
    { text[0]=(char)(x%10)+48;
      text[1]='\0';  }
    outtextxy(getmaxx()/2-20,getmaxy()/2,text);
    delay(10*n);
    setcolor(RED);
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    line(100,y,195,y);
    line(420,y,515,y);
    drawkq(y);
    setcolor(BLACK);
    outtextxy(getmaxx()/2-20,getmaxy()/2,text);
    line(100,y,195,y);
    line(420,y,515,y);  }
}


void secondscreen(int z)
{
 cleardevice();
 delay(100);
 drawkq();
 setlinestyle(SOLID_LINE,0,NORM_WIDTH);
// rectangle(230,185,400,160);
// rectangle(220,225,405,200);
// rectangle(280,265,335,240);
// rectangle(265,305,345,280);
// rectangle(280,345,330,320);
 setcolor(WHITE);
 settextstyle(1,0,1);
 if(z==0)
  setcolor(DARKGRAY);
 outtextxy(235,160,"RETURN TO GAME");
 setcolor(WHITE);
 outtextxy(225,200,"START A NEW GAME");
 outtextxy(285,240,"HELP");
 outtextxy(270,280,"CREDITS");
 outtextxy(285,320,"QUIT");
 int Mstatus = initmouse();
 int button,m,n;
 if(Mstatus == 0 )
  outtextxy(50,50, "Mouse Support Not Available");

// changecursor(cursor);
 while(1)
{ showmouseptr();
  getmousepos(&button,&m,&n);
  if(m>230 && m<400 && n>160 && n<185 && z!=0)
  { setcolor(RED);
    outtextxy(235,160,"RETURN TO GAME"); }
  else
  { if(z==0)
     setcolor(DARKGRAY);
    else
     setcolor(WHITE);
    outtextxy(235,160,"RETURN TO GAME");
  if(m>220 && m<405 && n>200 && n<225)
  { setcolor(RED);
    outtextxy(225,200,"START A NEW GAME"); }
  else
  { setcolor(WHITE);
    outtextxy(225,200,"START A NEW GAME");
  if(m>280 && m<335 && n>240 && n<265)
  { setcolor(RED);
    outtextxy(285,240,"HELP");  }
  else
  { setcolor(WHITE);
    outtextxy(285,240,"HELP");
  if(m>265 && m<345 && n>280 && n<305)
  { setcolor(RED);
    outtextxy(270,280,"CREDITS");  }
  else
  { setcolor(WHITE);
    outtextxy(270,280,"CREDITS");
  if(m>280 && m<330 && n>320 && n<345)
  { setcolor(RED);
    outtextxy(285,320,"QUIT");  }
  else
  { setcolor(WHITE);
    outtextxy(285,320,"QUIT"); }}}}}
  if(button == 1)
  { if(m>220 && m<405 && n>200 && n<225)
    { hidemouseptr();
//      load();
      spawnle(P_WAIT, "g:\exefil~1\chess.exe", NULL);
      break;  }
    if(m>280 && m<335 && n>240 && n<265)
    { hidemouseptr();
      HELP(z);  }
    if(m>280 && m<330 && n>320 && n<345)
     exit(0); }}}


void HELP(int z)
{  cleardevice();
   delay(100);
   drawkq();
   setlinestyle(SOLID_LINE,0,NORM_WIDTH);
// rectangle(245,245,375,220);
// rectangle(260,285,355,260);
// rectangle(280,325,335,300);

 setcolor(WHITE);
 settextstyle(1,0,1);
 outtextxy(250,220,"HOW TO PLAY");
 outtextxy(265,260,"CONTROLS");
 outtextxy(285,300,"BACK");

 int button,m,n;
 while(1)
{ showmouseptr();
  getmousepos(&button,&m,&n);
  if(m>245 && m<375 && n>220 && n<245)
  { setcolor(RED);
    outtextxy(250,220,"HOW TO PLAY");  }
  else
  { setcolor(WHITE);
    outtextxy(250,220,"HOW TO PLAY");
  if(m>260 && m<355 && n>260 && n<285)
  { setcolor(RED);
    outtextxy(265,260,"CONTROLS");  }
  else
  { setcolor(WHITE);
    outtextxy(265,260,"CONTROLS");
  if(m>280 && m<335 && n>300 && n<325)
  { setcolor(RED);
    outtextxy(285,300,"BACK"); }
  else
  { setcolor(WHITE);
    outtextxy(285,300,"BACK"); }}}
  if(button == 1)
  { if(m>280 && m<335 && n>300 && n<325)
    { hidemouseptr();
      secondscreen(z); }
    if(m>260 && m<355 && n>260 && n<285)
    { hidemouseptr();
      controls(z); }
    if(m>245 && m<375 && n>220 && n<245)
    { hidemouseptr();
      howtoplay(z); }}}}

void controls(int z)
{cleardevice();
 delay(100);
 int button,m,n;
 //  rectangle(getmaxx()/2-30,getmaxy()-40,getmaxx()/2+20,getmaxy()-25);

 settextstyle(5,0,2);
 setcolor(RED);
 outtextxy(getmaxx()/2-150,30,"CONTROLS AND HOW TO USE");
 settextstyle(3,0,1);
 setcolor(BLUE);
 outtextxy(50,125,"MOUSES");
 settextstyle(2,0,5);
 for(int y=150,p=1;p<=5;y+=20,p++)
 { switch(p)
 { case 1:outtextxy(50,y,"1. Left click for selecting or disselecting the coin.");
	  break;
   case 2:outtextxy(50,y,"2. Left click on any other square for moving the coin to that square.");
	  break;
   case 3:outtextxy(50,y,"3. Left click for selecting the object.");
	  break;
   case 4:outtextxy(50,y,"1. Left click for selecting the object.");
	  break;
   case 5:outtextxy(50,y,"1. Left click for selecting the object.");
	  break;   }}
 setcolor(WHITE);
 settextstyle(2,0,7);
 outtextxy(getmaxx()/2-30,getmaxy()-45,"BACK");
 while(!kbhit())
{ showmouseptr();
  getmousepos(&button,&m,&n);
 if(m>getmaxx()/2-30 && m<getmaxx()/2+20 &&
    n<getmaxy()-25 && n>getmaxy()-40 )
{ setcolor(RED);
  outtextxy(getmaxx()/2-30,getmaxy()-45,"BACK");  }
 else
{ setcolor(WHITE);
  outtextxy(getmaxx()/2-30,getmaxy()-45,"BACK");  }
 if(button==1)
 if(m>getmaxx()/2-30 && m<getmaxx()/2+20 &&
    n<getmaxy()-25 && n>getmaxy()-40 )
 { hidemouseptr();
   HELP(z); }}}

void howtoplay(int z)
{cleardevice();
 delay(100);
 int button,m,n;
 settextstyle(3,0,1);
 setcolor(WHITE);
 outtextxy(50,50,"Select the coin :");
 settextstyle(3,0,1);
 setcolor(WHITE);
 outtextxy(300,400,"BACK");
// setvalues();

  pawn(200,200,black);
  rook(200+43,200,black);
  bishop(200+43*2,200,black);
  knight(200+43*3,200,black);
  king(200+43*4,200,black);
  queen(200+43*5,200,black);
// rectangle(150,160,400,200);
// rectangle(295,400,350,425);
 while(!kbhit())
{ showmouseptr();
  getmousepos(&button,&m,&n);
  if(m>295 && m<350 && n<425 && n>400)
  { setcolor(RED);
    outtextxy(300,400,"BACK");  }
  else
  { setcolor(WHITE);
    outtextxy(300,400,"BACK");  }
  if(button == 1)
  { if(m>295 && m<350 && n<425 && n>400)
    { hidemouseptr();
      HELP(z);  }
    if(m>150 && m<400 && n<200 && n>160)
    { hidemouseptr();
      exit(0); }}}}

/*void circle()
{ cleardevice();
  delay(100);
  int x=100,y=0;
  float radiens,x1,y1;
  float rad,x2,y2;
  void balls(int &i,int &j,float &degree,float &deg,int r)
{
  if(i==getmaxx()/2)
  {
   radiens=(M_PI/180)*degree;
   x1=x*cos(radiens)+y*sin(radiens);
   y1=-x*sin(radiens)+y*cos(radiens);
   x1+=getmaxx()/2;
   y1+=getmaxy()/2;
   rad=(M_PI/180)*deg;
   x2=x*cos(rad)+y*sin(rad);
   y2=-x*sin(rad)+y*cos(rad);
   x2+=getmaxx()/2;
   y2+=getmaxy()/2;
   setfillstyle(SOLID_FILL,RED);
   setcolor(WHITE);
   circle(x1,y1,r);
   floodfill(x1,y1,WHITE);
   circle(x2,y2,r);
   floodfill(x2,y2,WHITE);
   delay(5);
   setfillstyle(SOLID_FILL,BLACK);
   setcolor(BLACK);
   floodfill(x1,y1,WHITE);
   floodfill(x2,y2,WHITE);
   circle(x1,y1,r);
   circle(x2,y2,r);
   degree++;
   deg++;
  }
  else
  {  setfillstyle(SOLID_FILL,RED);
     setcolor(WHITE);
     circle(i,(getmaxy()/2)-100,r);
     floodfill(i,(getmaxy()/2)-100,WHITE);
     circle(j,(getmaxy()/2)+100,r);
     floodfill(j,(getmaxy()/2)+100,WHITE);
     delay(5);
     setfillstyle(SOLID_FILL,BLACK);
     floodfill(i,(getmaxy()/2)-100,WHITE);
     floodfill(j,(getmaxy()/2)+100,WHITE);
     setcolor(BLACK);
     circle(i,(getmaxy()/2)-100,r);
     circle(j,(getmaxy()/2)+100,r);
     i--; j++;  }
}
 int i=getmaxx(),j=0;
 int a=getmaxx()+20,b=-20;
 int p=getmaxx()+38,q=-38;
 float degree1=90,deg1=270;
 float degree2=90,deg2=270;
 float degree3=90,deg3=270;
 while(!kbhit())
 {
       balls(i,j,degree1,deg1,10);
       balls(a,b,degree2,deg2,8);
       balls(p,q,degree3,deg3,6);
 }}

  */
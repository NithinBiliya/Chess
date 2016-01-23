
void drawkq(float);

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

//		VIDEO FUNCTIONS

#include<string.h>

void video(int x1,int y1)
{ setcolor(WHITE);
  x1=x1-75; y1=y1+65;
  line(x1,y1,x1,y1+35);
  line(x1,y1,x1,y1+35);
  x1=x1+75; y1=y1-65;
  x1=x1-75; y1=y1+65;
  float a=92,d=30,b=a;
  float x2,y2,x5,y5,x3,y3,x4,y4,x9,y9,
	x6,y6,x7,y7,x8,y8;
  while(a>=90)
  { x2=x1+d*cos(a);
    y2=y1+d*sin(a);
    x3=x1+d*cos(a);
    y3=y1+35+(d*sin(a));
    x4=x1+(d+3)*cos(a);
    y4=y1+35+((d+3)*sin(a));
    x5=x1+(d+3)*cos(a);
    y5=y1+(d+3)*sin(a);
    x6=x1+(d+3)*cos(a);
    y6=(y1+18)+(d+3)*sin(a);
    x7=x1+(d+150)*cos(a);
    y7=(y1+18)+(d+150)*sin(a);
    x8=x1+(d+150)*cos(a);
    y8=(y1+10)+(d+150)*sin(a);
    x9=x1+(d+3)*cos(a);
    y9=(y1+10)+(d+3)*sin(a);
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
    delay(10);
    setcolor(BLACK);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
    a-=0.01; }
  setfillstyle(SOLID_FILL,BLACK);
  bar(180,73,370,365);
  while(a<=b)
  { x2=x1+d*cos(a);
    y2=y1+d*sin(a);
    x3=x1+d*cos(a);
    y3=y1+35+(d*sin(a));
    x4=x1+(d+3)*cos(a);
    y4=y1+35+((d+3)*sin(a));
    x5=x1+(d+3)*cos(a);
    y5=y1+(d+3)*sin(a);
    x6=x1+(d+3)*cos(a);
    y6=(y1+18)+(d+3)*sin(a);
    x7=x1+(d+150)*cos(a);
    y7=(y1+18)+(d+150)*sin(a);
    x8=x1+(d+150)*cos(a);
    y8=(y1+10)+(d+150)*sin(a);
    x9=x1+(d+3)*cos(a);
    y9=(y1+10)+(d+3)*sin(a);
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7);
    delay(10);
    if(a!=b) {
    setcolor(BLACK);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x1,y1,x2,y2);
    line(x1,y1+35,x3,y3);
    line(x2,y2,x3,y3);
    line(x4,y4,x5,y5);
    line(x6,y6,x7,y7);
    line(x8,y8,x9,y9);
    line(x8,y8,x7,y7); }
    a+=0.01;  }
}

void king(char name[30])                //  for king
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

void animationvideo(char name[30])               // opening ani files
{     struct animation
      { char obj[6];
	int x,y,c; }object;
      struct coordinates
      { int x,y; }coor;
      int count=0,m,n;
      fstream file;
      file.open(name,ios::binary|ios::in);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      setcolor(WHITE);
      file.read((char*)&object,sizeof(object));
      while(!file.eof())
      { file.read((char*)&coor,sizeof(coor));
	if(coor.x==-240 && coor.y==-240)
	{ file.read((char*)&coor,sizeof(coor));
	  m=coor.x;  n=coor.y; }
	if(coor.x==-20 && coor.y==-20)
	{ file.read((char*)&object,sizeof(object));
	  file.read((char*)&coor,sizeof(coor));
	  count=0;  }
	if(!strcmp(object.obj,"rect"))
	{ setcolor(WHITE);
	  setfillstyle(SOLID_FILL,object.c);
	  rectangle(coor.x,coor.y,coor.x+object.x,coor.y+object.y);
	  floodfill(coor.x+(object.x/2),coor.y+(object.y/2),WHITE);
	  delay(10);
	  setfillstyle(SOLID_FILL,BLACK);
	  floodfill(coor.x+(object.x/2),coor.y+(object.y/2),WHITE);
	  setcolor(BLACK);
	  rectangle(coor.x,coor.y,coor.x+object.x,coor.y+object.y);  }
	else if(!strcmp(object.obj,"cir"))
	{ setcolor(WHITE);
	  setfillstyle(SOLID_FILL,object.c);
	  ellipse(coor.x,coor.y,0,360,(object.x/2),(object.y/2));
	  floodfill(coor.x,coor.y,WHITE);
	  delay(10);
	  setfillstyle(SOLID_FILL,BLACK);
	  floodfill(coor.x,coor.y,WHITE);
	  setcolor(BLACK);
	  ellipse(coor.x,coor.y,0,360,(object.x/2),(object.y/2)); }
	else if(!strcmp(object.obj,"line"))
	{ setcolor(object.c);
	  if(count==0)
	  { line(coor.x,coor.y,coor.x,coor.y);
	    count++; }
	  else
	   line(m,n,coor.x,coor.y);
	  delay(10);
	  m=coor.x;  n=coor.y;  }}
      file.close();  }
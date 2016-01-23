//		LOAD

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
#include<string.h>

//void save11(char[30]);
void open11(char[30],char);

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();
 char name[30]={"ch2"};
 open11(name,'N');
 strcpy(name,"ch3");
 open11(name,'Y');
 closegraph();
}

/*void save11(char name[30])
{     fstream file;
      file.open(name,ios::binary|ios::out);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      unsigned color;
      for(int j=getmaxy();j>0;j--)
       for(int i=getmaxx();i>0;i--)
       { color=getpixel(i,j);
	 file.write((char*)&color,sizeof(color)); }
      file.close();
     setfillstyle(SOLID_FILL,BLACK);
     bar(200,150,450,250);
     outtextxy(250,200,"Save Complete");  }*/
void open11(char name[30],char ch)
{     fstream file;
      file.open(name,ios::binary|ios::in);
      randomize();
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      unsigned color;
      int i;
      file.read((char*)&color,sizeof(color));
      for(int j=getmaxy();j>0;j--)
      { for(i=getmaxx();i>0;i--)
	{ putpixel(i,j,color);
	  file.read((char*)&color,sizeof(color)); }
       if(ch=='Y')
	if( j>150 && j<400 )
	 delay(random(15)*10);  }
      putpixel(i,j,color);
      file.close();  }

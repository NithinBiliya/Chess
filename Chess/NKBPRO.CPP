//		NKB PRODUCTS

#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>

void video(char [30]);

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 delay(500);

 video("NKB1");
 video("NKB2");
 video("NKB3");
 video("NKB4");
 video("NKB5");
 video("NKB6");
 video("NKB7");
 spawnl(P_WAIT,"intro.exe", NULL);   // intro video
 closegraph();
}

void video(char name[30])
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

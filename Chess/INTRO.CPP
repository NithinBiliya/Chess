//		Chess Intro

#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>
#include<math.h>
#include<process.h>

void pic(char [30]);

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");
 cleardevice();
 delay(500);
 char ch[2];
 int a,b;
 pic("intro");

 for(int i=1;i<=8;i++)
 { a=getmaxx()+50;
   if(i==1)
   { settextstyle(5,0,3);
     strcpy(ch,"H");  b=200;  }
   else if(i==2)
   { strcpy(ch,"E");  b=226;  }
   else if(i==3)
   { strcpy(ch,"R");  b=330;  }
   else if(i==4)
   { strcpy(ch,"T");  b=356;  }
   else if(i==5)
   { strcpy(ch,"O");  b=436;  }
   else if(i==6)
   { strcpy(ch,"F");  b=452;  }
   else if(i==7)
   { strcpy(ch,"T");  b=170;  }
   else if(i==8)
   { strcpy(ch,"A");  b=300;  }
   while(a>=b)
   { setcolor(WHITE);
     if(i==7||i==8)
     { settextstyle(5,0,3);
       outtextxy(201,325,"H");
       outtextxy(227,325,"E");
       outtextxy(331,325,"R");
       outtextxy(357,325,"T");
       outtextxy(437,325,"O");
       outtextxy(453,325,"F");
       settextstyle(5,0,5);
       outtextxy(a,303,ch);	 }
     else outtextxy(a,325,ch);
     delay(10);
     setcolor(BLACK);
     if(a!=b+1)
     { if(i==7||i==8)
	outtextxy(a,303,ch);
       else outtextxy(a,325,ch);  }
     a-=2;  }}
  settextstyle(10,0,5);
  for(i=1;i<=5;i++)
 { a=getmaxy()+50;
   if(i==1)
   { strcpy(ch,"C");  b=200;  }
   else if(i==2)
   { strcpy(ch,"H");  b=250;  }
   else if(i==3)
   { strcpy(ch,"E");  b=300;  }
   else if(i==4)
   { strcpy(ch,"S");  b=350;  }
   else if(i==5)
   { strcpy(ch,"S");  b=400;  }
   while(a>=getmaxy()-120)
   { setcolor(WHITE);
     outtextxy(b,a,ch);
     delay(10);
     setcolor(BLACK);
     if(a!=getmaxy()-120)
      outtextxy(b,a,ch);
     a-=2;  }}
 setfillstyle(SOLID_FILL,BLACK);
 bar(0,getmaxy()-120,getmaxx(),getmaxy());
 long degree=0,degree1;
 float x1,y1,radiens,x=10,y=0;
 b=getmaxy()-120;
 while(degree<=1500)
 { for(i=1;i<=5;i++)
  { if(i==1)
    { degree1=degree;
      a=200;
      strcpy(ch,"C"); }
    else if(i==2)
    { degree1=degree+60;
      a=250;
      strcpy(ch,"H"); }
    else if(i==3)
    { degree1=degree+120;
      a=300;
      strcpy(ch,"E"); }
    else if(i==4)
    { degree1=degree+180;
      a=350;
      strcpy(ch,"S"); }
    else if(i==5)
    { degree1=degree+240;
      a=400;
      strcpy(ch,"S"); }
   radiens=(M_PI/180)*degree1;
   x1=x*cos(radiens)+y*sin(radiens);
   y1=-x*sin(radiens)+y*cos(radiens);
   x1+=a;
   y1+=b;
   setcolor(WHITE);
   outtextxy(x1,y1,ch);              }
   delay(10);
   for(i=1;i<=5;i++)
  { if(i==1)
    { degree1=degree;
      a=200;
      strcpy(ch,"C"); }
    else if(i==2)
    { degree1=degree+60;
      a=250;
      strcpy(ch,"H"); }
    else if(i==3)
    { degree1=degree+120;
      a=300;
      strcpy(ch,"E"); }
    else if(i==4)
    { degree1=degree+180;
      a=350;
      strcpy(ch,"S"); }
    else if(i==5)
    { degree1=degree+240;
      a=400;
      strcpy(ch,"S"); }
   radiens=(M_PI/180)*degree1;
   x1=x*cos(radiens)+y*sin(radiens);
   y1=-x*sin(radiens)+y*cos(radiens);
   x1+=a;
   y1+=b;
   if(degree!=1500)
   { setcolor(BLACK);
     outtextxy(x1,y1,ch);  }}
   degree++;  }
 spawnl(P_WAIT,"menu1.exe", NULL);  // main menu
 exit(0);
}

void pic(char name[30])
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
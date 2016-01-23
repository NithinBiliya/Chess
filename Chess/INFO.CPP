#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>

void main()
{ clrscr();
  int esc=27,opt;  char ch;
  cin>>opt;
  if(opt==1) {
  fstream file;
  file.open("Info.TXT",ios::app|ios::binary);
  if(!file)
  { cout<<"File couldnt be opened";
    getch();  exit(0); }
  cout<<"\n\n\t\tType the info. : \n\n";
  ch=getche();
  while(ch!=esc)
  { if(ch=='\r')
    { ch='\n';
      cout<<ch; }
    file.put(ch);
    ch=getche(); }
  file.close(); }
  else {
  clrscr();
  fstream file;
  file.open("Info.TXT",ios::in|ios::binary);
  if(!file)
  { cout<<"File couldnt be opened";
    getch();  exit(0); }
  cout<<"\n\n\tInfo. : \n\n";
  file.get(ch);
  while(!file.eof())
  { if(ch=='*')
     getch();
    else
     cout<<ch;
    if(ch=='\n')
     cout<<ch;
    delay(10);
    file.get(ch); }
  file.close(); }
 getch();
}


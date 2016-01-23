

enum{ null=-1,black,white };
enum{ yes,no };
struct box
{ int x,y;
  char coin;
  int color;
  int occblack;
  int occwhite;  };
/*struct mate
{ int a,b; };*/
box A[8][8];
//mate blackmate,whitemate;
int stop;
//,sign=-1,c,tempcolor;
//char tempcoin;
int help=yes;
//,blackcheck=no,whitecheck=no;

void pawn(int,int,int);
void rook(int,int,int);
void bishop(int,int,int);
void knight(int,int,int);
void king(int,int,int);
void queen(int,int,int);
void redraw();
void main();
/*
void boxes(int i,int j)
{ setcolor(RED);
     if(A[i][j].coin=='P' && A[i][j].color==black)   // Black pawn
     { if(A[i+1][j].coin=='N')
	rectangle(A[i+1][j].x,A[i+1][j].y,A[i+1][j].x+43,A[i+1][j].y+43);
       if(i==1 && A[i+2][j].coin=='N')
	rectangle(A[i+2][j].x,A[i+2][j].y,A[i+2][j].x+43,A[i+2][j].y+43);
       if(A[i+1][j+1].color==white)
	rectangle(A[i+1][j+1].x,A[i+1][j+1].y,A[i+1][j+1].x+43,A[i+1][j+1].y+43);
       if(A[i+1][j-1].color==white)
	rectangle(A[i+1][j-1].x,A[i+1][j-1].y,A[i+1][j-1].x+43,A[i+1][j-1].y+43);  }
     else if(A[i][j].coin=='P' && A[i][j].color==white)   // White pawn
     { if(A[i-1][j].coin=='N')
	rectangle(A[i-1][j].x,A[i-1][j].y,A[i-1][j].x+43,A[i-1][j].y+43);
       if(i==6 && A[i-2][j].coin=='N')
	rectangle(A[i-2][j].x,A[i-2][j].y,A[i-2][j].x+43,A[i-2][j].y+43);
       if(A[i-1][j+1].color==black)
	rectangle(A[i-1][j+1].x,A[i-1][j+1].y,A[i-1][j+1].x+43,A[i-1][j+1].y+43);
       if(A[i-1][j-1].color==black)
	rectangle(A[i-1][j-1].x,A[i-1][j-1].y,A[i-1][j-1].x+43,A[i-1][j-1].y+43);  }
     else if(A[i][j].coin=='H' && A[i][j].color==black)   // Black knight
     { if(A[i-2][j-1].color!=black && (i!=0||i!=1||j!=0))
	rectangle(A[i-2][j-1].x,A[i-2][j-1].y,A[i-2][j-1].x+43,A[i-2][j-1].y+43);
       if(A[i-2][j+1].color!=black && (i!=0||i!=1||j!=7))
	rectangle(A[i-2][j+1].x,A[i-2][j+1].y,A[i-2][j+1].x+43,A[i-2][j+1].y+43);
       if(A[i+2][j-1].color!=black && (i!=7||i!=6||j!=0))
	rectangle(A[i+2][j-1].x,A[i+2][j-1].y,A[i+2][j-1].x+43,A[i+2][j-1].y+43);
       if(A[i+2][j+1].color!=black && (i!=7||i!=6||j!=7))
	rectangle(A[i+2][j+1].x,A[i+2][j+1].y,A[i+2][j+1].x+43,A[i+2][j+1].y+43);
       if(A[i-1][j-2].color!=black && (i!=0||j!=1||j!=0))
	rectangle(A[i-1][j-2].x,A[i-1][j-2].y,A[i-1][j-2].x+43,A[i-1][j-2].y+43);
       if(A[i-1][j+2].color!=black && (i!=0||j!=7||j!=6))
	rectangle(A[i-1][j+2].x,A[i-1][j+2].y,A[i-1][j+2].x+43,A[i-1][j+2].y+43);
       if(A[i+1][j-2].color!=black && (i!=7||j!=1||j!=0))
	rectangle(A[i+1][j-2].x,A[i+1][j-2].y,A[i+1][j-2].x+43,A[i+1][j-2].y+43);
       if(A[i+1][j+2].color!=black && (i!=7||j!=7||j!=6))
	rectangle(A[i+1][j+2].x,A[i+1][j+2].y,A[i+1][j+2].x+43,A[i+1][j+2].y+43);  }
     else if(A[i][j].coin=='H' && A[i][j].color==white)    // White knight
     { if(A[i-2][j-1].color!=white)
	rectangle(A[i-2][j-1].x,A[i-2][j-1].y,A[i-2][j-1].x+43,A[i-2][j-1].y+43);
       if(A[i-2][j+1].color!=white)
	rectangle(A[i-2][j+1].x,A[i-2][j+1].y,A[i-2][j+1].x+43,A[i-2][j+1].y+43);
       if(A[i+2][j-1].color!=white)
	rectangle(A[i+2][j-1].x,A[i+2][j-1].y,A[i+2][j-1].x+43,A[i+2][j-1].y+43);
       if(A[i+2][j+1].color!=white)
	rectangle(A[i+2][j+1].x,A[i+2][j+1].y,A[i+2][j+1].x+43,A[i+2][j+1].y+43);
       if(A[i-1][j-2].color!=white)
	rectangle(A[i-1][j-2].x,A[i-1][j-2].y,A[i-1][j-2].x+43,A[i-1][j-2].y+43);
       if(A[i-1][j+2].color!=white)
	rectangle(A[i-1][j+2].x,A[i-1][j+2].y,A[i-1][j+2].x+43,A[i-1][j+2].y+43);
       if(A[i+1][j-2].color!=white)
	rectangle(A[i+1][j-2].x,A[i+1][j-2].y,A[i+1][j-2].x+43,A[i+1][j-2].y+43);
       if(A[i+1][j+2].color!=white)
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
     { if(A[i-1][j-1].color!=black)
	rectangle(A[i-1][j-1].x,A[i-1][j-1].y,A[i-1][j-1].x+43,A[i-1][j-1].y+43);
       if(A[i-1][j].color!=black)
	rectangle(A[i-1][j].x,A[i-1][j].y,A[i-1][j].x+43,A[i-1][j].y+43);
       if(A[i-1][j+1].color!=black)
	rectangle(A[i-1][j+1].x,A[i-1][j+1].y,A[i-1][j+1].x+43,A[i-1][j+1].y+43);
       if(A[i][j-1].color!=black)
	rectangle(A[i][j-1].x,A[i][j-1].y,A[i][j-1].x+43,A[i][j-1].y+43);
       if(A[i][j+1].color!=black)
	rectangle(A[i][j+1].x,A[i][j+1].y,A[i][j+1].x+43,A[i][j+1].y+43);
       if(A[i+1][j-1].color!=black)
	rectangle(A[i+1][j-1].x,A[i+1][j-1].y,A[i+1][j-1].x+43,A[i+1][j-1].y+43);
       if(A[i+1][j].color!=black)
	rectangle(A[i+1][j].x,A[i+1][j].y,A[i+1][j].x+43,A[i+1][j].y+43);
       if(A[i+1][j+1].color!=black)
	rectangle(A[i+1][j+1].x,A[i+1][j+1].y,A[i+1][j+1].x+43,A[i+1][j+1].y+43);  }
     else if(A[i][j].coin=='K' && A[i][j].color==white)   // White king
     { if(A[i-1][j-1].color!=white)
	rectangle(A[i-1][j-1].x,A[i-1][j-1].y,A[i-1][j-1].x+43,A[i-1][j-1].y+43);
       if(A[i-1][j].color!=white)
	rectangle(A[i-1][j].x,A[i-1][j].y,A[i-1][j].x+43,A[i-1][j].y+43);
       if(A[i-1][j+1].color!=white)
	rectangle(A[i-1][j+1].x,A[i-1][j+1].y,A[i-1][j+1].x+43,A[i-1][j+1].y+43);
       if(A[i][j-1].color!=white)
	rectangle(A[i][j-1].x,A[i][j-1].y,A[i][j-1].x+43,A[i][j-1].y+43);
       if(A[i][j+1].color!=white)
	rectangle(A[i][j+1].x,A[i][j+1].y,A[i][j+1].x+43,A[i][j+1].y+43);
       if(A[i+1][j-1].color!=white)
	rectangle(A[i+1][j-1].x,A[i+1][j-1].y,A[i+1][j-1].x+43,A[i+1][j-1].y+43);
       if(A[i+1][j].color!=white)
	rectangle(A[i+1][j].x,A[i+1][j].y,A[i+1][j].x+43,A[i+1][j].y+43);
       if(A[i+1][j+1].color!=white)
	rectangle(A[i+1][j+1].x,A[i+1][j+1].y,A[i+1][j+1].x+43,A[i+1][j+1].y+43);  }}
  */
void dontsetvalues()
{ for(int i=0,n=0;i<8;i++,n+=43)
   for(int j=0,m=0;j<8;j++,m+=43)
   { A[i][j].x=150+m;
     A[i][j].y=60+n;
     A[i][j].coin='N';
     A[i][j].color=null;
     A[i][j].occblack=no;
     A[i][j].occwhite=no; }}

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

void getpos(int &i,int &j,char &s)
{ if(s=='S' || s=='s')
   s='5';
  else if(s=='0')
   exit(0);
/*  if(s=='m' || s=='M')
   mainmenu();*/
  else if(s=='r' || s=='R')
   main();
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

void redraw()
{ setcolor(WHITE);
  for(int a=0;a<8;a++)
   for(int b=0;b<8;b++)
    rectangle(A[a][b].x,A[a][b].y,A[a][b].x+43,A[a][b].y+43);  }

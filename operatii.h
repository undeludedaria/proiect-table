#include <stdlib.h>
#include <iostream>
#include <termios.h>
#include <stdio.h>

using namespace std;

extern char col;
char inpheader;
bool juc=0, term=1;


static struct termios old, current;

void initTermios(int echo) 
{
  tcgetattr(0, &old); 
  current = old; 
  current.c_lflag &= ~ICANON; 
  if (echo) {
      current.c_lflag |= ECHO; 
  } else {
      current.c_lflag &= ~ECHO; 
  }
  tcsetattr(0, TCSANOW, &current); 
}

void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

char getch(void) 
{
  return getch_(0);
}


struct locpi{
	int x;
	int y;
	bool c;
	locpi*leg;

};

struct layout{
	int info;
	bool c;
};

layout lay[24];

locpi*l;
locpi*q;
locpi*p;



void muta(int i, int j){
	lay[i].info--;
	lay[j].info++;
	lay[j].c=lay[i].c;
}

void afiseaza(){
	for(int i=0; i<90; i++){
		for(int j=0; j<250; j++){
			cout << tabla[i][j];
		}
	cout << endl;
	} 
}

void reset_tabla(){
	l=p;
	while(l){
		for(int i=l->y; i<l->y+5; i++){
			if(i==l->y || i==l->y+4){
				for(int j=l->x+3; j<l->x+11; j++){
					tabla[i][j]=emptyT[i][j];
				}
			}else if(i==l->y+1 || i==l->y+3){
				for(int j=l->x+1; j<l->x+13; j++){
					tabla[i][j]=emptyT[i][j];
				}
			}else if(i==l->y+2){
				for(int j=l->x; j<l->x+14; j++){
					tabla[i][j]=emptyT[i][j];
				}
			}
		}
		l=l->leg;
	}


}

void sync(){
				bool prim=1;
				int xp=12;
				int yp=7;
				for(int i=0; i<12; i++){

					yp=7;
					for(int j=0; j<lay[i].info; j++){
						l=new locpi;
						if(prim){
							p=l;
							prim=0;		
						}else{
							q->leg=l;
						
						}
						q=l;
						q->leg=NULL;
						l->x=xp;
						l->y=yp;
						l->c=lay[i].c;	
						yp+=6;
					}
					if(i==5)
						xp+=33;
					else	
						xp+=18;

				}
				xp=224;

				for(int i=12; i<24; i++){

					yp=77;
					for(int j=0; j<lay[i].info; j++){
						l=new locpi;
						if(prim){
							p=l;
							prim=0;		
						}else{
							q->leg=l;
						
						}
						q=l;
						q->leg=NULL;
						l->x=xp;
						l->y=yp;
						l->c=lay[i].c;	
						yp-=6;
					}
					if(i==17)
						xp-=33;
					else	
						xp-=18;


				}


}

void distruge(){
	locpi*temp;
	temp=p;
	while(p){
		temp=p->leg;
		delete p;
		p=temp;
		
	}
}



void update_tabla(){
	l=p;
	while(l){
		if(l->c==0)
			col='\u2588';
		else
			col=' ';
		for(int i=l->y; i<l->y+5; i++){
			if(i==l->y || i==l->y+4){
				for(int j=l->x+3; j<l->x+11; j++){
					tabla[i][j]=col;
				}
			}else if(i==l->y+1 || i==l->y+3){
				for(int j=l->x+1; j<l->x+13; j++){
					tabla[i][j]=col;
				}
			}else if(i==l->y+2){
				for(int j=l->x; j<l->x+14; j++){
					tabla[i][j]=col;
				}
			}
		}
		l=l->leg;
	}
}


bool validare(int i, int j, int mutari, int zt, int zar1, int zar2, bool juc){
	if(lay[i].info==0){
		cout << "Actiune nepermisa!!!\n";
				
		char inp='A';
		while(inp!=' ' && inp!=0x0d){
		inp = getch();

		}
		term=0;
		return 0;
	}else if(lay[i].c!=lay[j].c && lay[j].info>1){
		cout << "Actiune nepermisa!!!\n";
		char inp='A';
		while(inp!=' ' && inp!=0x0d){
			inp = getch();

		}
		term=0;
		return 0;
	}else if(i<0 || i>23 || j<0 || j >23){
		cout << "Actiune nepermisa!!!\n";
		char inp='A';
		while(inp!=' ' && inp!=0x0d){
			inp = getch();

		}
		term=0;
		return 0;
	}else if(i==j){
	
		cout << "Actiune nepermisa!!!\n";
		char inp='A';
		while(inp!=' ' && inp!=0x0d){
			inp = getch();
		}
		term=0;
		return 0;
	}else if(lay[j].info==5){
	
		cout << "Actiune nepermisa!!!\n";
		char inp='A';
		while(inp!=' ' && inp!=0x0d){
			inp = getch();
		}
		term=0;
		return 0;
	}else if(mutari==1){
		if(j-i!=zt && i-j!=zt){
			cout << "Actiune nepermisa!!!\n";
			char inp='A';
			while(inp!=' ' && inp!=0x0d){
				inp = getch();
			}
			term=0;
			return 0;
		}	
	}else if(i-j!=zar1 && j-i!=zar1 && i-j!=zar2 && j-i!=zar2){
		cout << "Actiune nepermisa!!!\n";
		char inp='A';
		while(inp!=' ' && inp!=0x0d){
			inp = getch();
		}
		term=0;
		return 0;

	}else if(!juc){
		if(i>j){
			cout << "Actiune nepermisa!!!\n";
			char inp='A';
			while(inp!=' ' && inp!=0x0d){
				inp = getch();
			}
			term=0;
			return 0;

		}

	}else if(juc){
		if(i<j){
			cout << "Actiune nepermisa!!!\n";
			char inp='A';
			while(inp!=' ' && inp!=0x0d){
				inp = getch();
			}
			term=0;
			return 0;

		}
	}

	return 1;
	
}





void animeaza(int i, int j){
	


	int ox, oy, fx, fy;
	if(i<12){
		ox=12+i*18;
		if(i>=6)
			ox+=15;
		oy=7+6*(lay[i].info-1);
	}
	else{
		ox=224-(i-12)*18;
		if(i>=18)
			ox-=15;
		oy=77-(lay[i].info-1)*6;		
	}

	if(j<12){
		fx=12+j*18;
		if(j>=6)
			fx+=15;
		fy=7+6*lay[j].info;
	}
	else{
		fx=224-(j-12)*18;
		if(j>=18)
			fx-=15;
		fy=77-lay[j].info*6;		
	}

	
	
	
		
	lay[i].info--;

	reset_tabla();
	distruge();
	sync();

	locpi* ani=new locpi;
	ani->x=ox;
	ani->y=oy;
	ani->c=lay[i].c;
	ani->leg=NULL;
	q->leg=ani;

	update_tabla();

	while(ani->x != fx || ani->y != fy){	
					//frame		
					if(ani->x < fx){
						ani->x++;
					}else if(ani->x > fx){
						ani->x--;
					}

					if(ani->y < fy){
						ani->y++;
						}else if(ani->y > fy){
						ani->y--;
					}
					
						
					update_tabla();	
						
					afiseaza();				
					usleep(10000);
					
					reset_tabla();
					
					//if(ani->x != fx ||  ani->y != fy)
					system("clear");
	}
		
	lay[j].info++;
	lay[j].c=lay[i].c;
	reset_tabla();	
	distruge();
	sync();
	update_tabla();
		
	afiseaza();				
}


int zar(){
    return rand()%6+1;;
}




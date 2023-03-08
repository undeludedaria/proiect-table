#include <stdlib.h>
#include <iostream>

using namespace std;

extern char col;
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


void muta(int i, int j, layout lay[]){
	lay[i].info--;
	lay[j].info++;
	lay[j].c=lay[i].c;
}

void afiseaza(){
	for(int i=0; i<100; i++){
		for(int j=0; j<250; j++){
			cout << tabla[i][j];
		}
	cout << endl;
	} 
}

void reset_tabla(locpi*l){
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

void sync(locpi *&p, locpi *&l, locpi *&q, layout lay[]){
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
					if(i==6)
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

void distruge(locpi*&p){
	locpi*temp;
	temp=p;
	while(p){
		temp=p->leg;
		delete p;
		p=temp;
		
	}
}



void update_tabla(locpi*l){
	while(l){
		if(l->c==0)
			col='=';
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



void animeaza(int i, int j, locpi*&q, layout lay[], locpi*&p, locpi*&l){
	if(lay[i].info==0){
		cout << "Actiune nepermisa\n";
		return;
	}else if(lay[i].c!=lay[j].c && lay[j].info!=0){
		cout << "Actiune nepermisa\n";
		return;
	}
	int ox, oy, fx, fy;
	if(i<12){
		ox=12+i*18;
		if(i>=6)
			ox+=15;
		oy=7+6*(lay[i].info-1);
	}
	else{
		ox=224-(i-12)*18;
		if(i>=17)
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
		if(j>=17)
			fx-=15;
		fy=77-lay[j].info*6;		
	}

	

	
	
	locpi* ani=new locpi;
	ani->x=ox;
	ani->y=oy;
	ani->c=0;
	ani->leg=NULL;
	q->leg=ani;
	
	lay[i].info--;
/*
		
	distruge(p);
	sync(p, l, q, lay);
	reset_tabla(p);
	update_tabla(p);	
	afiseaza();
	
	usleep(10000000000);
	
	l=p;
	while(l){
		cout << l->x << " " << l->y << " " << l->c << endl;
		l=l->leg; 
		if(!l){
			usleep(100000);
		}
	}
*/
	q->leg=ani;
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
						
					update_tabla(p);	
				
					afiseaza();				
					usleep(10000);
					
					
					reset_tabla(p);
			
					if(ani->x != fx ||  ani->y != fy)
						system("clear");
	}
	lay[j].info++;
	lay[j].c=lay[i].c;
	distruge(p);
	sync(p, l, q, lay);
	q->leg=ani;	
}


int randnum(){
    return rand()%6+1;;
}




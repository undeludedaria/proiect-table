#include "tabla.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "operatii.h"
//#include <windows.h>
using namespace std;
#define LAT 24
#define LUNG 12

bool COL;


bool exist(int x, int y, locpi*p);


int main(){
				 //culori
				const string red("\033[0;31m");
				const string reset("\033[0m");
				const string green("\033[1;32m");

				srand(time(NULL));
				//system("chcp 65001 > nul");
				/*nod *p = new nod;
				p->culoare=0;
				p->info=5;
				nod*q=p;

				for(int i = 1; i <= 4; i++){
				nod*n = new nod;
				q->leg=n;
				n->info=0;
				n->culoare=0;
				q=n;
				}

				nod*l=new nod;
				q->leg=l;
				l->info=2;
				l->culoare=1;
				q=l;

				l=new nod;
				l->info = 5;
				l->culoare=1;
				q->leg=l;
				q=l;

				for(int i = 1; i <= 3; i++){
				nod*n = new nod;
				q->leg=n;
				n->info=0;
				n->culoare=0;
				q=n;
				}

				l=new nod;
				l->info=3;
				l->culoare=0;
				q->leg=l;
				q=l;

				l=new nod;
				l->info=0;
				l->culoare=0;
				q->leg=l;
				q=l;

				l = new nod;
				l->info=5;
				l->culoare=1;
				q->leg=l;
				q=l;

				for(int i = 1; i <= 4; i++){
				nod *n = new nod;
				q->leg=n;
				n->info=0;
				n->culoare=0;
				q=n;
				}
				l=new nod;
				l->info=2;
				l->culoare=0;
				q->leg=l;
				q=l;

				l=new nod ;
				l->info =5;
				l->culoare=0;
				q->leg=l;
				q=l;

				for(int i = 1; i <= 3; i++){
				nod *n = new nod;
				q->leg=n;
				n->info=0;
				n->culoare=0;
				q=n;
				}

				l=new nod;
				l->info=3;
				l->culoare=1;
				q->leg=l;
				q=l;

				l=new nod;
				l->info=0;
				l->culoare=0;
				q->leg=l;
				q=l;

				l=new nod;
				l->info=0;
				l->culoare=0;
				q->leg=l;
				q=l;
				q->leg=NULL;
				*/


				layout lay[24];
				lay[0].info=2;
				lay[0].c=0;

				for(int i=1; i<5; i++){
					lay[i].info=0;
				}

				lay[5].info=5;
				lay[5].c=1;
	
				for(int i=6; i<7; i++){
					lay[i].info=0;
				}			
				lay[7].info=3;
				lay[7].c=1;

				for(int i=8; i<11; i++){
					lay[i].info=0;
				}
				lay[11].info=5;
				lay[11].c=0;

				
				lay[12].info=5;
				lay[12].c=1;
				for(int i=13; i<16; i++){
					lay[i].info=0;
				}
				lay[16].info=3;
				lay[16].c=0;
				for(int i=17; i<18; i++){
					lay[i].info=0;
				}
				lay[18].info=5;
				lay[18].c=0;
				for(int i=19; i<23; i++){
					lay[i].info=0;
				}
				lay[23].info=2;
				lay[23].c=1;

				


				locpi*l;
				locpi*q;
				locpi*p;
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
						yp+=5;
					}
					xp+=20;
			
				}

				
				for(int i=12; i<24; i++){
				
					yp=82;
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
						yp-=5;
					}
					xp+=20;
			
				}

				l=p;
				while(l){
					cout << l->x << " " << l->y << " " << l->c << endl;
					l=l->leg; 
				}
			
				
     /*cout<<"■";
     cout<<"□";
q=p;
    for( int i=1;i<=24;i++)
    {cout<<q->info<<" ";
    q=q->leg;

    }
	
		cout << endl << culoare(1, p) << " " << culoare(7, p) << endl;
		*/



	for(int i=0; i<100; i++){
		for(int j=0; j<250; j++){
			if(exist(i, j, p)){
				if(COL==0){
					cout << red << '/' << reset;
				}else{
					cout << green << '/' << reset;
				}		
			}else{
				cout << tabla[i][j];
			}

		}
		cout << endl;
	}












    return 0;
}






bool exist(int x, int y, locpi*p){
	
	while(p){
		if(x>=p->x && x < p->x+14 && y>=p->y && y < p->y+5){
			if(y==p->y+2){
				COL=p->c;
				cout << endl << x << " " << y << endl;
				return true;

			}else if((y==p->y || y==p->y+4) && (x>=p->x+3 && x<=p->x+10)){
				COL=p->c;
				cout << endl << x << " " << y << endl;
				return true;
			}else if((y==p->y+1 || y==p->y+3) && (x>=p->x+1 && x<=p->x+12)){
				COL=p->c;
				cout << endl << x << " " << y << endl;
				return true;
			}
		}
		p=p->leg;
	}


	return false;
}

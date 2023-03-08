#include <unistd.h>
#include "tabla.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "operatii.h"
//#include <windows.h>
using namespace std;




char col;

int main(){
				 //culori
				srand(time(NULL));
				//system("chcp 65001 > nul");


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

				
				//muta(0,1, lay);

				locpi*l;
				locpi*q;
				locpi*p;
				
				
		/*		
				l=p;
				while(l){
					cout << l->x << " " << l->y << " " << l->c << endl;
					l=l->leg; 
					if(!l){
						usleep(100000);
					}
				}
	*/
		
	int ox, oy, fx, fy;

	ox=50;
	oy=50;
	fx=200;
	fy=30;

	
	
	locpi* ani=new locpi;
	ani->x=ox;
	ani->y=oy;
	ani->c=0;
	ani->leg=NULL;
	q->leg=ani;



	sync(p, l, q, lay);
	char n;	
	int opt, opt2;
	char car;
	while(true){
		update_tabla(p);
		afiseaza();
		cout << "Alegeti actiunea: m/z\n";
		cin >> car;
		if(car=='z'){
			cout << randnum() << endl << randnum() << endl;;
			cin >> n;
		}else if(car=='m'){
			cin >> opt;
			cin >> opt2;
			animeaza(opt-1, opt2-1, q, lay, p, l);

			sync(p, l, q, lay);
		}
					
		 
		system("clear");
	}


	
	
	return 0;
}
	



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

	

	cout << "TEST\n";

	sync();
	char n;	
	int opt, opt2;
	char car, cont;
	while(true){
		update_tabla();
		afiseaza();
		cout << "Alegeti actiunea: m/z\n";
		car='A';
		while(car!='m' && car!='z'){
			car=getch();
		}
		if(car=='z'){
			cout << zar() << endl << zar() << endl;
			cont='A';
			while(cont!=' ')
				cont=getch();
		}else if(car=='m'){
			cin >> opt;
			cin >> opt2;
			animeaza(opt-1, opt2-1);

			sync();
		}
					
		 
		system("clear");
	}


	
	
	return 0;
}
	



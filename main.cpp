#include <unistd.h>
#include "tabla.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "operatii.h"
//#include <windows.h>

#define GRN  "\x1B[32m"
#define RED  "\x1B[31m"
#define WHT  "\x1B[37m"

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

	

	
	sync();
	char n;	
	int opt1, opt2;
	char car, cont;
	/*while(true){
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
			
			reset_tabla();
			distruge();
			sync();

		}
					
		 
		system("clear");
	}*/

	int zar1, zar2, zt;
	int mutari;
	bool dubla=false;
	string jucCol;
	juc=1;
	while(true){
		juc=!juc;
		update_tabla();
		afiseaza();
		if(juc==0){
			jucCol=GRN;
			cout << GRN << "Jucatorul 1\n" << WHT << "Apasa tasta spatiu pentru a da cu zarul\n";	
		}else{
			jucCol=RED;
			cout << RED << "Jucatorul 2\n" << WHT << "Apasa tasta spatiu pentru a da cu zarul\n";	
		}
		car='A';
		while(car!=' '){
			car=getch();
		}
		zar1=zar();
		zar2=zar();
		cout << zar1 << endl << zar2 << endl;
		if(zar1==zar2){
			dubla=true;
			mutari=4;
			zt=zar1;
		}else{ 
			dubla=false;
			mutari=2;
			zt=zar1;
		}
		cont='A';
		while(cont!=' ')
			cont=getch();
		while(mutari>0){
			
			cout << jucCol << "Alegeti mutarea\n"<< WHT;
			if(mutari==1 && !dubla){
				cout << '(' << zt << ')' << endl;
			}

			cin >> opt1 >> opt2;
			while(!validare(opt1-1, opt2-1, mutari, zt, zar1, zar2, juc)){	
				cin >> opt1;
				cin >> opt2;

			}
													
		
		
			animeaza(opt1-1, opt2-1);
			reset_tabla();
			distruge();
			sync();
			if(mutari==2){
				if(opt1-opt2==zar1){
					zt=zar2;
				}else if(opt2-opt1==zar1){
					zt=zar2;
				}else if(opt1-opt2==zar2){
					zt=zar1;
				}else if(opt2-opt1==zar2){
					zt=zar1;
				}
			}
			mutari--; 
		
		}


		system("clear");
	}
	
	return 0;
}
	



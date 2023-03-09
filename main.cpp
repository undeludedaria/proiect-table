#include <unistd.h>
#include "tabla.h"
#include "numere.h"
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
char car, cont;
int zar1, zar2, zt;


bool rezRestante(bool juc){
	if(restante[juc]!=0){
		cout << restante[juc] << " piese capturate\n";
		if(juc==0){
			cout << GRN << "Jucatorul 1\n" << WHT << "Apasa tasta spatiu pentru a da cu zarul\n";	
		}
		if(juc==1){
			cout << RED << "Jucatorul 2\n" << WHT << "Apasa tasta spatiu pentru a da cu zarul\n";	
		}
		car='A';
		while(car!=' '){
			car=getch();
		}
		zar1=zar();
		zar2=zar();
		
		convert(zar1);
		cout << endl;
		convert(zar2);
		int i=juc==0?0:18;
		bool posib=0;
		int mm=juc==0?6:24;
		if(juc==1){
			for(; i<mm; i++){
				if(lay[i].info==0 && (24-i==zar1||24-i==zar2)){
					posib=1;
					break;
				}
			}
		}else(juc==0){
			for(; i<mm; i++){
				if(lay[i].info==0 && (i+1==zar1||i+1==zar2)){
					posib=1;
					break;
				}
			}
		}
		if(posib){
			if(juc==0){	
				cout << GRN << "Alege triunghiul de evadare\n";	
				cin >> i;
				while(i-1<0 || i-1>5 || lay[i-1].info!=0){
					cout << "Actiune nepermisa!!!\n";
					cin >> i;
				}
				restante[0]--;
				lay[i-1].info++;
				lay[i-1].c=0;
			}else{	
				cout << RED << "Alege triunghiul de evadare\n";	
				cin >> i;
				while(i-1<18 || i-1>23 || lay[i-1].info!=0){
					cout << "Actiune nepermisa!!!\n";
					cin >> i;
				}
				restante[1]--;
				lay[i-1].info++;
				lay[i-1].c=1;

			}
			
		}
		return 1;
	}
	return 0;
}
/*
int i=juc==0?0:18;
		for(; i<juc==0?6:24; i++){
			if(lay[i].c==juc){
				s+=lay[i].info;
			}		
		}
		if(s==15){}

*/

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
	int mutari;
	bool dubla=false;
	string jucCol;
	juc=1;
	
	while(true){
		juc=!juc;

		update_tabla();
		afiseaza();

		if(rezRestante(juc)){
			continue;
		}
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
		
		convert(zar1);
		cout << endl;
		convert(zar2);

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
				convert(zt);
				cout << endl;
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
	



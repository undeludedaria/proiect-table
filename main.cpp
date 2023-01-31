#include<iostream>
#include<time.h>
#include<stdlib.h>
#include "operatii.h"
using namespace std;
#define LAT 24
#define LUNG 12


int main(){
    srand(time(NULL));
    system("chcp 65001 > nul");
    nod *p = new nod;
    p->culoare=0;
    p->info=5;
    nod*q = new nod;
    q=p;
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
    q->leg=0;
    q=l;







    for(int i = 1; i <= LUNG; i++){
        int lat = 1;
        while(lat!=25){
            if(i == 6 || i == 7){
                cout << " ";
            }else if(lat == 24 || lat == 1 || lat == 14 || lat ==13)
                cout << '|';
            else if(i < 6){
                if(LUNG-i+1 <= cauta(lat/2+12,p)){
                    piesa(culoare(lat/2,p));
                }else{
                    cout << " ";
                }
            }else{

            }
        }
        cout << endl;
    }

    return 0;
}

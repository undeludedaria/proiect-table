#include<stdlib.h>
#include <iostream>
#include <windows.h>

using namespace std;




struct nod{
    int info;
    bool culoare;
    nod*leg;
    nod*legi;
};

struct baza_p{
    int xpi;
    int ypi;

};
/*
bool piesa2(int xpi, int ypi, int x, int y){
    int xps=xpi+13, yps=ypi+4;
    if(x>=xpi && x <= xps && y>=ypi && y<=yps)
    {
        if((y==ypi || y==yps) && x>=xpi+3 && x<=xps-3)
        {
            cout<<culoare;
            return true;
        }
        else if((y==ypi+1 || y==yps-1) && x>=xpi+1 && x<=xps-2){
            cout<<culoare;
            return true;
        }
        else if(y==ypi+2){
            cout<<culoare;
            return true;
        }
    }
    return false;
}

bool piesa(int x,int y,nod*p)
{
    for(int i=0;i<120;i++)
    {
        if(piesa2(piese[i].xpi , piese[i].ypi))
        {
            return true;
        }
    }
}*/


void muta(int ni, int nj, nod*p, nod*q){
    int i = 1, j = 1;
    for(i = 1; i < ni || i < 13; i++){
        p=p->leg;
    }
    if(ni > 12){
        for(i = 1; i > ni-12; i++){
            q=q->legi;
        }
        q->info--;
    }else{
        p->info--;
    }

    for(i = 1; i < nj || i < 13; i++){
        p=p->leg;
    }
    if(ni > 12){
        for(i = 1; i > nj-12; i++){
            q=q->legi;
        }
        q->info++;
    }else{
        p->info++;
    }
}

bool culoare(int n,nod*p){
    nod*q;
    int ord = 1;
    while(ord != n)
    {
        p = p->leg;
    }
    return p->culoare;
}

int cauta(int n,nod*p)
{
    nod*q,*u;
    int ord;
    while(ord!=n)
    {
        p=p->leg;
    }
    return p->info;
}

void piesa(int n)
{
    if(n==1)
    {
        cout<<"■";
    }
    if(n==0)
    {
        cout<<"□";
    }
}
/*
void muta(int ni, int nj, nod*p){
    int i = 1;
    for(i = 1; i < ni && i < 13; i++){
        p = p->leg;
    }
    if(i==12 && ni != 12){
        for()
    }
}
  */




int randnum(){
    return rand()%6+1;;
}

#include<stdlib.h>
#include <iostream>
#include <windows.h>

using namespace std;




struct nod{
    int info;
    bool culoare;
    nod*leg;
};

bool piesa2(){
    int xps=xpi+13, xps=yps=ypi+4;
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




int randnum(){
    return rand()%6+1;;
}

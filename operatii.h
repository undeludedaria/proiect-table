#include<stdlib.h>
#include <iostream>

using namespace std;



struct nod{
    int info;
    bool culoare;
    nod*leg;
};

bool culoare(int n,nod*p){
		int ord = 1;
    while(ord != n)
    {
        p = p->leg;
				ord++;
    }
    return p->culoare;
}

int cauta(int n,nod*p)
{
    int ord = 1;
    while(ord!=n)
    {
        p=p->leg;
				ord++;
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

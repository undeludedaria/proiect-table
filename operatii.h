#include<stdlib.h>
#include <iostream>

using namespace std;


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

/*
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

void out_piesa(bool c, short int n)
{
	 cout << "piesa";
}

*/


int randnum(){
    return rand()%6+1;;
}

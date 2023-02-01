#include<stdlib.h>
#include <iostream>

using namespace std;

char piesa[7][20]={{"     ////////     "},
								{"  //////////////  "},
								{" //////////////// "},
								{"//////////////////"},
		            {" //////////////// "},
								{"  //////////////  "},
								{"     ////////     "}
							};

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

void out_piesa(bool c, short int n)
{
	 cout << "piesa";
}




int randnum(){
    return rand()%6+1;;
}

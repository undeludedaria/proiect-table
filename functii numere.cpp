#include <iostream>

using namespace std;

void zero(int z)
{
    z=0;
    cout<<"000000\n"<<"00  00\n"<<"00  00\n"<<"00  00\n"<<"000000\n";
}

void unu(int z)
{
    z=0;
    cout<<"000\n"<<" 00\n"<<" 00\n"<<" 00\n"<<"0000\n";
}

void doi(int z)
{
    z=0;
    cout<<"00000\n"<<"   00\n"<<"00000\n"<<"00  \n"<<"00000\n";
}
void trei(int z)
{
    z=0;
    cout<<"00000\n"<<"   00\n"<<"00000\n"<<"   00\n"<<"00000\n";
}

void patru(int z)
{
    z=0;
    cout<<"00  00\n"<<"00  00\n"<<"0000000\n"<<"    00\n"<<"    00\n";
}

void cinci(int z)
{
    z=0;
    cout<<"00000\n"<<"00   \n"<<"00000\n"<<"   00\n"<<"00000\n";
}

void sase(int z)
{
    z=0;
    cout<<"000000\n"<<"00   \n"<<"000000\n"<<"00  00\n"<<"000000\n";
}

void sapte(int z)
{
    z=0;
    cout<<"00000\n"<<"   00\n"<<"   00\n"<<"   00\n"<<"   00\n";
}

void opt(int z)
{
    z=0;
    cout<<"000000\n"<<"00  00\n"<<"000000\n"<<"00  00\n"<<"000000\n";
}

void noua(int z)
{
    z=0;
    cout<<"000000\n"<<"00  00\n"<<"000000\n"<<"    00\n"<<"000000\n";
}




void fct(int n)
{
    if(n==0)
    {
        zero(0);
    }
    if(n==1)
    {
        unu(0);
    }
    if(n==2)
    {
        doi(0);
    }
    if(n==3)
    {
        trei(0);
    }
    if(n==4)
    {
        patru(0);
    }
    if(n==5)
    {
        cinci(0);
    }
    if(n==6)
    {
        sase(0);
    }
    if(n==7)
    {
        sapte(0);
    }
    if(n==8)
    {
        opt(0);
    }
    if(n==9)
    {
        noua(0);
    }
}

int main()
{
    int n;
    cin>>n;
    fct(n);
    return 0;
}

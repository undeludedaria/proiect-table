#include <iostream>

using namespace std;
#define LAT 24
#define LUNG 12
int zar(){
    int nr = rand();
    while(!nr){
        nr = rand();
    }
    return nr;
        
}

int main()
{
    
    
    for(int i = 1; i <= LUNG; i++){
        int lat = 1;
        while(lat!=25){
            if(i == 6 || i == 7){
                cout << " ";
            }else if(lat == 24 || lat == 1 || lat == 14 || lat ==13)
                cout << '|';
            else if(i < 6){ 
                if(lung-i+1 <= cauta(lat/2+12)){
                    piesa(culoare(lat/2));
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

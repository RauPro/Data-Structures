#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    int matriz[5][5];
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++)
        	matriz[i][j]=0;
        }
    
    
    for(int i = 0; i<5; i++){
        for(int j = 0; j<=i; j++){
            cout<<"introduce el valor"<<"["<<i<<"]"<<"["<<j<<"]"<<endl;
            cin>>matriz[i][j];
        }
    }
    
    for(int i = 0; i< 5; i++){
        for(int j = 0; j< 5; j++)
            cout<<matriz[i][j];
        cout<<endl;
    }

}

#include <iostream>
using namespace std;
void naturales(int a, int b){
    if(a!=b){
        cout<<a<<" ";
        naturales(a+1, b);
    }
}
int main()
{
    int a,b;
    cout<<"Ingrese a: "<<endl;
    cin>>a;
    cout<<"Ingrese b: "<<endl;
    cin>>b;
    naturales(a,b);
    return 0;
}

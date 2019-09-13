#include <iostream>
#include <time.h>
using namespace std;
struct continente{
    string pais[5];
    string capital[5];
    int avitantes[5];
};
int main(){
    struct continente Europa;
    struct continente America;
    struct continente Asia;
    struct continente Oseania;
    struct continente Africa;
    cout<<"MENU!: "<<endl;
    cout<<"1.Para añadir los paises."<<endl;
    cout<<"2.Para Buscar datos por continente."<<endl;
    cout<<"3.Saber cantidad con mas poblacion."<<endl;
    int pAsia=(Asia.avitantes[0]+Asia.avitantes[1]+Asia.avitantes[2]+Asia.avitantes[3]+Asia.avitantes[4]);
    int pAmerica= (America.avitantes[0]+America.avitantes[1]+America.avitantes[2]+America.avitantes[3]+America.avitantes[4]);
    int pOseania=(Oseania.avitantes[0]+Oseania.avitantes[1]+Oseania.avitantes[2]+Oseania.avitantes[3]+Oseania.avitantes[4]);
    int pAfrica=(Africa.avitantes[0]+Africa.avitantes[1]+Africa.avitantes[2]+Africa.avitantes[3]+Africa.avitantes[4]);
    int pEuropa=(Europa.avitantes[0]+Europa.avitantes[1]+Europa.avitantes[2]+Europa.avitantes[3]+Europa.avitantes[4]);
    int x;
    cin>>x;
    string cont;
    switch(x){
    	case 1: 
	    	 cout<<"Continente Europeo: "<<endl;
	    for (int i=0;i<5;i++){
		    cout<<"Ingrese el nombre del pais "<<i+1<<": "<<endl;
		    cin>>Europa.pais[i];
		    cout<<"Ingrese La Capital "<<i+1<<": "<<endl;
		    cin>>Europa.capital[i];
		    cout<<"Ingrese El numero de Avitantes "<<i+1<<": "<<endl;
		    cin>>Europa.avitantes[i];	
		}
		cout<<"Continente Americano: "<<endl;
	    for (int i=0;i<5;i++){
		    cout<<"Ingrese el nombre del pais "<<i+1<<": "<<endl;
		    cin>>America.pais[i];
		    cout<<"Ingrese La Capital "<<i+1<<": "<<endl;
		    cin>>America.capital[i];
		    cout<<"Ingrese El numero de Avitantes "<<i+1<<": "<<endl;
		    cin>>America.avitantes[i];	
		}
		cout<<"Continente Asiatico: "<<endl;
	    for (int i=0;i<5;i++){
		    cout<<"Ingrese el nombre del pais "<<i+1<<": "<<endl;
		    cin>>Asia.pais[i];
		    cout<<"Ingrese La Capital "<<i+1<<": "<<endl;
		    cin>>Asia.capital[i];
		    cout<<"Ingrese El numero de Avitantes "<<i+1<<": "<<endl;
		    cin>>Asia.avitantes[i];	
		}
		cout<<"Continente Oseania: "<<endl;
	    for (int i=0;i<5;i++){
		    cout<<"Ingrese el nombre del pais "<<i+1<<": "<<endl;
		    cin>>Oseania.pais[i];
		    cout<<"Ingrese La Capital "<<i+1<<": "<<endl;
		    cin>>Oseania.capital[i];
		    cout<<"Ingrese El numero de Avitantes "<<i+1<<": "<<endl;
		    cin>>Oseania.avitantes[i];	
		}
			cout<<"Continente Africano: "<<endl;
	    for (int i=0;i<5;i++){
		    cout<<"Ingrese el nombre del pais "<<i+1<<": "<<endl;
		    cin>>Africa.pais[i];
		    cout<<"Ingrese La Capital "<<i+1<<": "<<endl;
		    cin>>Africa.capital[i];
		    cout<<"Ingrese El numero de Avitantes "<<i+1<<": "<<endl;
		    cin>>Africa.avitantes[i];	
		}
		break;
		case 2:
			cout<<"Ingrese el contienente con Mayuscula inicial: ejemplo: Asia :: "<<endl;
			
			cin>>cont;
			if (cont=="Asia"){
				cout<<"La cantidad de poblacion es: "<<endl;
				cout<<(Asia.avitantes[0]+Asia.avitantes[1]+Asia.avitantes[2]+Asia.avitantes[3]+Asia.avitantes[4])<<endl;
			}
			if (cont=="America"){
				cout<<(America.avitantes[0]+America.avitantes[1]+America.avitantes[2]+America.avitantes[3]+America.avitantes[4])<<endl;
			}
			if (cont=="Oseania"){
				cout<<(Oseania.avitantes[0]+Oseania.avitantes[1]+Oseania.avitantes[2]+Oseania.avitantes[3]+Oseania.avitantes[4])<<endl;
			}
			if (cont=="Africa"){
				cout<<(Africa.avitantes[0]+Africa.avitantes[1]+Africa.avitantes[2]+Africa.avitantes[3]+Africa.avitantes[4])<<endl;
			}
			if (cont=="Europa"){
				cout<<(Europa.avitantes[0]+Europa.avitantes[1]+Europa.avitantes[2]+Europa.avitantes[3]+Europa.avitantes[4])<<endl;
			}
			break;
		case 3:
			if (pAsia>pAmerica and pAsia>pEuropa and pAsia>pAfrica and pAsia>pOseania)	{
				cout<<"La mayor poblacion la tiene Asia: "<<pAsia<<endl;
			}
			if (pAsia<pAmerica and pAmerica>pEuropa and pAmerica>pAfrica and pAmerica>pOseania)	{
				cout<<"La mayor poblacion la tiene America: "<<pAmerica<<endl;
			}
			if (pEuropa>pAmerica and pAsia<pEuropa and pEuropa>pAfrica and pEuropa>pOseania)	{
				cout<<"La mayor poblacion la tiene Europa: "<<pEuropa<<endl;
			}
			if (pAfrica>pAmerica and pAfrica>pEuropa and pAsia<pAfrica and pAfrica>pOseania)	{
				cout<<"La mayor poblacion la tiene Africa: "<<pAfrica<<endl;
			}
			else {
				cout<<"La mayor poblacion la tiene Oceania: "<<pOseania<<endl;
			}
		
	}
   
    
}

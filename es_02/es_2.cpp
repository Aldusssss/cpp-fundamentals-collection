#include <iostream>
using namespace std;


int main(){
	
	int contatore;
	cout << "Programma per eseguire la media di n numeri." << endl;
	
	
	do{
		cout << "Quanti numeri vuoi inserire?"<< endl;
		cin >> contatore; 
	}while(contatore<0);
	
	if(contatore==0){
		cout << "La media non e definita";
	}else{
	

	float somma=0,num;
	for(int i=contatore;i>0;i--){
		cout << "Inserisci un numero: ";
		cin >> num;
		somma+=num;
	}
	float media=somma/contatore;
	cout << "La media e: "<< media;
	
	
	}
	
	
	return 0;
}
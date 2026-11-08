#include <iostream>

using namespace std;
//dimensione array e una costante
const int DIM = 11;

int main(){
	//dichiarazioni array e variabili
	int numeri[DIM];
	int mediana=0;
	
	
	cout<<"Programma che calcola la mediana di n numeri inseriti in input"<<endl;
	//chiedo numeri in input all'utente da inserire nell'array "numeri"
	for(int i=0;i<DIM;i++){
		cout<<"Inserire un numero:"<<endl;
		cin>>numeri[i];
	}
	
	//ordino array (bouble sort)
	for(int i=0;i<DIM;i++){
		for(int j=0;j<DIM;j++){
			if(numeri[i]<numeri[j]){
				int salva=numeri[j];
				numeri[j]=numeri[i];
				numeri[i]=salva;
			}	
	}
	}

	//controllo se DIM e pari
	if(DIM%2==0){
		mediana=DIM/2;
	}
	
	//controllo se DIM e dispari
	if(DIM%2!=0){
		mediana=(DIM-1)/2;
	}
	
	//stampo mediana
	cout<<"Mediana: "<< numeri[mediana];
	
	
	
	return 0;
}
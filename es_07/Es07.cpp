#include <iostream>

using namespace std;

int main(){
	//dichiarazioni variabili
	
	int mediana=0,dim=0;
	
	cout<<"Programma che calcola la mediana di n numeri inseriti in input"<<endl;
	
	//chiedo all'utente la dimensione dell'array
	do{
		cout<<"Quanti numeri vuoi inserire : "<<endl;
		cin>>dim;
		
	}while(dim<=0);
	
	//dichiaro array perche ora conosco la dimensione-->"dim" dell'array "numeri"
	int numeri[dim];
	
	
	//chiedo numeri in input all'utente da inserire nell'array "numeri"
	for(int i=0;i<dim;i++){
		cout<<"Inserire un numero:"<<endl;
		cin>>numeri[i];
	}
	
	//ordino array (bouble sort)
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			if(numeri[i]<numeri[j]){
				int salva=numeri[j];
				numeri[j]=numeri[i];
				numeri[i]=salva;
			}	
	}
	}

	//controllo se DIM e pari
	if(dim%2==0){
		mediana=dim/2;
	}
	
	//controllo se DIM e dispari
	if(dim%2!=0){
		mediana=(dim-1)/2;
	}
	
	//stampo mediana
	cout<<"Mediana: "<< numeri[mediana];
	
	
	return 0;
}
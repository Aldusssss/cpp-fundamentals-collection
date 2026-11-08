#include <iostream>
using namespace std;

void leggiArray(int array[],int dim){
	for(int i=0;i<dim;i++){
		cout << "Inserisci il numero in posizione["<<i<<"]: "<<endl;
		cin >> array[i];
	}
	
}

int calcolaMediana(int array[],int dim){

	//ordinamento bubble sort
	for(int i=0;i<dim-1;i++){
		for(int j=0;j<dim-i-1;j++){
			if(array[j]<array[j+1]){
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
	}}
	
	return (int)array[(dim/2)];
}

int trovaMassimo(int num1,int num2){
	int max;
	if(num1>num2){
		max=num1;
	}else if(num2>num1){
		max=num2;
	}else{
		cout << "Le mediane sono uguali.";
	}
	return max;
}




int main(){
	
	//dichiarazione dimensioni dei 2 array
	int const DIM1=5;
	int const DIM2=5;
	
	
	int array1[DIM1],array2[DIM2];
	leggiArray(array1,DIM1);
	leggiArray(array2,DIM2);
	int mediana1,mediana2;
	cout <<"Primo array:"<<endl;
	mediana1=calcolaMediana(array1,DIM1);
	cout <<"Secondo array:"<<endl;
	mediana2=calcolaMediana(array2,DIM2);
	
	cout <<"Mediana di array1: "<<mediana1<<endl;
	cout <<"Mediana di array2: "<<mediana2<<endl;
	cout << "Il massimo tra le due mediane e: "<<trovaMassimo(mediana1,mediana2);
	
	
	return 0;
}
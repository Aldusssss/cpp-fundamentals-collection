#include <iostream>
using namespace std;
#define LEN 10

void readArray(int (&array) [LEN]){
	
	for (int i=0;i<LEN;i++){
		cout << "Inserisci elemento in posizione ["<<i<<"]: ";
		cin >> array[i];
	}
}

void printArray(int (&array) [LEN]){
	cout << "Stampa array:"<<endl;
	for (int i=0;i<LEN;i++){
		cout << "Elemento in posizione ["<<i<<"]: "<<array[i]<<endl;

	}
}

void xSearch (int (&array) [LEN],int x,int valDaCercare){
 
	bool trovato=false;
	if(x==1){
		
		//1. algoritmo di ordinamento per inserimento
		for (int i = 1; i < LEN; i++) {
        int key = array[i];  // Elemento da inserire
        int j = i - 1;
        
        // Sposta gli elementi maggiori di key verso destra
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;  // Inserisci key nella posizione corretta
    }
		
	}else if(x==2){
		//2. algoritmo di ordinamento per selezione
		for (int i = 0; i < LEN - 1; i++) {
        int minIndex = i;  // Indice del minimo
        
        // Trova il minimo nella parte non ordinata
        for (int j = i + 1; j < LEN; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        
        // Scambia il minimo con il primo elemento non ordinato
        swap(array[i], array[minIndex]);
    }
		
	}else if(x==3){
		//algoritmo di ricerca binaria in un vettore ordinato
		for (int i = 0; i < LEN - 1; i++) {

        for (int j = 0; j < LEN - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);  
            }
        }
    }
		
		
		
	}else{
		cout << "Tipo di algoritmo non coincide."<<endl;
	}
	
	
}



int main(){
	
	int array[LEN];
	readArray(array);
	printArray(array);
	cout << "L'array ordinato : "<<endl;
	xSearch(array,1,3);
	for (int i=0;i<LEN;i++){
		cout << "array["<<i<<"]: "<<array[i]<<endl;
	}
	
	return 0;
}
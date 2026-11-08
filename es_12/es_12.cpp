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

int xSearch (int array [LEN],int x,int valDaCercare){
	int pos; 
	bool trovato=false;
	if(x==1){
		
		//algoritmo di ricerca in un vettore non ordinato
		for(int i=0;i<LEN;i++){
			if(array[i]==valDaCercare){
				pos=i;
				trovato=true;
			}
		}
		
	}else if(x==2){
		//algoritmo di ricerca sequenziale in un vettore ordinato
		for(int i=0;i<LEN;i++){
			if(array[i]==valDaCercare){
				pos=i;
				trovato=true;
			}
			if(array[i]>valDaCercare){
				break;
			}
		}
		
	}else if(x==3){
		//algoritmo di ricerca binaria in un vettore ordinato
		int sinistra=0;
		int destra=LEN-1;
		while(sinistra<=destra){
			int centro = sinistra + (destra - sinistra) / 2;
			
			if(valDaCercare==array[centro]){
				pos=centro;
				trovato=true;
			}else if (array[centro] < valDaCercare) {
            	sinistra = centro + 1; // cerca a destra
        	}
        	else {
            	destra = centro - 1; // cerca a sinistra
        	}
			
		}
		
		
		
	}else{
		cout << "Tipo di algoritmo non coincide."<<endl;
	}
	
	if(!trovato){
		pos=-1;
		cout << "valore da cercare non presente nell'array."<<endl;
	}
	
	return pos;
}



int main(){
	
	int array[LEN];
	readArray(array);
	printArray(array);
	cout << "L'elemento cercato e in posizione : "<<xSearch(array,1,3);
	
	return 0;
}
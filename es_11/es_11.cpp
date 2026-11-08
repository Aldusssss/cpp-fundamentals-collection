#include <iostream>
#include <climits> // per INT_MAX e INT_MIN
using namespace std;

int cercaMax(int array[]){
	int max=INT_MIN;
	for(int i=0;i<9;i++){
		if(array[i]>max){
			max=array[i];
		}
	}
	return max;
}

int sommaDiagonale(int matrice[5][5]){
	int max;
	int arraySup[5];
	int arrayInf[5];
	int k=0,somma=0;
	
	
	for(int i=0;i<5;i++){

			for(int j=4-i-k;j>=0;j--){
				somma=somma+matrice[k][j];
				k++;
			}
			arraySup[i]=somma;
			somma=0;
			k=0;
			
	}

	for(int i=0;i<5;i++){

			k=i;
			for(int j=4;j>=i;j--){
				somma=somma+matrice[k][j];
				k++;
			}
			arrayInf[i]=somma;
			somma=0;
			k=0;
			
	}
	
	
	
	int arrayFinale[9];

	for(int i = 0; i < 9; i++) {
    	if(i <= 4) {
    	    arrayFinale[i] = arraySup[i];  
    	} else {
    	    arrayFinale[i] = arrayInf[i - 4]; 
    	}
	}

	cout << "Somma delle varie diagonali" << endl;
		for(int i = 0; i < 9; i++) {
    		cout << "diagonale numero " << i << " : " << arrayFinale[i] << endl;
		}

	
	max=cercaMax(arrayFinale);
	cout <<"Il massimo: ";
	
	return max;
}






int main(){
	int matrice[5][5] = {
        {1, 5, 3, 4, 6},
        {2, 3, 5, 4, 2},
        {3, 7, 0, 1, 2},
        {4, 6, 9, 1, 9},
        {1, 2, 5, 3, 2}
    };
    
	cout<<sommaDiagonale(matrice);
	
	return 0;
}
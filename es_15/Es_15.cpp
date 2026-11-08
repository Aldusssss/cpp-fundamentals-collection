#include <iostream>

using namespace std;

void inizializzaMatrice(int **mat, int r, int c ){
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			mat[i][j]=0;
		}
		
	}
	cout << "Matrice inizializzata."<<endl;
	
}

void stampaMatrice(int **mat, int r, int c ){
	cout << "Stampo matrice: "<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	
}

void eliminaMatrice(int**mat,int righe,int colonne){
	for(int i = 0; i < righe; i++) {
        delete[] mat[i];  // libera ogni riga
    }
    delete[] mat; 
	
	cout << "Matrice Eliminata."<<endl;
	
}


int main(){
	
	int righe, colonne;
	int **mat;
	
	do{
		cout << "Inserisci il numero di colonne"<<endl;
		cin >> colonne;
		cout << "Inserisci il numero di righe"<<endl;
		cin >> righe;
		
		
	}while(colonne<0 || righe<0);
	
	if(colonne==0 || righe==0){
		cout << "Non ha senso allocare una matrice con 0 righe e/o 0 colonne";
	}else{
		
		mat = new int*[colonne];
		for (int i = 0; i < righe; i++){
 			
			mat[i] = new int[colonne];
			 
 		}
		inizializzaMatrice(mat,righe,colonne);
		stampaMatrice(mat,righe,colonne);
		eliminaMatrice(mat,righe,colonne);
		
		
	}
	
	
	
	
	
	return 0;
}
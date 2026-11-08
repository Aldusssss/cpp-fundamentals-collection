#include <iostream>
#include <climits> // per INT_MAX e INT_MIN
using namespace std;

void calcolaSella(int matrice[3][3]){
	
	//dichiarazione variabili
	int min;
	bool sellaTrovata=true;
	int y=0;
	
	int* risultato=new int[3];
	for(int i=0;i<3;i++){
		min=INT_MAX;
		sellaTrovata=true;
			for(int j=0;j<3;j++){
				//trovo min
				if(matrice[i][j]<min){
					min=matrice[i][j];
					y=j;
				}
			}
			//vedo se min e il max della sua colonna
			for(int k=0;k<3;k++){
				if(min<matrice[k][y]){
					sellaTrovata=false;
				}
			}
					
			if(sellaTrovata){
				risultato[0]=min;
				risultato[1]=i;
				risultato[2]=y;
				break;
			}
	}
	
	if(!sellaTrovata){
		cout << "Punto di sella = non esiste";
	}else{
 	
	cout<< "punto di sella: "<<risultato[0]<<endl;
	cout<< "riga: "<<risultato[1]+1<<endl;
	cout<< "colonna: "<<risultato[2]+1<<endl;
	}
}




int main(){
	int matrice[3][3]={
		{33,7,71},
		{19,12,83},
		{29,4,15}
	};
	calcolaSella(matrice);
	
	
	
	return 0;
}
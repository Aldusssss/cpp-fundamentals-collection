#include <iostream>

using namespace std;

int main(){
	//dichiarazione variabili e array
	int nParole=0,nSpazi=0,nBuchi=0;
	int spaziPerBuco=0, resto=0;
	char stringaGiustificata[40];
	char stringa[40];
	
	//dichiarazione indici 
	int j=0,i=0;
	
	
	//l'utente inserisce la stringa 
	cout<<"Inserire stringa: "<<endl;
	cin.getline(stringa,40);
	
	//conto il numero degli spazi "nSpazi" di stringa
	for(int i=0;i<strlen(stringa);i++){
		if(stringa[i]==' '){
			nSpazi++;
		}	
	}
	nSpazi++;
	
	//conto il numero delle parole "nParole"
	for(int i=0;i<strlen(stringa)-1;i++){
		if(stringa[i]==' ' && isalpha(stringa[i+1])){
				nParole++;
		}
	
	}
	
	//controllo se nella prima posizione di stringa ce un alfanumerico
	if(isalpha(stringa[0])){
		nParole++;
		nBuchi++;
	}
	
	//assegno nBuchi
	nBuchi=nParole-1;
	
	//calcolo spaziPerBuco e resto
	spaziPerBuco=nSpazi/nBuchi;
	resto=nSpazi%nBuchi;
	
	//non considero gli spazi iniziali
	while(stringa[i]==' '){
		i++;
	}
	
	//giustifico la stringa in input
	do{
		if(!(stringa[i]==' ')){
			stringaGiustificata[j]=stringa[i];
			j++;			
		}
		
		//controllo se stringa[i] e vuota e stringa[i+1] ha un alfanumerico
		if(stringa[i]==' ' && isalpha(stringa[i+1])){
			//inserisco in stringaGiustificata quanti spazi vuoti in base a "spaziPerBuco"
			for(int k=0;k<spaziPerBuco;k++){
				stringaGiustificata[j]=' ';
				j++;
			}
			
			//controllo se il resto e maggiore di zero e aggiungo uno spazio in stringaGiustificata
			if(resto>0){
				stringaGiustificata[j]=' ';
				j++;
				resto--;
			}
		}
		i++;
	}while(i<strlen(stringa)-1);
	
	//stampo stringa giustificata
	cout<<"Stringa Giustificata: "<<endl;
	for(int i=0;i<40;i++)
	cout<<stringaGiustificata[i];
	
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main(){
	cout << "Calcolo il numero dei caratteri del periodo con il massimo numeri di caratteri " << endl <<
	"il numero di parole del periodo con il massimo numero di parole ";
	
	//dichiarazione variabili
	std::string stringa,output="";
	int nCaratteri=0;
	int maxCaratteri=0;
	int nParole=0;
	int maxParole=0;
	int nPeriodo=1;
	
	//richiesta stringa all'utente
	cout << "Inserisci una stringa (deve finire con $): ";
	getline(cin,stringa);
	
	//controllo stringa vuota
	if(stringa=="$"){
		cout << "Non sono stati introdotti caratteri.";
	}else{
		
		//dichiaro contatore
		int i=0;
		
		
		
		//ciclo per scorrere la stringa
		while(stringa[i]!='$'){
			nCaratteri++;
			
			//ciclo se nella stringa sono presenti .;:
			while(stringa[i]=='.' || stringa[i]==';' || stringa[i]==':'){
				
				 nPeriodo++;
				if(nParole+1>maxParole){
					maxParole=nParole+1;
				}
				if(nCaratteri>maxCaratteri){
					maxCaratteri=nCaratteri;
				}
				nParole=0;
				nCaratteri=0;
				break;
			}
			//controllo spazio
			if(stringa[i]==' '){
					nParole++;
				}
			
			
			i++;
		}
		
		maxCaratteri++;
		//controllo se quando inserisce un carattere ed e .,;
		if(i==1 && stringa[0]=='.' || stringa[0]==';' || stringa[0]==':' ){
			maxParole=0;
			maxCaratteri=1;
		}
		
		
		cout<<"Numero di caratteri del periodo con piu caratteri e =" << maxCaratteri << endl 
		<< "Numero di parole del periodo con piu parole e =" << maxParole;
		
	}


	return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main(){
	cout << "Calcolo della percentuale di lettere minuscole e la percentuale di cifre di una stringa." << endl ;
	
	std::string stringa;
	int numMinuscole=0;
	int numCifre=0;
	double percentualeMinuscole,percentualeCifre;
	
	cout << "Inserisci una stringa (deve finire con $): ";
	getline(cin,stringa);
	
	//controllo stringa vuota
	if(stringa=="$"){
		cout << "Non sono stati introdotti caratteri.";
	}else{
		
		//dichiaro contatore
		int i=0;
		
		//scorro la stringa
		while(stringa[i]!='$'){
			
			
			//verifico se in posizione i della stringa il carattere e minuscolo
			if(std::islower(stringa[i])){
				numMinuscole++;
			}
			
			//verifico se in posizione i della stringa il carattere e una cifra
			if(std::isdigit(stringa[i])){
				numCifre++;
			}
			i++;
			
		}
		
		//assegnazione alle percentuali --> (stringa.size()-1) perche e presente anche $ nella stringa e non dobbiamo contarlo
		percentualeMinuscole=(numMinuscole*100)/(stringa.size()-1);
		percentualeCifre=(numCifre*100)/(stringa.size()-1);
		
		cout << "la percentuale di lettere minuscole e " << percentualeMinuscole << "% La percentuale di cifre e " << percentualeCifre<<"%";
		
	}


	return 0;
}
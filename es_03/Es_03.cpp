#include <iostream>
using namespace std;


int main(){
	//dichiarazioni variabili
	int num,max=0;
	bool trovato;
	
	cout<< "Calcolo del max  (inserisci zero per uscire) :"<<endl;

	do{
		//imposto trovato a true-->ipotizzando che l utente inserisce un numero positivo. Se non lo fara si imposta trovato a false.
		trovato=true;
		
		//chiede all'utente di inseire un num e prende in input il num 
		cout<< "Inserire un numero intero positivo: ";
		cin>>num;
		
		//caso in cui il numero inserito e negativo
		if(num<0){
			cout<< "Hai inserito un numero NEGATIVO. Ripeti operazione."<<endl;
			trovato=false;
		}else{
			//confronto il numero in input con il max(che inizialmente e zero) 
			if(num>max){
				//assegno a max il valore del numero in input
				max=num;
			}
		}
		
		
	}while(num!=0 || trovato==false);
	
	//stampo a video il massimo
	cout<< "Max: "<<max<<endl;
	
	
	return 0;
}
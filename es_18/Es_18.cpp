#include <iostream>
#include <string>
using namespace std;

struct Nodo{
	int num;
	Nodo *ptr;
};

void inserisci(Nodo*& head,int contatore) {
	
	//creazione nodo + collegamento
	int numero;
	cout << "Inserisci in posizione: "<<"1"<<endl;
	cin >> numero;
	
	head = new Nodo{numero, nullptr};
    Nodo* coda = head;
    
	for (int i=2;i<=contatore;i++){
		Nodo *nuovoNodo = new Nodo;
		cout << "Inserisci in posizione: "<<i<<endl;
		cin >> numero;
		
		coda->ptr = new Nodo{numero, nullptr};
		coda=coda->ptr;
		
	}

}


void stampaContrarioIterazione(Nodo* head) {
    int lunghezza = 0;
    Nodo* corrente = head;
    while (corrente != nullptr) {
        lunghezza++;
        corrente = corrente->ptr;
    }
    
    // Stampa dall'ultimo al primo
    for (int i = lunghezza; i >= 1; i--) {
        corrente = head;
        // Scorri fino alla posizione i-esima
        for (int j = 1; j < i; j++) {
            corrente = corrente->ptr;
        }
        cout << corrente->num << " ";
    }
    cout << endl;
}


void stampaContrarioRicorsivo(Nodo* head) {
    if (head == nullptr) {
        return;
    }
    // Chiama ricorsivamente prima di stampare
    stampaContrarioRicorsivo(head->ptr);
    // Stampa quando ritorni dalla ricorsione
    cout << head->num << " ";
}

void stampa(Nodo* head) {
    while(head != nullptr) {
        cout << head->num << " ";
        head=head->ptr;
    }
      
}

void deleteNodiRicorsione(Nodo*& head) {
    if (head == nullptr) {
        return;
    }
    deleteNodiRicorsione(head->ptr);    
	delete head;
    
}

void deleteNodiIterazione(Nodo*& head) {
    while (head != nullptr) {
        Nodo* temp = head;      // Salva il riferimento al nodo corrente
        head = head->ptr;       // Avanza al prossimo nodo
        delete temp;            // Elimina il nodo salvato
    }

}

bool controllo (Nodo*& head){
	bool esiste=true;
	if(head == nullptr){
		esiste=false;
		}
	return esiste;
}


int main(){
	
	
	//chiede all'utente quanti valori vuole inserire (num)
	int num=-1;
	do{
		cout << "Quanti valori vuoi inserire nella lista collegata:"<<endl;
		cin >> num;
	}while(num<=0);
	
	Nodo* head = nullptr;
	//Inserisce i dati l'utente (uso della relativa funzione)
	inserisci(head,num);
	
	//verifica
	if(!controllo(head)){
		cout << "lista vuota.";
	}else{
	
		cout <<endl<<"Stampa."<<endl;
		stampa(head);
	
		//stampa al contrario
		cout <<endl<<"Stampa al contrario."<<endl;
		stampaContrarioIterazione(head);
		//distruggi nodi
		cout <<endl<<"Sono stati eliminati tutti i nodi.";
		deleteNodiIterazione(head);
		
	}

	return 0;
}
#include <iostream>
using namespace std;

struct Nodo{
	int num;
	Nodo *dx;
	Nodo *sx;

};

void inserisci(Nodo*& radice, int num) {
    
}

void stampa(Nodo* nodo) {
	int i=0;
    if(nodo==nullptr){
    	return;
	}
	stampa(nodo->sx);
	cout << nodo->num << " ";  
	stampa(nodo->dx);
	
}

int contaFoglie(Nodo* nodo) {
    if(nodo == nullptr) {
        return 0;  //0 foglie
    }
    
    // Se e una FOGLIA (nessun figlio)
    if(nodo->sx == nullptr && nodo->dx == nullptr) {
        return nodo->num;  //Trovata una foglia
    }
    
    // Altrimenti, somma ricorsivamente le foglie dei sottoalberi
    return contaFoglie(nodo->sx) + contaFoglie(nodo->dx);
}

int contaRadici(Nodo* nodo) {
    if(nodo == nullptr) {
        return 0;  //0 foglie
    }
  
    if(!(nodo->sx == nullptr && nodo->dx == nullptr)) {
        return nodo->num + contaRadici(nodo->sx) + contaRadici(nodo->dx);  //Trovata una foglia
    }
    
    // Altrimenti, somma ricorsivamente le foglie dei sottoalberi
    return contaRadici(nodo->sx) + contaRadici(nodo->dx);
}

void inizializza(Nodo*& head){
	head = new Nodo{28, nullptr, nullptr};
    
    head->sx = new Nodo{13, nullptr, nullptr};
    head->dx = new Nodo{40, nullptr, nullptr};
    
    head->sx->sx = new Nodo{10, nullptr, nullptr};
    head->sx->dx = new Nodo{18, nullptr, nullptr};
    
    head->dx->sx = new Nodo{30, nullptr, nullptr};
}

int main(){
	
	
	Nodo* head = nullptr;
	inizializza(head);
	stampa(head);
	cout <<endl<<"Somma Valori cammino esterno: "<<contaFoglie(head)<<endl;
	cout << "Somma Valori cammino interno: "<<contaRadici(head)<<endl;
	return 0;
}




#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Nodo{
	int valore;
	Nodo *nodoSuccessivo;
};

void InserisciNodo(Nodo *&head,int num){

	Nodo* nuovoNodo = new Nodo{num, nullptr};
    
    // Se la lista e vuota
    if (head == nullptr) {
        head = nuovoNodo;
    } else {
        // Trova l'ultimo nodo
        Nodo* temp = head;
        while (temp->nodoSuccessivo != nullptr) {
            temp = temp->nodoSuccessivo;
        }
        // Collega l'ultimo nodo al nuovo nodo
        temp->nodoSuccessivo = nuovoNodo;
    }
}

int calcolaMedia(Nodo *&head){
	int i=0;
	int somma=0;
	if(head==nullptr){
		return 0;
	}
	Nodo* temp = head;
	while(temp!=nullptr){
		somma=somma+temp->valore;
		i=i+1;
		temp=temp->nodoSuccessivo;
	}
	return somma/i;
}


int main() {
    std::ifstream file("voti.txt");
    
    if(!file.is_open()){
    	cout << "Il file NON si e aperto correttamente"<<endl;
	}
	

	int numero;
    int riga = 1;
    Nodo*head=nullptr;
    while (file >> numero) {
        //inserisci
        InserisciNodo(head,numero);
        riga++;
    }
    
    // Verifica se c e stato un errore (non EOF)
    if (!file.eof()) {
        std::cerr << "Errore nella lettura dei dati!" << std::endl;
    }
    
    file.close();
    
    cout << calcolaMedia(head);
    
	return 0;
}








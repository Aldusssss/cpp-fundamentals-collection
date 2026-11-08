#include <iostream>
using namespace std;


struct Nodo{
	int num;
	Nodo *ptr;
};


void printList(Nodo *head){
 	Nodo *curr = head;
 	if (head == NULL){
 		cout << "Empty list";
 		return;
 	}
 	while (curr != NULL){
 		cout << curr->num << " ";
 		curr = curr->ptr;
 		}
	}

int main(){
	
	
	Nodo *head = new Nodo;
    Nodo *current = head;  // ?? USA VARIABILE TEMPORANEA
    
    int dim;
    
    do{
        cout << "Inserisci Quanti numeri vuoi inserire: "<<endl;
        cin >> dim;
    }while(dim<=0);
    
    // Inserisci numeri
    for (int i=0;i<dim;i++){
        cout << "Inserisci il numero in posizione["<<i<<"]: "<<endl;
        cin >> current->num;
        current->ptr = nullptr;
        
        if (i < dim - 1) {
            current->ptr = new Nodo();
            current = current->ptr;
        }
    }
	
	//inverti lista
	//creo nuovi puntatori
	Nodo *pre = nullptr;
    Nodo *curr = head;
    Nodo *next = nullptr;
    
    while(curr != nullptr){
        next = curr->ptr;
        curr->ptr = pre;
        pre = curr;
        curr = next;
    }
	head = pre;
	
printList(head);		
	
	
	
	return 0;
}
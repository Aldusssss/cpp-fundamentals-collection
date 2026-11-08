#include <iostream>
using namespace std;

struct Node{
 int num; 		// contiene il numero intero
 Node *nextPtr; // contiene il puntatore al nodo successivo
};


int main(){
	
	int DIM=2;
	
    Node* primo = new Node{15, nullptr};
    Node* secondo = new Node{3, nullptr};
    //Node* terzo = new Node{5, nullptr};
    
    // Li collego
    primo->nextPtr = secondo;
    //secondo->nextPtr = terzo;
    
    // Testa della lista
    Node* testa = primo;
    
    // STAMPA
    cout << "Contenuto array: ";
    Node* current = testa;
    while(current != nullptr) {
        cout << current->num << " ";
        current = current->nextPtr;
    }
    cout << endl;
    
    //ordina
	
	for(int i = 0; i < DIM - 1; i++) {
		Node* current = testa;
        for(int j = 0; j < DIM - i - 1; j++) {
            // Confronta elementi adiacenti
            
            if(current->num > current->nextPtr->num ) {
                // Scambia
                int temp = current->num;
                current->num = current->nextPtr->num;
                current->nextPtr->num = temp;
                
            }
            //aumenta
                current = current->nextPtr;
        }
        
    
}
	
	if(DIM%2==0){
		//pari
		int j=(DIM/2);
		int mediana;
		Node* current = testa;
		while(current != nullptr && j==0){
        	current = current->nextPtr;
        	j--;
    	}
    	cout << "La mediana e: "<<current->num  <<endl;
		
	}else{
		//dispari
		int k=(DIM/2)+1;
		int mediana;
		Node* current = testa;
		do{
        	
        	current = current->nextPtr;
        	k--;
    	}while(current != nullptr && k==0);
    	cout << "La mediana e: "<< current->num  <<endl;
	}
	
	
	
	

	
	return 0;


}
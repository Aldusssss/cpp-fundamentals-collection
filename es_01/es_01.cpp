#include <iostream>
using namespace std;
int main(){
	int num1,num2;
	int temp;
	int mcd=1;
	cout << "Inserisci 2 numeri interi e positivi, e calcolo il MCD." << endl;
	
	//l'utente inserisce num1 intero pos
	do{
		cout << "Inserisci il primo numero:";
		cin >> temp;
	}while(temp<=0);
	
	num1=temp;
	
	//l'utente inserisce num2 intero pos
	do{
		cout << "Inserisci il secondo numero:";
		cin >> temp;
	}while(temp<=0);
	
	num2=temp;
	
	//calcolo MCD
	
	//num1:5 num2:10
	if(num1==num2){
		mcd=num1;
	}else{
		//max num1
		if(num1<num2){
			int min=num1;
			do{
				if(num2%min==0){
					mcd=min;
					break;
				}
				
				min--;
				
			}while(min>0);
			
			
		}else{
			
			int min=num2;
			do{
				if(num1%min==0){
					mcd=min;
					break;
				}
				
				min--;
				
			}while(min>0);
			
		}

	}
	
	cout << "Numero 1 " << num1  << "Numero 2 " << num2 << "MCD: "<< mcd;

	
	
	
	return 0;
}
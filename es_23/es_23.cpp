#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>

using namespace std;


std::string CifraCesare(std::string stringaNormale){
	
	std::string stringaCifrata=stringaNormale;
	srand(time(0));
	int offset= rand() % (10 - 1 + 1) + 1;
	
	for(int i=0;i<stringaNormale.length();i++){
		stringaCifrata[i]=char(stringaCifrata[i]+offset);
	}
	
	return stringaCifrata;
}


int main() {
    std::ifstream file("file.txt");
    
    
    if(!file.is_open()){
    	cout << "Il file NON si e aperto correttamente"<<endl;
	}
	
	std::string stringaFinale="";
    std::string riga;
    
	while (std::getline(file, riga)) {
       //in riga
       stringaFinale=stringaFinale+CifraCesare(riga);
       stringaFinale=stringaFinale+"\n";
    }

    // Verifica se c e stato un errore (non EOF)
    if (!file.eof()) {
        std::cerr << "Errore nella lettura dei dati!" << std::endl;
    }
    
    file.close();
    cout << stringaFinale;
    
    
    //scrivo su un file: fileW

    std::ofstream fileW("fileW.txt");
    fileW<<stringaFinale;
    fileW.close();
    
    
    
    
	return 0;
}








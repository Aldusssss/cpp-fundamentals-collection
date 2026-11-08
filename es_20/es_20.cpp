#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

class Complesso{
	private:
		double a,b,r;
		int q;
		
	public:
		
	double getA(){
		return a;
	}
	void setA(double a){
		this->a=a;
	}	
	
	double getB(){
		return b;
	}
	void setB(double b){
		this->b=b;
	}
	
	double getR(){
		return r;
	}
	void setR(double r){
		this->r=r;
	}
	
	int getQ(){
		return q;
	}
	void setQ(int q){
		this->q=q;
	}
		
		
		Complesso(double a,double b){
			this->a=a;
			this->b=b;
			//ricavo r,q
			this->r=sqrt(a*a+b*b);
 			this->q=atan(b/a);
		}
		
	Complesso(double r,int q){
			this->r=r;
			this->q=q;
			//ricavo a,b
			this->a=r*cos(q);
 			this->b=r*sin(q);
		}	
		
	SommaProdottoAlgebrico(double a2,double b2){
		// Notazione algebrica:
		//(a1+ib1)+(a2+ib2)=(a1+a2)+i(b1+b2)
		
		cout << "("<<getA()<<"+"<<getB()<<"i"<<")+("<<a2<<"+"<<b2<<"i)";
		cout << "="<<getA()+a2<<"+i("<<getB()+b2<<")"<<endl;
		
	}
	
	
	SommaProdottoPolare(double r2,int q2){
		// Notazione polare:
		//(r1,q1)*(r2,q2)=(r1+r2,q1+q2)
		
		cout << "("<<getR()<<","<<getQ()<<")*("<<r2<<","<<q2<<")";
		cout << "=("<<getR()+r2<<","<<getQ()+q2<<")"<<endl;
		
	}
	
	bool uguali(double a,double b){
		bool uguali=true;
		if(getA()!=a || getB()!=b){
			uguali=false;
		}
		return uguali;
	}
	
	bool uguali(double r,int q){
		bool uguali=true;
		if(getR()!=r || getQ()!=q){
			uguali=false;
		}
		return uguali;
	}
	
		
	string toStringAlg() {
        stringstream ss;
        if (getB() >= 0) {
            ss << getA() << " + " << getB() << "i"<<endl;
        } else {
            ss << getA() << " - " << -getB() << "i"<<endl;
        }
        return ss.str();
    }
    
    
    string toStringPol() {
        stringstream ss;
        ss << "(" << getR()<<","<<getQ()<<")"<<endl;
        return ss.str();
    }
    
    
    
	
	
};

int main(){
	
	Complesso complesso(1.34, 2.33);  	
	
	cout<< "Forma Algebrica: "<<complesso.toStringAlg();
	cout<< "Forma Polare: "<< complesso.toStringPol();
	complesso.SommaProdottoAlgebrico(3,3);
	complesso.SommaProdottoPolare(2,1);
	if(complesso.uguali(1.34,2.32)){
		cout << "sono uguali";
	}else{
		cout << "Non sono uguali";
	}
	
	return 0;
	
	
	
}
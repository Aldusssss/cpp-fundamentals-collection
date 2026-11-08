#include <iostream>
#include <cmath>
using namespace std;

class PolynomialTerm {
private:
    int degree;
    double coeff;
    PolynomialTerm *next;

public:
    PolynomialTerm(int degree, double coeff) {
        this->degree = degree;
        this->coeff = coeff;
        this->next = nullptr;
    }

    double calculateTermValue(double v) {
        return this->coeff * pow(v, this->degree);
    }

    void setDegree(int degree) {
        this->degree = degree;
    }

    int getDegree() const {
        return this->degree;
    }

    void setCoeff(double coeff) {
        this->coeff = coeff;
    }

    double getCoeff() const {
        return this->coeff;
    }

    void setNext(PolynomialTerm *term) {
        this->next = term;
    }

    PolynomialTerm *getNext() const {
        return this->next;
    }
};

class Polynomial {
private:
    PolynomialTerm *head;

    void addTermRecursive(PolynomialTerm *head, PolynomialTerm *prev, int degree, double coeff) {
        if (degree > head->getDegree()) {
            PolynomialTerm *newTerm = new PolynomialTerm(degree, coeff);
            newTerm->setNext(head);
            if (prev != nullptr) {
                prev->setNext(newTerm);
            } else {
                this->head = newTerm;
            }
        } else if (degree == head->getDegree()) {
            head->setCoeff(head->getCoeff() + coeff);
            // Se il coefficiente diventa zero, rimuovi il termine
            if (head->getCoeff() == 0 && prev != nullptr) {
                prev->setNext(head->getNext());
                delete head;
            }
        } else if (head->getNext() == nullptr) {
            PolynomialTerm *newTerm = new PolynomialTerm(degree, coeff);
            head->setNext(newTerm);
        } else {
            addTermRecursive(head->getNext(), head, degree, coeff);
        }
    }

    double calculatePolynomialValueRecursive(PolynomialTerm *head, double val) const {
        if (head == nullptr)
            return 0.0;
        else
            return head->calculateTermValue(val) + calculatePolynomialValueRecursive(head->getNext(), val);
    }

    void clearPolynomialRecursive(PolynomialTerm *head) {
        if (head != nullptr) {
            clearPolynomialRecursive(head->getNext());
            delete head;
        }
    }

    void printPolynomialRecursive(PolynomialTerm *head) const {
        if (head == nullptr) {
            cout << "0";
        } else if (head->getNext() != nullptr) {
            if (head->getCoeff() != 0) {
                cout << head->getCoeff();
                if (head->getDegree() > 0) {
                    cout << "x";
                    if (head->getDegree() > 1) {
                        cout << "^" << head->getDegree();
                    }
                }
                cout << " + ";
            }
            printPolynomialRecursive(head->getNext());
        } else {
            if (head->getCoeff() != 0) {
                cout << head->getCoeff();
                if (head->getDegree() > 0) {
                    cout << "x";
                    if (head->getDegree() > 1) {
                        cout << "^" << head->getDegree();
                    }
                }
            } else {
                cout << "0";
            }
        }
    }

    void copyPolynomial(const Polynomial &other) {
        this->head = new PolynomialTerm(0, 0);
        PolynomialTerm *current = other.head;
        while (current != nullptr) {
            if (current->getCoeff() != 0) {
                this->addTerm(current->getDegree(), current->getCoeff());
            }
            current = current->getNext();
        }
    }

public:
    Polynomial() {
        this->head = new PolynomialTerm(0, 0);
    }

    Polynomial(const Polynomial &other) {
        this->head = nullptr;
        copyPolynomial(other);
    }

    ~Polynomial() {
        clearPolynomial();
    }
    
    Polynomial& operator=(const Polynomial &other) {
        if (this != &other) {
            clearPolynomial();
            copyPolynomial(other);
        }
        return *this;
    }

    bool operator==(const Polynomial &pol) const {
        PolynomialTerm *curr1 = this->head;
        PolynomialTerm *curr2 = pol.head;
        
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->getCoeff() != 0 || curr2->getCoeff() != 0) {
                if ((curr1->getDegree() != curr2->getDegree()) || 
                    (curr1->getCoeff() != curr2->getCoeff())) {
                    return false;
                }
            }
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
        }
        
        // Controlla se entrambe le liste sono terminate
        while (curr1 != nullptr && curr1->getCoeff() == 0) curr1 = curr1->getNext();
        while (curr2 != nullptr && curr2->getCoeff() == 0) curr2 = curr2->getNext();
        
        return (curr1 == nullptr && curr2 == nullptr);
    }

    PolynomialTerm *getHead() const {
        return this->head;
    }

    void addTerm(int degree, double coeff) {
        if (coeff != 0) {
            addTermRecursive(this->head, nullptr, degree, coeff);
        }
    }

    double calculatePolynomialValue(double val) const {
        return calculatePolynomialValueRecursive(this->head, val);
    }

    int getMaxDegree() const {
        PolynomialTerm *current = this->head;
        int maxDegree = 0;
        while (current != nullptr) {
            if (current->getCoeff() != 0 && current->getDegree() > maxDegree) {
                maxDegree = current->getDegree();
            }
            current = current->getNext();
        }
        return maxDegree;
    }

    void addPolynomial(const Polynomial &otherPolin) {
        PolynomialTerm *currentTerm = otherPolin.head;
        while (currentTerm != nullptr) {
            if (currentTerm->getCoeff() != 0) {
                this->addTerm(currentTerm->getDegree(), currentTerm->getCoeff());
            }
            currentTerm = currentTerm->getNext();
        }
    }

    void clearPolynomial() {
        if (this->head != nullptr) {
            clearPolynomialRecursive(this->head->getNext());
            this->head->setCoeff(0);
            this->head->setDegree(0);
        }
    }

    void printPolynomial() const {
        printPolynomialRecursive(this->head);
    }
};

int main() {
    cout << "=== TEST CLASSE POLINOMIO ===" << endl << endl;

    Polynomial pol1, pol2, pol3, sum;

    // Creazione del primo polinomio: 3x^2 + 2x + 1
    cout << "Creazione polinomio #1: 3x^2 + 2x + 1" << endl;
    pol1.addTerm(0, 1.0);
    pol1.addTerm(1, 2.0);
    pol1.addTerm(2, 3.0);

    // Creazione del secondo polinomio: x^3 + 3x^2 + 3x + 1
    cout << "Creazione polinomio #2: x^3 + 3x^2 + 3x + 1" << endl;
    pol2.addTerm(0, 1.0);
    pol2.addTerm(1, 3.0);
    pol2.addTerm(2, 3.0);
    pol2.addTerm(3, 1.0);

    cout << endl << "=== STAMPA POLINOMI ===" << endl;
    cout << "Polinomio #1: ";
    pol1.printPolynomial();
    cout << endl;
    
    cout << "Polinomio #2: ";
    pol2.printPolynomial();
    cout << endl;

    cout << endl << "=== CALCOLO VALORI ===" << endl;
    cout << "Valore del polinomio #1 per x = 1: " << pol1.calculatePolynomialValue(1) << endl;
    cout << "Valore del polinomio #2 per x = 1: " << pol2.calculatePolynomialValue(1) << endl;
    cout << "Valore del polinomio #1 per x = 2: " << pol1.calculatePolynomialValue(2) << endl;
    cout << "Valore del polinomio #2 per x = 2: " << pol2.calculatePolynomialValue(2) << endl;
    cout << "Valore del polinomio #1 per x = 0: " << pol1.calculatePolynomialValue(0) << endl;

    cout << endl << "=== GRADO DEI POLINOMI ===" << endl;
    cout << "Grado del polinomio #1: " << pol1.getMaxDegree() << endl;
    cout << "Grado del polinomio #2: " << pol2.getMaxDegree() << endl;

    cout << endl << "=== TEST OPERATORE DI ASSEGNAZIONE ===" << endl;
    pol3 = pol1;
    cout << "Polinomio #3 (copia di #1): ";
    pol3.printPolynomial();
    cout << endl;

    cout << endl << "=== TEST OPERATORE DI UGUAGLIANZA ===" << endl;
    cout << "Il polinomio #1 è uguale al polinomio #2? " << (pol1 == pol2 ? "SI" : "NO") << endl;
    cout << "Il polinomio #1 è uguale al polinomio #3? " << (pol1 == pol3 ? "SI" : "NO") << endl;

    cout << endl << "=== SOMMA DI POLINOMI ===" << endl;
    sum = pol1;
    sum.addPolynomial(pol2);
    cout << "Somma (#1 + #2): ";
    sum.printPolynomial();
    cout << endl;

    cout << endl << "=== TEST EXTRA ===" << endl;
    
    // Test con polinomio vuoto
    Polynomial pol4;
    cout << "Polinomio vuoto: ";
    pol4.printPolynomial();
    cout << endl;
    cout << "Grado polinomio vuoto: " << pol4.getMaxDegree() << endl;

    // Test aggiunta termini che si annullano
    Polynomial pol5;
    pol5.addTerm(2, 5.0);
    pol5.addTerm(2, -5.0); // Dovrebbe annullarsi
    cout << "Polinomio con termini annullati: ";
    pol5.printPolynomial();
    cout << endl;

    // Test somma con polinomio vuoto
    Polynomial pol6 = pol1;
    pol6.addPolynomial(pol4);
    cout << "Somma con polinomio vuoto: ";
    pol6.printPolynomial();
    cout << " (uguale al polinomio #1)" << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    const char STOPPER = '$';
    char ch;
    int totChars = 0;
    int totLowChars = 0;
    int totDigits = 0;
    
    cin.unsetf(ios::skipws);
    
    cout << "Please enter a text terminated by " << STOPPER << endl;
    cin >> ch; // or get getchar()
    

    while(ch != STOPPER) {
        totChars++;

        if(ch >= 'a' && ch <= 'z') {
            totLowChars++;
        }

        else if (ch >= '0' && ch <= '9') {
            totDigits++;
        }

        cin>>ch;
    }

    if (totChars>0) {
        cout << endl << "The percentage of lowercase chars is  ";
        cout << 100*totLowChars/totChars << " %" << endl;
        cout << endl << "The percentage of digits is ";
        cout << 100*totDigits/totChars << " %" << endl;
    } else {
        cout << endl << "No chars were entered" << endl;
    }
    return 0;
}
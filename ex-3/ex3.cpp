#include <iostream>
using namespace std;

int main()
{
    const int STOPPER = 0;
    int num,
        max;

    cout << "Max computation" << endl
         << endl;
    cout << "Enter a sequence of positive integers, terminated by 0" << endl;

    cin >> num;
    max = 0; // INT_MIN or INT_MAX

    while (num != STOPPER)
    {
        if (num > max)
        {
            max = num;
        }

        cin >> num;
    }

    if (max != STOPPER)
    {
        cout << endl
             << "Max is:  " << max << endl
             << endl;
    }
    else
    {
        cout << endl
             << "No numbers were entered" << endl
             << endl;
    }

    return 0;
}
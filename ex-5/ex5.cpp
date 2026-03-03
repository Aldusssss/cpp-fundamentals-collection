#include <iostream>
using namespace std;

int main()
{
    const char STOPPER = '$';
    int lenChars = 0;
    int maxLenChars = 0;
    int lenWord = 0;
    int maxLenWord = 0;
    char ch, prevCh;
    prevCh = ' ';

    cin.unsetf(ios::skipws);
    cout << "Please enter a text terminated by" << STOPPER << endl;
    cin >> ch;

    while (ch != STOPPER)
    {
        lenChars++;
        if ((((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')) || ((ch >= '0') && (ch <= '9'))) && !(((prevCh >= 'a') && (prevCh <= 'z')) || ((prevCh >= 'A') && (prevCh <= 'Z')) || ((prevCh >= '0') && (prevCh <= '9'))))
        {
            lenWord++;
        }
        else if ((ch == '.') || (ch == ';') || (ch == ':'))
        {
            if (lenWord > maxLenWord)
            {
                maxLenWord = lenWord;
            }

            lenWord = 0;

            if (lenChars > maxLenChars)
            {
                maxLenChars = lenChars;
            }
            lenChars = 0;
        }
        prevCh = ch;
        cin >> ch;
    }

    if (lenWord > maxLenWord)
    {
        maxLenWord = lenWord;
    }

    if (lenChars > maxLenChars)
    {
        maxLenChars = lenChars;
    }

    cout << "The number of characters in the max-character period = ";
    cout << maxLenChars << endl;
    cout << endl
         << "The number of words in the max-word period = ";
    cout << maxLenWord << endl;
    return 0;
}
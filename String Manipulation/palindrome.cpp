#include <iostream>
using namespace std;

// Program to find whether a given string is a palindrome or not

int main()
{
    string inp;
    cout << "Enter a string: ";
    getline(cin, inp);

    string pal;
    for (int i = inp.size() - 1; i >= 0; i--)
    {
        pal += inp[i];
    }

    if (pal == inp)
        cout << inp << " is a palindrome.";
    else
        cout << inp << " is not a palindrome.";
    return 0;
}
#include <iostream>
using namespace std;

// Basic program to tell if entered number is positive, negative or 0

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    n == 0 ? cout << "Number is 0!" : n < 0 ? cout << "Number is negative!" : cout << "Number is positive!";
    return 0;
}
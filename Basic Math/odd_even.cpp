#include <iostream>
using namespace std;

// Program to tell whether entered number is even or odd

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    num % 2 == 0 ? cout << "Even Number!" : cout << "Odd Number!";
    return 0;
}

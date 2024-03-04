#include <iostream>
using namespace std;

// To print the multiplication table of a number

int main()
{
    int n, x;
    cout << "Enter number you want to print table of: ";
    cin >> n;
    cout << "Enter till where you want to print the table: ";
    cin >> x;

    for (int i = 1; i < x + 1; i++)
        cout << n << " X " << i << " = " << n*i << endl;
    return 0;
}
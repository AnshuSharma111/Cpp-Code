#include <iostream>
using namespace std;

// Program to convert degree to celsius

int main()
{
    char choice;
    float x, y;
    cout << "Do you want to convert celsius to fahrenheit[c] or fahrenheit to degree[f]: ";
    cin >> choice;

    if (choice == 'c' || choice == 'C')
    {
        cout << "Enter celsius value: ";
        cin >> x;
        y = (x*9.0)/5.0 + 32;
        cout << x << " Degrees = " << y << " Fahrenheit";
    }
    else if(choice == 'f' || choice == 'F')
    {
        cout << "Enter fahrenheit value: ";
        cin >> x;
        y = (x - 32.0)* 5.0/9.0;
        cout << x << " Fahrenheit = " << y << " Degrees";
    }
    else { cout << "Invalid Choice!"; }
    return 0;
}
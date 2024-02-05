#include <iostream>
#include <math.h>
using namespace std;

// Program to check whether entered number is armstrong or not

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    int temp, digits = 0, digit, armstrong = 0, td;
    temp = num;
    while(temp > 0)
    {
        digits += 1;
        temp /= 10;
    }
    temp = num;
    while (temp > 0)
    {
        digit = temp % 10;
        td = digit;
        for (int i = 0; i < digits-1; i++)
        digit *= td;
        armstrong += digit;
        temp /= 10;
    }
    if (armstrong == num)
        cout << num << " is an armstrong number.";
    else
        cout << num << " is not an armstrong number.";
    return 0;
}
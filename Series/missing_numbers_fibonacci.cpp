#include <iostream>
using namespace std;

// Program to print the missing natural numbers in a fibonacci series

int main(){
    int n;
    cout << "Till where do you want to print the fibonacci series? Please enter: ";
    cin >> n;

    int a = 0, b = 1, c, missing_count = 0;
    int *series = new int[n];
    int *missing = new int[100];

    *(series) = a;
    *(series + 1) = b;

    for(int i = 2; i < n; i++){
        c = a+b;
        a = b;
        b = c;

        *(series + i) = c;

        if (b - a > 1){
            for (int j = a+1; j < b; j++){
                *(missing + missing_count) = j;
                missing_count++;
            }
        }
    }

    cout << "Fibonacci Series: ";
    for(int i = 0; i<n; i++)
    cout << *(series + i) << " ";

    cout << "\nMissing Elements: ";
    for (int i = 0; i < missing_count; i++)
    cout << *(missing + i) << " ";

    return 0;
}
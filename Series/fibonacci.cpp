#include <iostream>
using namespace std;

// Program to print the fibonacci series upto first n members

int main(){
    int a = 0, b = 1, c, n;
    cout << "Till where do you want to print the series? Please enter: ";
    cin >> n;

    cout << a << " " << b << " ";
    for(int i = 0; i < n-1; i++){
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    return 0;
}
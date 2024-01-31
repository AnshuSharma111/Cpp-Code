#include <iostream>
#include <string>
using namespace std;

int main(){
    string inp, out;
    cout << "Enter a string: ";
    getline(cin, inp);

    for (char i : inp){
        if(islower(i))
            out += (char)(i-32);
        else if(isupper(i))
            out += (char)(i+32);
        else
            out += i;
    }

    cout << "Reverse case of input string is: ";
    cout << out;
    return 0;
}
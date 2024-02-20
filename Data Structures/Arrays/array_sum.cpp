#include <iostream>
using namespace std;

// Program to take an array of numbers and output their sum

bool isDigitOnly(string str);

int main(){
    int *arr = new int[100];
    cout << "Start entering numbers. Enter any alphabet to stop: ";

    int i = 0, sum = 0;
    char inp[20];
    bool loopCondition = true;

    while(loopCondition){
        cin >> inp;
        if (isDigitOnly(inp)){
            sscanf(inp, "%d", arr+i);
            i++;
        }
        else{
            loopCondition = false;
        }
    }

    cout <<"The array is: ";
    for(int h = 0; h < i; h++){
        sum += *(arr + h);
        cout << *(arr+h) << " ";
    }
    
    cout << endl << "The sum of the numbers is: " << sum;
    return 0;
}

bool isDigitOnly(string str){
    for (int i = 0; i < str.length(); i++){
        if (!isdigit(str[i])){
            return false;
        }
    }
    return true;
}
#include <vector>
#include <iostream>
using namespace std;

// To solve leetcode problem 1291. Sequential Digits

int main(){
    vector<long> res;
    int low, high;
    cout << "Enter lower limit: ";
    cin >> low;
    cout << "Enter upper limit: ";
    cin >> high;

    int lowDigits = 0, highDigits = 0, temp1, temp2;
    temp1 = low;
    temp2 = high;
    while (temp1 > 0)
    {
        lowDigits += 1;
        temp1 /= 10;
    }
    while (temp2 > 0)
    {
        highDigits += 1;
        temp2 /= 10;
    }

    for (int digits = lowDigits; digits <= highDigits; digits++)
    {
        for (int i = 1; i < 9; i++)
        {
            if (i + digits > 10)
            break;

            int num = i;
            int prev = num;
            for (int k = 0; k < digits-1; k++)
            {
                num *=  10;
                prev += 1;
                num += prev;
            }
            
            if (low <= num && num <= high)
            {
                res.push_back(num);
            }
        }
    }

    cout << "All sequential numbers in the range " << low << " and " << high << " are: ";
    for (int k : res)
    {
        cout << k << " "; 
    }

    return 0;
}
#include <iostream>
using namespace std;

// Given an array arr, to find if an element n is present in it and the position of n in arr

int main()
{
    int arr[100];
    int s, n, flag = 0;

    cout << "How many elements do you want in the array? Please enter: ";
    cin >> s;

    cout << "Enter array elements: ";
    for (int i = 0; i < s; i++)
        cin >> arr[i];
    
    cout << "Enter element to find: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == n)
        {
            flag = 1;
            cout << n << " found at position " << i+1;
            break;
        }
    }

    if (flag == 0)
        cout << n << " was not found in the array.";
    return 0;
}
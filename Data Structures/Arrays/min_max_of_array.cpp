#include <iostream>
using namespace std;

int main()
{
    int arr[100], n;
    cout << "How many elements do you want in the array> Please enter: ";
    cin >> n;

    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max) { max = arr[i]; }
        else if (arr[i] < min) { min = arr[i]; }
    }
    cout << "Maiximum value of array is: " << max << endl;
    cout << "Minimum value of array is: " << min;
    return 0;
}
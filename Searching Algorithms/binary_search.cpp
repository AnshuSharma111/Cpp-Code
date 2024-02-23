#include <iostream>
using namespace std;

//Given a sorted array arr, find the position of integer n if it is in the array

int main()
{
    int arr[100], s, n, flag = 0;
    cout << "How many elements do you want in the array? Enter: ";
    cin >> s;

    cout << "Enter elements in ascending or descending order: ";
    for (int i =0; i < s; i++)
        cin >> arr[i];
    
    cout << "Enter element you want to find: ";
    cin >> n;

    int left = 0, right = s-1, mid;
    while (left <= right)
    {
        mid = (int)((left + right) / 2);

        if (arr[mid] == n)
        {
            flag = 1;
            cout << n << " found at position " << mid+1;
            break;
        }
        else if (arr[mid] < n)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (flag == 0)
        cout << n << " was not found.";
    return 0;
}
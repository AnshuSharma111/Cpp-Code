#include <iostream>
#include <vector>
using namespace std;

// C++ program to demonstrate insertion sort

void insertion_sort(vector<int>& arr);

int main()
{
    vector<int> arr;
    int n, e;

    cout << "How many elements do you want in the array? Pelase enter: ";
    cin >> n;

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> e;
        arr.push_back(e);
    }

    insertion_sort(arr);
    cout << "Sorted Array is: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}

void insertion_sort(vector<int>& arr)
{
    int i = 1;
    while (i < arr.size())
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        i++;
    }
}
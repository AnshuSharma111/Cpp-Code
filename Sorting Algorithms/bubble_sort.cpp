#include <iostream>
#include <vector>
using namespace std;

// Program to demonstrate bubble sort

void bubbleSort(vector<int> *arr)
{
    for (int i =0; i < arr->size(); i++)
    {
        for (int j = 0; j < arr->size() - i - 1; j++)
        {
            if (arr->at(j) < arr->at(j+1))
            {
                int temp = arr->at(j+1);
                arr->at(j+1) = arr->at(j);
                arr->at(j) = temp;
            }
        }
    }
}

int main()
{
    vector<int> arr;
    int n, ele;
    cout << "How many elements do you want in the array. Please enter: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }

    bubbleSort(&arr);
    cout << "Sorted array is: ";
    for (int i : arr)
        cout << i << " ";
    return 0;
}
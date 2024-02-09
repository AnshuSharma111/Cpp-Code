#include <iostream>
#include <vector>
using namespace std;

// Program to showcase selection sort algorithm for sorting. O(n^2)

void selection_sort(vector<int> *arr);

int main()
{
    int n, ele;
    cout << "Enter number of elements in input array: ";
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }

    selection_sort(&arr);
    for (int i : arr)
    cout << i << " ";

    return 0;
}

void selection_sort(vector<int> *arr)
{
    for (int i = 0; i < arr->size()-1; i++)
    {
        int smallest = 99999999, index = i;
        for(int j = i; j < arr->size(); j++)
        {
            if (arr->at(j) < smallest)
            {
                smallest = arr->at(j);
                index = j;
            }
        }
        int temp = arr->at(i);
        arr->at(i) = smallest;
        arr->at(index) = temp;
    }
}
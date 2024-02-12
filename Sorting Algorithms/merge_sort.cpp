#include <iostream>
#include <vector>
using namespace std;

// Program to demonstrate merge sort algorithm in C++

vector<int> merge_sort(vector<int> arr);
vector<int> merge(vector<int> left, vector<int> right);

int main()
{
    vector<int> arr;
    int sizeArr, ele;
    cout << "Enter the number of elements you want to enter: ";
    cin >> sizeArr;
    cout << "Enter array elements: ";
    for (int i =0; i < sizeArr; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }

    cout << "The sorted array is: ";
    vector<int> res = merge_sort(arr);
    for (int i : res)
        cout << i << " ";
    return 0;
}

vector<int> merge_sort(vector<int> arr)
{
    // Base Case
    if (arr.size() == 1)
    {
        return arr;
    }

    // Dividing Array
    int mid = arr.size() / 2;

    vector<int> left = vector<int>(arr.begin(), arr.begin()+mid);
    vector<int> right = vector<int>(arr.begin()+mid, arr.end());

    vector<int> left_res = merge_sort(left);
    vector<int> right_res = merge_sort(right);

    vector<int> res = merge(left_res, right_res);
    
    return res;
}

vector<int> merge(vector<int> left, vector<int> right)
{
    int leftSize = left.size();
    int rightSize = right.size();
    vector<int> res;

    int lCount = 0, rCount = 0;
    while (lCount < leftSize && rCount < rightSize)
    {
        if (left[lCount] > right[rCount])
        {
            res.push_back(right[rCount]);
            rCount++;
        }
        else
        {
            res.push_back(left[lCount]);
            lCount++;
        }
    }

    while (lCount < leftSize) { res.push_back(left[lCount]); lCount++; }
    while (rCount < rightSize) { res.push_back(right[rCount]); rCount++; }

    return res;
}
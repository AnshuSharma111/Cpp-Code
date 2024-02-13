#include <iostream>
#include <vector>
using namespace std;

// Leetcode 2108. Find first palindromic substring in an array

string firstPalindrome(vector<string>& words) {
    int length, leftPointer, rightPointer;
    bool isPal = true;
    for (string i : words)
    {
        isPal = true;
        rightPointer = i.size()-1;
        leftPointer = 0;
        length = i.size() / 2;
        while (leftPointer < length && rightPointer >= length)
        {
            if (i[leftPointer] != i[rightPointer]) 
            {
                isPal = false;
                break;
            }
            leftPointer++;
            rightPointer--;
        }

        if (isPal == true)
            return i;
    }
    return "";
}

int main()
{
    vector<string> arr;
    int n;
    string ele;
    cout << "Enter number of elements in string array: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }
    string res = firstPalindrome(arr);
    if (res == "")
        cout << "No palindromic substring exists in the array";
    else
        cout << "The first palindromic substring in the array is: " << res;
    return 0;
}
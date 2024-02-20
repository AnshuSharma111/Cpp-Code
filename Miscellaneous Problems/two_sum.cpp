#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Leetcode #7: To take an array and a target sum and check whether any 2 elements from the array sum up to it  

int main()
{
    map<int, int> hashmap;
    vector<int> arr;
    int target, n, ele;

    cout << "How many elements do you want in the array: ";
    cin >> n;
    cout << "Enter the array: ";
    while (n--)
    {
        cin >> ele;
        arr.push_back(ele);
    }
    cout << "Enter the target element: ";
    cin >> target;

    int diff; bool hasFound = false;
    for (int i : arr)
    {
        diff = target - i;
        map<int, int>::iterator it = hashmap.begin();
        while(it != hashmap.end())
        {
            if (it->first == i) 
            {
                cout << "The numbers that sum to " << target << " are: "; 
                cout << "[" << it->first << ", " << it->second << "]";
                hasFound = true;
                break;  
            }
            it++;
        }
        if (hasFound) { break; }
        hashmap[diff] = i;
    }

    if (!hasFound) { cout << "No two numbers in the array sum to " << target; }
    return 0;
}
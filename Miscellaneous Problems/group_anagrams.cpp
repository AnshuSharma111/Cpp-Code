#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// This is Leetcode 49. Group Anagrams

int main()
{
    vector<string> inp;
    int n;
    string ele;
    cout << "Enter number of elements in array: ";
    cin >> n;
    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        inp.push_back(ele);
    }

    map<string, vector<string>> hashmap;
    
    for (string i : inp)
    {
        string copy = i;
        sort(copy.begin(), copy.end());
        hashmap[copy].push_back(i); 
    }

    cout <<"The anagram pairs are: [ " << endl;
    map<string, vector<string>>::iterator it = hashmap.begin();
    while (it != hashmap.end())
    {
        cout << "[ ";
        for (string j : it->second)
            cout << j << " ";
        cout << " ]" << endl;
        it++;
    }
    cout << "]";
    return 0;
}
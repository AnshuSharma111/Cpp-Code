#include <iostream>
#include <string>
using namespace std;


// This is a C++ solution to LeetCode 647. Palindromic Substrings. To return the number of palindromic substrings in a given string

int main()
{
    string s;
    cout << "Enter string to find number of palindromic substrings of: ";
    cin >> s;

    int l, r, res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        l = i; r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            res++;
            l--;
            r++;
        }
        l = i; r = i+1;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            res++;
            l--;
            r++;
        }
    }
    cout << "The number of palindromic substrings are: " << res;
    return 0;
}
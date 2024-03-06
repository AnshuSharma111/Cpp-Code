#include <iostream>
#include <stack>
using namespace std;

// To reverse a string using stack

void reverse(string &str);

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    reverse(str);
    cout << "Reverse string is: " << str;
}

void reverse(string &str)
{
    int l = str.length();
    stack<char> s;

    for(int i = 0; i < l; i ++)
    s.push(str[i]);

    for(int i = 0; i < l; i++)
    {
        str[i] = s.top();
        s.pop();
    }
}
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// This program is a C++ solution to leetcode 20. Valid Parenthesess

bool isValidInput(string inp);
bool isValidCombination(string inp);

int main()
{
    // Take input
    string input;
    cout << "Enter a bracket combination of () {} []: ";
    cin >> input;

    // Check if input is valid
    if (!isValidInput(input)) { cout << "Invalid Input!"; exit(0); };

    // Check if input is a valid combination
    if (isValidCombination(input))
        cout << "The give string is a valid combination of parentheses!";
    else
        cout << "The given string is not a valid combination of parentheses";
    return 0;
}

bool isValidInput(string inp)
{
    for (char c : inp)
    {
        if (c != '(' && c != ')' && c != '{' && c != '}' && c != '[' && c != ']')
            return false;
    }
    return true;
}

bool isValidCombination(string inp)
{
    vector<char> stack;
    int current = 0;

    // Hash Map to store closing brackets and their respective opening ones.
    map<char, char> openClose;
    openClose = {{ ')', '('}, {'}', '{'}, {']', '['}};

    for (char i : inp)
    {
        // No conditions for entering opening bracket
        if (i == '(' || i == '{' || i == '[')
        {
            stack.push_back(i);
            current = stack.size() - 1;
        }
        // If stack is empty and we are trying to insert a closing bracket in it, that is invalid. Or if we use a closing bracket without an apt open one.
        else if (stack.size() == 0 || openClose[i] != stack[current]) { return false; }
        // If the entered closing bracket is apt, then we pop the corresponding opening one with it
        else
        {
            stack.pop_back();
            current = stack.size() - 1;
        }
    }

    if (stack.size() != 0) { return false; }
    return true;
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op){
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    else if (op == '^') return 3;
    return -1;
}

char associativity(char op){
    if (op == '^') return 'R';
    return 'L';
}

string infixToPostfix(string exp){
    string res;
    stack<char> st; 
    for(int i = 0; i < exp.size(); i++){
        // Evaluate each charracter
        // If the character is an operand, add it to the stack
        if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z' || exp[i] >= '0' && exp[i] <= '9')
            res += exp[i];
        // If the cahracter is an opening bracket, add it to the stack
        else if (exp[i] == '(')
            st.push(exp[i]);
        // closing bracket
        else if (exp[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        // If we have an operator
        else{
            while(!st.empty() && precedence(exp[i]) <= precedence(st.top()) && associativity(st.top()) == 'L'){
                res += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

int main(){
    string exp;
    cout << "Enter an expression to convert to postfix notation: ";
    getline(cin, exp);
    cout << "The postfix notation for the above expression is: " << infixToPostfix(exp);
    return 0;
}
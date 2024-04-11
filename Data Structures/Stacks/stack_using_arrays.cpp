#include <iostream>
#include <string.h>
using namespace std;

// Stack Implementation using arrays

class Stack{
    private:
        int stack[20];
        int top;
    public:
        Stack(){
            top = -1;
            memset(stack, 0, sizeof(stack));
        }
        bool isEmpty(){
            if (top == -1) return true;
            return false;
        }
        bool isFull(){
            if (top == 20) return true;
            return false;
        }
        void push(int data){
            if (isFull()) { cout << "Stack Overflow!\n"; return;}
            top++;
            stack[top] = data;
        }
        int pop(){
            if (isEmpty()) { cout << "Stack Underflow!\n"; return 0;}
            int ret = stack[top];
            stack[top] = 0;
            top--;
            return ret;
        }
        int peek(){
            return stack[top];
        }
        void display(){
            for(int i = top; i >= 0; i--)
                cout << stack[i] << " ";
            cout << endl;
        }
        int count(){ return top + 1; }
};

int main(){
    Stack s;
    char ch;
    int ele;
    do{
        cout << "Welcome to the ultimate stack program! What do you wish to perform?\n1) Push\n2) Pop\n3) Peek\n4) Display\n5) Count\n6) Exit\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            cout << "Enter element to enter: ";
            cin >> ele;
            s.push(ele);
            break;
        case '2':
            cout << "Element popped is: " << s.pop();
            break;
        case '3':
            cout << "The top element is: " << s.peek() << endl;
            break;
        case '4':
            s.display();
            break;
        case '5':
            cout << "There are " << s.count() << " elements in the stack\n";
            break;
        default:
            break;
        }
    }
    while (ch != '6');
    return 0;
}
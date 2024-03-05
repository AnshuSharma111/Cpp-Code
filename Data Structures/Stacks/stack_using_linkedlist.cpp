#include <iostream>
using namespace std;

// Cpp implementation of stack data structure

class Stack
{
    struct Node
    {
        int data;
        struct Node* next = NULL;
    };
    struct Node* top = NULL;

    public:
        void push(int data)
        {
            struct Node* temp = (struct Node*) malloc(sizeof(Node));
            temp->data = data;
            temp->next = top;
            top = temp;
        }
        void print()
        {
            struct Node* traverse = top;
            while (traverse != NULL){
                cout << traverse->data << " ";
                traverse = traverse->next;
            }
            cout << "\n";
        }
        void pop()
        {
            if (top == NULL) { cout << "Enpty stack!\n"; return; }
            struct Node* temp;
            temp = top;
            top = top->next;
            free(temp);
        }
};

int main()
{
    Stack stack;
    stack.pop();

    stack.push(5);
    stack.push(87);
    stack.push(534);
    stack.push(12);

    stack.print();

    stack.pop();
    stack.pop();

    stack.print();
    return 0;
}
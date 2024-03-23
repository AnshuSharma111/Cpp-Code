#include <iostream>
#include <stack>
using namespace std;

// Linked List Implementation
struct Node
{
    int data;
    Node* next;

    Node(int d)
    { 
        data = d;
        next = nullptr; 
    }
};

class LinkedList
{
    private:
        Node* head = nullptr;
        int length;

    public:
        LinkedList(){ length = 0; }

        void insert(int pos, int data) 
        {
            length += 1;
            Node* temp = new Node(data);
            if (pos == 1)
            { 
                temp->next = head;
                head = temp;
                return;
            }

            Node *traversal = head;
            int i = 0;
            while (i < pos-2)
            {
                traversal = traversal->next;
                ++i;
            }
            temp->next = traversal->next;
            traversal->next = temp;
        }
        void print()
        {
            Node* traversal = head;
            while (traversal)
            {
                cout << traversal->data << " ";
                traversal = traversal->next;
            }
        }
        void reverse(){
             stack<struct Node*> st;
            struct Node* temp = head;
            while(temp != NULL){
                st.push(temp);
                temp = temp->next;
            }

            temp = st.top(); head = temp;
            st.pop();
            while (!st.empty()){
                temp->next = st.top();
                st.pop();
                temp = temp->next;
            }
            temp->next = NULL;
        }
        int size() { return length; }
        struct Node* gethead() { return head; }
};

// Linked List implementation end


int main(){
    LinkedList ll;
    ll.insert(1, 12);
    ll.insert(1, 4);
    ll.insert(1, 190);
    ll.insert(1, 45);
    ll.print();

    ll.reverse();
    cout << endl;
    ll.print();
    return 0;
}
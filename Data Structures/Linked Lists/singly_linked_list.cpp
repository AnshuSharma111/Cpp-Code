#include <iostream>
using namespace std;

class LinkedList
{
    private:
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
        int size() { return length; }
};

int main()
{
    LinkedList linkedlist;
    int n, ele;
    cout << "Let us first initialise a linked list.\nEnter how many elements you want in the linked list: ";
    cin >> n;
    while (n--) 
    {
        cout << "Enter value to insert: ";
        cin >> ele;
        linkedlist.insert(1, ele);
    }
    cout << "Current linked list is: ";
    linkedlist.print();
    cout << endl;

    bool programRunning = true;
    while (programRunning) 
    {
        char ch;
        int pos;
        cout << "What do you want to do with the linked list? Enter your choice.\n1)Insert element\n2)Print list\n3)Exit\nEnter Choice: ";
        cin >> ch;
        switch (ch)
        {
            case '1':
                cout << "Enter element to enter: ";
                cin >> ele;
                cout << "Enter position to enter: ";
                cin >> pos;
                linkedlist.insert(pos, ele);
                cout << "After insertion the list is: ";
                linkedlist.print();
                cout << endl;
                break;
            case '2':
                cout << "The list is: ";
                linkedlist.print();
                cout << endl;
                break;
            case '3':
                programRunning = false;
                break;
            default:
                cout << "Invalid Choice. Please try again!\n";
                break;
        }

    }
    return 0;
}
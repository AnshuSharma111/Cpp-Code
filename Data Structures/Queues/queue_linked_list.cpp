#include <iostream>
using namespace std;

class Queue{
    private:
        struct node{
            int data;
            node* next;
            node(){
                data = 0;
                next = nullptr;
            }
        };
        int max_length;
        int cur_length;
        struct node* front;
        struct node* rear;
    public:
        Queue(int m_l){
            front = nullptr;
            rear = nullptr;
            max_length = m_l;
            cur_length = 0;
        }
        bool isFull(){
            if (cur_length == max_length) return true;
            return false;
        }
        bool isEmpty(){
            if (cur_length == 0) return true;
            return false;
        }
        void enqueue(int data){
            if (isFull()){
                cout << "Full Queue!\n";
                return;
            }
            struct node* newEle = new node;
            newEle->data = data;
            // Empty Queue
            if(!front && !rear){
                front = newEle;
                rear = newEle;
                cur_length += 1;
                return;
            }
            // Non-Empty Queue
            rear->next = newEle;
            rear = newEle;
            cur_length += 1;
        }
        void dequeue(){
            // If empty
            if (isEmpty()){
                cout << "No element to delete!\n";
                return;
            }
            struct node* toDelete = front;
            // Only one element
            if (front == rear){
                front = nullptr;
                rear = nullptr;
                delete toDelete;
                cur_length -= 1;
            }
            front = toDelete->next;
            delete toDelete;
            cur_length -= 1;
        }
        void print(){
            struct node* trav = front;
            while (trav != NULL){
                cout << trav->data << " ";
                trav = trav->next;
            }
            cout << endl;
        }
        void displayStatus(){
            if (isFull()) { cout << "Queue is Full!\n"; }
            else if(isEmpty()){ cout << "Queue is empty!\n";}
            else { cout << "Queue is niether empty nor full\n";}
        }
};

int main(){
    Queue q(10);
    char ch;
    int item;
    do{
        cout << "What to do?\n1) Enqueue\n2) Dequeue\n3) Display\n4) Display Status\nEnter Choice (q to quit): ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            cout << "Enter element to insert: ";
            cin >> item;
            q.enqueue(item);
            break;
        case '2':
            q.dequeue();
            cout << "Performed Dequeue Operation!\n";
        case '3':
            q.print();
            break;
        case '4':
            q.displayStatus();
            break;
        default:
            cout << "Invalid Choice!\n";
            break;
        }
    }
    while(ch != 'q');
    q.enqueue(4);
    q.enqueue(11);
    q.enqueue(7);
    q.enqueue(56);
    q.enqueue(14);
    q.enqueue(99);
    q.displayStatus();
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
    q.displayStatus();
    return 0;
}
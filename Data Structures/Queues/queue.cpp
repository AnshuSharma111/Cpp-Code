#include <iostream>
using namespace std;

class Queue{
    int front, rear;
    int q[10];
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        bool isFull(){
            if (front == 0 && rear == 9) return true;
            return false;
        }
        bool isEmpty(){
            if (front == -1 && rear == -1) return true;
            return false;
        }
        void enqueue(int data){
            if ((rear + 1) % 10 == front)
                cout << "Queue Full!\n";
            else{
                if(front == -1) front = 0;
                rear = (rear+1)%10;
                q[rear] = data;
            }
        }
        void dequeue(){
            if(isEmpty())
                cout << "Empty Queue!\n";
            else if(front == rear){
                front = -1;
                rear = -1;
            }
            else
                front = (front + 1) % 10;
        }
        int Front(){
            if (isEmpty()){
                return -1;
            }
            else 
                return q[front];
        }
        void print(){
            if(isEmpty())
                cout << "Empty Queue!\n";
            else{
                if (front <= rear){
                    for(int i = front; i <= rear; i++)
                        cout << q[i] << " ";
                }
                else{
                    int i = front;
                    while (i < 10){
                        cout << q[i] << " ";
                        ++i;
                    }
                    i = 0;
                    while (i <= rear){
                        cout << q[i] << " ";
                        i++;
                    }
                }
            }
            cout << endl;
        }
};

int main(){
    Queue q;
    char ch;
    int ele;
    do{
        cout << "Welcome to the ultimate Queue program! What do you wish to perform?\n1) Enqueue\n2) Dequeue\n3) Front\n4) Display\n5) Exit\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            cout << "Enter element to enter: ";
            cin >> ele;
            q.enqueue(ele);
            break;
        case '2':
            q.dequeue();
            break;
        case '3':
            cout << "The front element is: " << q.Front() << endl;
            break;
        case '4':
            cout << "The queue is: ";
            q.print();
            break;
        case '5':
            break;
        default:
            cout << "Invalid Choice!\n";
            break;
        }
    }
    while (ch != '5');
    return 0;
}
#include <iostream>
using namespace std;

class Array
{
    private:
        int length = 0;
        int* array = new int[length];
    public:
        Array()
        {
            cout << "How many elements do you want in the array: ";
            cin >> length;
            array = (int*) realloc(array, length);
            for (int i = 0; i < length; i++)
                cin >> *(array + i);
            Print();
        }
        void insert(int pos, int data)
        {
            if (pos > length) {cout << "Invalid Position!\n"; return; }

            length += 1;
            array = (int*) realloc(array, length);

            if (pos == length+1){ *(array+length) = data; return;}
    
            for(int i = length - 1; i >= pos; i--)
                *(array+i+1) = *(array+i);
            *(array + pos) = data;
        }
        int size()
        {
            return length;
        }
        void Print()
        {
            for(int i =0; i <length; i++) { cout << *(array+i) << " "; }
            cout << endl;
        }
};

int main()
{
    Array arr;
    cout << endl << arr.size() << endl;
    arr.insert(5,45);
    arr.Print();
    return 0;
}
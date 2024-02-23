#include <iostream>
using namespace std;

class Array
{
    private:
        int length = 8;
        int occupied_length = 0;
        int* array = new int[length];

        void reallocate_array()
        {
            array = (int*) realloc(array, length*2);
            length = length * 2;
        }
    public:
        Array()
        {
            cout << "How many elements do you want in the array: ";
            cin >> occupied_length;
            
            if (occupied_length > length) // In case array is full, it needs to be reallocated
                reallocate_array();

            for (int i = 0; i < occupied_length; i++)
                cin >> *(array + i);
            Print();
        }
        ~Array() { delete array; }
        void insert(int pos, int data)
        {
            if (pos > occupied_length) {cout << "Invalid Position!\n"; return; }

            occupied_length += 1;
            if (occupied_length > length) { reallocate_array(); }
            if (pos == occupied_length){ *(array+occupied_length) = data; return;}
    
            for(int i = occupied_length-2; i >= pos-1; i--)
                *(array+i+1) = *(array+i);
            *(array + pos - 1) = data;
        }
        int size()
        {
            return occupied_length;
        }
        void Print()
        {
            for(int i =0; i <occupied_length; i++) { cout << *(array+i) << " "; }
            cout << endl;
        }
};

int main()
{
    Array arr;
    cout << endl << arr.size() << endl;
    arr.insert(7,45);
    arr.Print();
    arr.insert(3,35);
    arr.Print();
    arr.insert(4,86);
    arr.Print();
    cout << arr.size() << endl;
    return 0;
}
#include <vector>
#include <iostream>
using namespace std;

// Program to print every given combination of an array

void printCombinations(const vector<int> &arr, int bitmask){
    cout << "{ ";
    for (int i = 0; i < arr.size(); ++i){
        if ((bitmask & (1 << i)) != 0){
            cout << arr[i] << " ";
        }
    }
    cout << " }" << endl;
}

void generateCombinations(const vector<int> &arr){
    int n = arr.size();
    int combinations = 1 << n;

    for(int bitmask = 0; bitmask < combinations; ++bitmask){
        printCombinations(arr, bitmask);
    }
}

int main(){
    int n;
    cout << "How many elements are there in the array? Please enter: ";
    cin >> n;

    cout << "Enter elements of array: ";
    vector<int> arr(n);
    for(int i =0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Original array is: ";
    for(int i : arr){
        cout << i << " "; 
    }

    cout << endl << "All possible combinations are: ";
    generateCombinations(arr);
    return 0;
}
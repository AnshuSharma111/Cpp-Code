#include <iostream>
#include <vector>
using namespace std;

// Given 2 integers n and k, return all possible combinations in the interval [1,n] of size k

void generate_combs(vector<vector<int>>& res, vector<int> comb, int start, int n, int k){
    // Base case of the recursion
    if (comb.size() == k){
        res.push_back(comb);
        return;
    }

    for(int i = start; i <= n; i++){
        comb.push_back(i);
        generate_combs(res, comb, i+1, n, k);
        comb.pop_back();
    }
}

int main(){
    int n, k;
    cout << "Enter the upper bound of the interval: ";
    cin >> n;
    cout << "Enter the size of each combination: ";
    cin >> k;
    
    if (k > n){
        cout << "Impossible!";
        exit(0);
    }

    vector<vector<int>> res;
    vector<int> comb;
    int start = 1;
    cout << "The possible combinations are: ";
    generate_combs(res, comb, start, n, k);
    for (const auto& combination : res) {
        cout << "[ ";
        for (int i : combination) {
            cout << i << " ";
        }
        cout << "]\n";
    }
    return 0;
}
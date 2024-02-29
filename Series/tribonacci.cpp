#include <iostream>
#include <map>

// To find the n-th element of the tribonacci series

int trib(int n, std::map<int, int> &hashtable)
{
    //base cases
    std::map<int, int>::iterator it = hashtable.begin();
    while (it != hashtable.end())
    {
        if (it->first == n) { return it->second;}
        it++;
    }
    if (n == 0) { return 0; }
    if(n == 1) { return 1; }
    if(n == 2) { return 1; }

    // Non base case shenanigans
    int nVal = trib(n-1, hashtable) + trib(n-2, hashtable) + trib(n-3, hashtable);
    hashtable[n] = nVal;
    return nVal;
}

int main()
{
    int n;
    std::cout << "Number at what position in the tribonacci series do you want to print? Enter: ";
    std::cin >> n;

    if (n == 0) { std::cout<< 0; exit(0); }
    if (n == 1) { std::cout<< 1; exit(0); }
    if (n == 2) { std::cout<< 1; exit(0); }

    std::map<int,int> hashmap = {};
    std::cout << trib(n-1, hashmap);

    return 0;
}
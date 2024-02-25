#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Program to demonstrate depth first search in c++

void dfs(map<int, vector<int>> graph, int cur, vector<int> visited = {})
{
    for (int v : visited)
    {
        if (v == cur)
            return;
    }

    visited.push_back(cur);
    cout << "Visited Node " << cur << endl;

    for (int i : graph[cur])
    dfs(graph, i, visited);
}

int main()
{
    map<int, vector<int>> graph ={
        {0, {1,2}}, 
        {1, {5,3}},
        {2, {4, 1}},
        {3, {6}},
        {4, {9}},
        {5, {8}},
        {6, {7}},
        {7, {}},
        {8, {7}},
        {9, {6, 10}},
        {10, {}}
    };

    dfs(graph, 0);
    return 0;
}
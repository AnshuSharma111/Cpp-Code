#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

// Program to demonstrate breadth first search algorithm to find shortest path from a node to another node in a graph

vector<char> bfs(map<char, vector<char>>& graph, char start, char target)
{
    queue<vector<char, vector<char>>> queue = {{start, {start}}};
    vector<char> visited = {start}; // scuffed set

    while (!queue.empty())
    {
        map<char, vector<char>>::iterator it = queue.begin();
        char cur = it->first;
        vector<char> path = it->second;

        if (cur == target) { return path; }
        queue.erase(cur);

        for (char i : graph[cur])
        {
            bool hasVisited = false;
            for  (char j : visited)
            {
                if (i == j) { hasVisited = true; break;}
            }
            if (!hasVisited)
            {
                visited.push_back(i);
                queue
            }
        }
    }
}

int main()
{
    map<char, vector<char>> graph = {};
    char start = 'A', stop = 'H';

    return 0;
}
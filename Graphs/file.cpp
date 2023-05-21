#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int k, int v, bool direction)
    {
        // direction == 0 ---> un-directed graph
        // direction == 1 ---> directed graph

        // create a key,value pair first --->
        adjList[k].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(k);
        }
    }

    void printList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-->";
            cout << " { ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << "}\n";
        }
    }

    void BFS(int srcVertex, bool *isVisited)
    {
        queue<int> q;
        q.push(srcVertex);
        isVisited[srcVertex] = true;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            cout << temp << " ";
            for (auto neighbor : adjList[temp])
            {
                if (!isVisited[neighbor])
                {
                    q.push(neighbor);
                    isVisited[neighbor] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g;
    // taking no of vertices or nodes :
    int e;
    cout << "\nEnter number of edges : ";
    cin >> e;

    // creating an array of bool for visited check :
    const int E = 1e5 + 2;
    bool isVisited[E] = {false};

    // taking input of edges
    cout << "Enter all edges from k-->v || v-->k :" << endl;
    for (int i = 0; i < e; i++)
    {
        int k, v;
        cin >> k >> v;
        g.addEdge(k, v, 0);
    }
    g.printList();
    g.BFS(0, isVisited);

    return 0;
};
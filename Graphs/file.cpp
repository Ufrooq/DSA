#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
public:
    map<int, list<int>> adjList;
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

    void BFS(int srcVertex, bool *isVisited)
    {
        queue<int> q;
        q.push(srcVertex);
        isVisited[srcVertex] = true;
        cout << "BFS output is : ";
        while (!q.empty())
        {
            int temp = q.front();
            cout << temp << " ";
            q.pop();
            for (auto neighbours : adjList[temp])
            {
                if (!isVisited[neighbours])
                {
                    q.push(neighbours);
                    isVisited[neighbours] = true;
                }
            }
        }
    }
    void DFS(int srcVertex, bool *isVisited)
    {
        stack<int> st;
        st.push(srcVertex);
        isVisited[srcVertex] = true;
        cout << "DFS output is : ";
        while (!st.empty())
        {
            int temp = st.top();
            cout << temp << " ";
            st.pop();
            for (auto neighbours : adjList[temp])
            {
                if (!isVisited[neighbours])
                {
                    st.push(neighbours);
                    isVisited[neighbours] = true;
                }
            }
        }
    }

    void printList()
    {
        cout << "Adjency List is : " << endl;
        cout << "----------------------" << endl;
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
        cout << "------------------------" << endl;
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
    g.DFS(1, isVisited);

    return 0;
};
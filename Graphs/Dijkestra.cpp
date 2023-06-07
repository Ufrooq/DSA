#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <limits.h>

using namespace std;

class Graph
{
public:
    int no_of_vertex;
    Graph(int v)
    {
        this->no_of_vertex = v;
    }
    map<int, list<pair<int, int>>> adjMatrix;
    void addEdge(int k, int v, int w)
    {
        adjMatrix[k].push_back(make_pair(v, w));
        adjMatrix[v].push_back(make_pair(k, w));
    }

    void Prims(int source)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(no_of_vertex);
        vector<int> parent(no_of_vertex);
        vector<bool> visited(no_of_vertex);

        // initilization ---->
        for (int i = 0; i < no_of_vertex; i++)
        {
            dist[i] = INT_MAX;
            visited[i] = false;
            parent[i] = -1;
        }

        // source node input -->
        dist[source] = 0;
        parent[source] = -1;
        pq.push({0, source});

        while (!pq.empty())
        {

            // find min node -->
            int minNodeDistance = pq.top().first;
            int minNode = pq.top().second;
            pq.pop();

            // neighbours work -->
            visited[minNode] = true;
            for (auto nb : adjMatrix[minNode])
            {
                int val = nb.first;
                int wet = nb.second;

                if (!visited[val] && wet < dist[val])
                {
                    parent[val] = minNode;
                    dist[val] = wet;
                    pq.push({dist[val], val});
                }
            }
        }
        cout << "PRIMS output is : " << endl;
        for (int i = 1; i < no_of_vertex; i++)
        {
            if (parent[i] != -1)
            {
                cout << "Node: " << i << " -----> Parent: " << parent[i] << "  --> weit " << dist[i] << endl;
            }
            else
            {
                cout << "Node: " << i << " -----> Parent: No parent" << endl;
            }
        }
    }
    // 1 5 15
    // 1 2 21
    // 1 4 16
    // 2 1 12
    // 2 3 13
    // 2 4 18
    // 2 5 15
    // 3 2 13
    // 3 5 17
    // 4 1 16
    // 4 2 18
    // 4 5 19
    // 5 1 18
    // 5 2 15
    // 5 3 17
    // 5 4 19

    vector<int>
    Dijkastra(int source)
    {
        vector<int> dist(no_of_vertex);
        for (int i = 0; i < no_of_vertex; i++)
        {
            dist[i] = INT_MAX;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // ------> pair(weight , node);
        dist[source] = 0;
        pq.push(make_pair(0, source));

        while (!pq.empty())
        {
            int currentNodeDistance = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            for (auto neighbour : adjMatrix[currentNode])
            {
                if ((currentNodeDistance + neighbour.second) < dist[neighbour.first])
                {
                    // update distance :
                    dist[neighbour.first] = currentNodeDistance + neighbour.second;
                    // add record as a pair as make_pair(newUpdatedWeitage , newNode);
                    pq.push(make_pair((currentNodeDistance + neighbour.second), neighbour.first));
                }
            }
        }

        return dist;
    }

    // Djkestra input --->
    // 0 4 5
    // 0 2 10
    // 0 3 15
    // 1 2 2
    // 2 4 3
    // 3 1 8
    // 4 1 1
    // 4 2 4

    // Prims input -->
    //  0 1 3
    //  0 5 25
    //  0 2 18
    //  0 5 2
    //  1 2 3
    //  1 7 4
    //  2 6 2
    //  2 3 10
    //  2 7 7
    //  3 4 4
    //  3 7 8
    //  4 5 4
    //  4 7 9
    //  5 6 7
    //  6 7 10

    // 0 1 1
    // 1 4 2
    // 0 2 3
    // 2 3 4
    // 3 5 5
    // 5 7 6
    // 4 6 7

    void printadjMatrix()
    {
        cout << "<----- Adjency List is ----->" << endl;
        for (auto i : adjMatrix)
        {
            cout << i.first << "---> {";
            for (auto j : i.second)
            {
                cout << "( " << j.first << ", " << j.second << " )"
                     << ",";
            }
            cout << "}\n";
        }
    }
    void printDjkestra(vector<int> result)
    {
        cout << "{";
        for (int i = 0; i < result.size(); i++)
        {
            cout << "(" << i << "," << result[i] << ")";
        }
        cout << "}";
    }
};

int main()
{
    cout << "Enter number of edges : ";
    int e;
    cin >> e;
    cout << "Enter number of verteces : ";
    int ver;
    cin >> ver;
    Graph g(ver);

    // creation of connections --->
    cout << "Enter all edges from k-->v || v-->k :" << endl;
    for (int i = 0; i < e; i++)
    {
        int k, v, w;
        cin >> k >> v >> w;
        g.addEdge(k, v, w);
    }
    g.printadjMatrix();
    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    g.Prims(source);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }
    return 0;
};
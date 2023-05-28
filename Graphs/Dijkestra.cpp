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
    }

    vector<int> Dijkastra(int source)
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
            // fetch the top pair :
            int nodeDistance = pq.top().first;
            int topNode = pq.top().second;
            // remove top pair :
            pq.pop();

            // traverse neighbours :
            for (auto neighbour : adjMatrix[topNode])
            {
                if ((nodeDistance + neighbour.second) < dist[neighbour.first])
                {
                    // update distance :
                    dist[neighbour.first] = nodeDistance + neighbour.second;

                    // add record as a pair as make_pair(newUpdatedWeitage , newNode);
                    pq.push(make_pair((nodeDistance + neighbour.second), neighbour.first));
                }
            }
        }

        return dist;
    }

    // 0 4 5
    // 0 2 10
    // 0 3 15
    // 1 2 2
    // 2 4 3
    // 3 1 8
    // 4 1 1
    // 4 2 4
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
    vector<int> result = g.Dijkastra(source);
    g.printDjkestra(result);
    return 0;
};
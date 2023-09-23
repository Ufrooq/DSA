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
    map<string, list<pair<string, int>>> adjMatrix;
    map<string, int> distMatrix;

    void
    addEdge(string k, string v, int w)
    {
        adjMatrix[k].push_back(make_pair(v, w));
        distMatrix[k] = INT_MAX;
    }

    void
    Dijkastra(string source)
    {

        // vector<int> dist(no_of_vertex, INT_MAX);
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        // ------> pair(weight , node);
        distMatrix[source] = 0;
        pq.push(make_pair(0, source));

        while (!pq.empty())
        {
            int currentNodeDistance = pq.top().first;
            string currentNode = pq.top().second;
            pq.pop();

            for (auto neighbour : adjMatrix[currentNode])
            {
                if ((currentNodeDistance + neighbour.second) < distMatrix[neighbour.first])
                {
                    cout << currentNode << " ";
                    // update distance :
                    distMatrix[neighbour.first] = currentNodeDistance + neighbour.second;
                    // add record as a pair as make_pair(newUpdatedWeitage , newNode);
                    pq.push(make_pair((currentNodeDistance + neighbour.second), neighbour.first));
                }
            }
        }

        // return dist;
    }

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
    cout << "Enter all edges from k-->v || v-->k :" << endl;
    for (int i = 0; i < e; i++)
    {
        string k, n;
        int w;
        cin >> k >> n >> w;
        g.addEdge(k, n, w);
    }
    g.printadjMatrix();
    return 0;
};
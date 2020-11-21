#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<pair<int, double>> adj[], int u, int v, double cost)
{
    adj[u].push_back(make_pair(v, cost));
    adj[v].push_back(make_pair(u, cost));
}

void printGraph(vector<pair<int, double>> adj[], int size)
{
    int f, s;
    for (int v = 0; v < size; v++)
    {
        cout << "Node " << v << "->";
        for (auto it = adj[v].begin(); it != adj[v].end(); it++)
        {
            f = it->first;
            s = it->second;
            cout << "( " << f << ", " << s << " )"
                 << "->";
        }
        cout << endl;
    }
}

void dijkstra(vector<pair<int, double>> adj[], int src, int size)
{
    priority_queue<pair<int, double>, vector<pair<int, double>>, greater<pair<int, double>>> pq;
    vector<double> dist(size, INT64_MAX);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        vector<pair<int, double>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int wt = (*i).second;

            if (dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << "Vertex Distance from Source:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i << "       " << dist[i] << endl;
    }
}

int main()
{
    cout << "Enter the number of Edges: ";
    int n;
    cin >> n;
    cout << "Enter the numner of Vertices: ";
    int v;
    cin >> v;
    vector<pair<int, double>> *graph = new vector<pair<int, double>>[v];
    cout << "Enter src , dest and cost:" << endl;
    int src, dest;
    double cost;
    for (int i = 0; i < n; i++)
    {
        cin >> src >> dest >> cost;
        addEdge(graph, src, dest, cost);
    }
    cout << "Enter the source node: ";
    int srct;
    cin >> srct;
    dijkstra(graph, srct, v);
}
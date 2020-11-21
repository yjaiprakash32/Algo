#include <iostream>
#include <vector>
#include <stack>
#define INF 100000
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, double cost)
{
    adj[u].push_back(make_pair(v, cost));
}

void util(vector<pair<int, int>> adj[], int n, bool *visited, stack<int> &Stack)
{
    visited[n] = true;
    vector<pair<int, int>>::iterator it;
    for (it = adj[n].begin(); it != adj[n].end(); it++)
    {
        int v = (*it).first;
        int wt = (*it).second;
        if (!visited[v])
            util(adj, v, visited, Stack);
    }
    Stack.push(n);
}

void shortestPath(vector<pair<int, int>> adj[], int src, int n)
{
    stack<int> Stack;
    vector<int> dist(n, INF);

    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
            util(adj, i, visited, Stack);
    }

    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;

    while (Stack.empty() == false)
    {
        int u = Stack.top();
        Stack.pop();

        vector<pair<int, int>>::iterator it;
        if (dist[u] != INF)
        {
            for (it = adj[u].begin(); it != adj[u].end(); it++)
            {
                int v = (*it).first;
                int wt = (*it).second;
                if (dist[v] > dist[u] + wt)
                    dist[v] = dist[u] + wt;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            cout << "INF"
                 << " ";
        else
            cout << dist[i] << " ";
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
    vector<pair<int, int>> *graph = new vector<pair<int, int>>[v];
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
    cout << "Distance of vertices from the source node: " << endl;
    shortestPath(graph, srct, v);
}
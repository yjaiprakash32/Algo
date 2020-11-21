#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#define INF 100000
using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void reconstructPath(int end, int dist[], int prev[], int start)
{
    list<int> path;
    if (dist[end] == INF)
        return;

    for (int at = end; prev[at] != 0; at = prev[at])
    {
        if (prev[at] = -1)
            return;
        path.push_front(at);
    }
    path.push_front(start);

    for (auto it = path.begin(); it != path.end(); ++it)
        cout << " ->" << *it;
}

void BellmanFord(struct Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int prev[V - 1];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
            prev[j] = i;
        }
    }

    bool pathPossible = true;

    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v])
        {
            cout << "Graph has negetive cycle";
            pathPossible = false;
            prev[i] = -1;
        }
    }

    cout << "Vertex  Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << "          " << dist[i] << endl;

    list<int> path;
    for (int i = 0; i < V; i++)
        reconstructPath(i, dist, prev, src);

    return;
}

int main()
{

    cout << "Enter the number of Edges: ";
    int n;
    cin >> n;
    cout << "Enter the numner of Vertices: ";
    int v;
    cin >> v;
    struct Graph *graph = createGraph(v, n);
    cout << "Enter the src dest and cost:" << endl;
    int src, dest, cost;
    for (int i = 0; i < n; i++)
    {
        cin >> src >> dest >> cost;
        graph->edge[i].src = src;
        graph->edge[i].dest = dest;
        graph->edge[i].weight = cost;
    }
    cout << "Enter the start point: " << endl;
    int start;
    cin >> start;
    BellmanFord(graph, start);
    return 0;
}
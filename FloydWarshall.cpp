#include <iostream>

using namespace std;
#define INF 100000
void printSolution(int **dist, int V)
{
    cout << "The following matrix shows the shortest distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "	 ";
            else
                cout << dist[i][j] << "	 ";
        }
        cout << endl;
    }
}

void floydWarshall(double **graph, int V)
{
    int **dist = new int *[V];
    for (int i = 0; i < V; i++)
        dist[i] = new int[V];
    int i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist, V);
}

int main()
{
    cout << "Enter the number of vertices: ";
    int v;
    cin >> v;

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;
    double **graph = new double *[v];
    for (int i = 0; i < v; i++)
        graph[i] = new double[v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
    int src, dest;
    double cost;
    cout << "Enter the src , dest and cost" << endl;
    for (int i = 0; i < edges; i++)
    {
        cin >> src >> dest >> cost;
        graph[src][dest] = cost;
    }

    floydWarshall(graph, v);
    return 0;
}

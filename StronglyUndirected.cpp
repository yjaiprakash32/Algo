#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsU(vector<vector<int>> &adj, int x, vector<int> &visited)
{

    visited[x] = 1;
    cout << x << " ";

    for (int i = 0; i < adj[x].size(); i++)
    {
        if (!visited[adj[x][i]])
        {
            visited[adj[x][i]] = 1;
            dfsU(adj, adj[x][i], visited);
        }
    }
}

int number_of_strongly_connected_components(vector<vector<int>> adj, int V)
{
    int result = 0;

    vector<int> visited(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsU(adj, i, visited);
            cout << endl;
            result++;
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of Vertices and Edges: ";
    cin >> n >> m;
    cout << "Enter the src and dest" << endl;
    vector<vector<int>> adj(n, vector<int>());
    cout << "Enter the Src and dest: " << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << "Strongly Connected components are: " << endl;
    number_of_strongly_connected_components(adj, n);
}
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> reverseEdges(vector<vector<int>> &adj)
{
    vector<vector<int>> rAdj(adj.size(), vector<int>());
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            rAdj[adj[i][j]].push_back(i);
        }
    }
    return rAdj;
}

void dfs(vector<vector<int>> &adj, int x, vector<int> &visited, stack<int> &Stack)
{

    visited[x] = 1;

    for (int i = 0; i < adj[x].size(); i++)
    {
        if (!visited[adj[x][i]])
        {
            visited[adj[x][i]] = 1;
            dfs(adj, adj[x][i], visited, Stack);
        }
    }
    Stack.push(x);
}

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

int number_of_strongly_connected_components(vector<vector<int>> adj)
{
    int result = 0;
    stack<int> Stack;

    vector<int> visited(adj.size(), 0);

    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            dfs(adj, i, visited, Stack);
        }
    }
    vector<vector<int>> rAdj = reverseEdges(adj);

    for (int i = 0; i < adj.size(); i++)
    {
        visited[i] = 0;
    }

    while (!Stack.empty())
    {

        int x = Stack.top();
        Stack.pop();
        if (!visited[x])
        {
            stack<int> componentStack;

            dfsU(rAdj, x, visited);
            cout << endl;
            result++;
        }
    }
    return result;
}

int main()
{
    int n, m;
    cout << "Enter the number of Vertices and Edges: ";
    cin >> n >> m;
    cout << "Enter the src and dest" << endl;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    cout << "Strongly Connected components are: " << endl;
    number_of_strongly_connected_components(adj);
}
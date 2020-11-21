#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &used, vector<int> &order, int x)
{
    used[x] = 1;
    for (int i = 0; i < adj[x].size(); i++)
    {
        if (!used[adj[x][i]])
            dfs(adj, used, order, adj[x][i]);
    }
    order.insert(order.begin(), x);
}

vector<int> toposort(vector<vector<int>> adj)
{
    vector<int> used(adj.size(), 0);
    vector<int> order;
    for (int i = 0; i < adj.size(); i++)
    {
        if (!used[i])
        {
            dfs(adj, used, order, i);
        }
    }
    return order;
}

int main()
{
    int n, m;
    cout << "Enter the number of Vertices and Edges: ";
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    cout << "Enter the src and dest" << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<int> order = toposort(adj);
    cout << "TopSort: " << endl;
    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << " ";
    }
}
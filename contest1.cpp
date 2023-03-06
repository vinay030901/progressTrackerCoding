#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u, v, wt;
    node(int f, int s, int w)
    {
        u = f;
        v = s;
        wt = w;
    }
};
bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] > rank[v])
        parent[v] = u;
    else if (rank[v] > rank[u])
        parent[u] = v;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
long long solve(int n, int m, vector<int> arr, vector<vector<int>> e)
{
    set<pair<int, int>> st;
    for (int i = 0; i < m; i++)
    {
        st.insert({e[i][0], e[i][1]});
    }
    vector<node> edge;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (st.find({i, j}) != st.end())
                continue;
            edge.push_back({i, j, arr[i - 1] * arr[j - 1]});
        }
    }
    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    long long cost = 0;
    vector<pair<int, int>> mst;

    for (auto it : edge)
    {
        if (findPar(it.u, parent) != findPar(it.v, parent)) // if they don't have common component, then we join then
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (parent[i] == i)
            cnt++;
    if (cnt > 1)
        return -1;
    return cost;
}
void solveme()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    cout << solve(n, m, arr, edges) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solveme();
    }
}
#include <bits/stdc++.h>
using namespace std;
long long solve(int n, int m, vector<int> arr, vector<vector<int>> e)
{
    set<pair<int, int>> st;
    for (int i = 0; i < m; i++)
    {
        st.insert({e[i][0], e[i][1]});
    }
    vector<vector<int>> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (st.find({i, j}) != st.end())
                continue;
            adj[i].push_back({j, arr[i - 1] * arr[j - 1]});
            adj[j].push_back({i, arr[i - 1] * arr[j - 1]});
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(n + 1, 0);
    long long sum = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node])
            continue;
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjnode = it[0];
            int edw = it[1];
            if (!vis[adjnode])
                pq.push({edw, adjnode});
        }
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            return -1;
    return sum;
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
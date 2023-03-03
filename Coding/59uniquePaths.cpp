#include <bits/stdc++.h>
using namespace std;
int recur(int m, int n, vector<vector<int>> &dp)
{
    if (!m && !n)
        return 1;
    if (m < 0 || n < 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    return dp[m][n] = recur(m - 1, n, dp) + recur(m, n - 1, dp);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return recur(m - 1, n - 1, dp);
}
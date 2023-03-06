#include <bits/stdc++.h>
using namespace std;
int solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    if (a[0] > 0)
        return -1;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0)
            continue;
        if (a[i - 1] + 1 == a[i])
        {
            ans += 1;
            a[i] = a[i - 1] + 1;
        }
        else if (a[i] == 1)
            ans++, b[i]++;
        else
            return -1;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve();
    }
}
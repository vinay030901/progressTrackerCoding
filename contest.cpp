#include <bits/stdc++.h>
using namespace std;
void fun()
{
    int n, f = 0;
    cin >> n;
    string str;
    cin >> str;
    string compare = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";
    if (compare.find(str) != string::npos)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        fun();
    }
}
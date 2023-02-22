#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // https://leetcode.com/problems/longest-palindromic-substring/solutions/844586/very-easy-to-understand-well-commented-2-approaches-thinking-process/?orderBy=most_votes
    string longestPalindrome(string s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, len = 1;
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i == 1 || dp[i + 1][j - 1] == true)
                    {
                        dp[i][j] = true;
                        if (j - i + 1 > len)
                        {
                            start = i;
                            len = j - i + 1;
                        }
                    }
                }
            }
        return s.substr(start, len);
    }
};
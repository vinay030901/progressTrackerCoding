#include <bits/stdc++.h>
using namespace std;
char nextGreatestLetter(vector<char> &arr, char target)
{
    int l = 0, h = arr.size() - 1;
    char ans = arr[0];
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] - 'a' > target - 'a')
        {
            h = mid - 1;
            ans = arr[mid];
        }
        else
            l = mid + 1;
    }
    return ans;
}
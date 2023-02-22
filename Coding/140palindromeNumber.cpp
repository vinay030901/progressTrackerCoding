#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    long long num = 0, y = x;
    while (y)
    {
        num = num * 10 + (y % 10);
        y /= 10;
    }
    return x == num;
}

// in this approach we are only checking till the middle value, so need to check for overflow or convertsion to long long
bool isPalindrome(int x)
{
    if (x < 0 || (x != 0 && x % 10 == 0))
        return false;
    int num = 0;
    while (x > num)
    {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return x == num || (x == num / 10);
}
int main()
{
}
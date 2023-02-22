#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &arr, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!dq.empty() && arr[i] > arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        if (dq.front() == i - k)
            dq.pop_front();
        if (i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }
    return ans;
}
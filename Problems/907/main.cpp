#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;

using LL = long long;

class Solution
{
    LL mod = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nextSmaller(n, n);
        vector<int> prevSmaller(n, -1);

        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            // > to deal w/ duplicate subarray calculation
            // 不然其實應該要是 >= 的。（相等的已經在 left -> right scan 中處理）
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        LL ret = 0;
        for (int i = 0; i < n; i++)
        {
            LL tmp = arr[i] * (i - prevSmaller[i]) % mod * (nextSmaller[i] - i) % mod;
            ret = (ret + tmp) % mod;
        }
        return ret;
    }
};

// brute force: O(n^3)
// [X X (X X i)] -> 快一點的 O(n^2), select end, may work

// greedy three pass solution

// maintain a strictly increasing sequence w/ stack

// 6 5 3 4 5 3 2 1

// [3 1] 2 4

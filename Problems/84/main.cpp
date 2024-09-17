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
#include <sstream>
#include <set>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &H)
    {
        int n = H.size();
        vector ns(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && H[st.top()] >= H[i])
                st.pop();
            if (!st.empty())
                ns[i] = st.top();
            st.push(i);
        }

        vector ps(n, -1);
        while (!st.empty())
            st.pop();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && H[st.top()] >= H[i])
                st.pop();
            if (!st.empty())
                ps[i] = st.top();
            st.push(i);
        }

        int res = INT_MIN;
        for (int i = 0; i < n; i++)
            res = max(res, H[i] * (ns[i] - ps[i] - 1));

        return res;
    }
};

// continous segments compress w/ min
//
// too many combination QQ ( 一開始真的會被這個 combination 給迷惑到 ww )
// w/ greedy .. ?
//
// solution space will be completed if we check each rectangle
// w/ next smaller, prev smaller
//
// Three pass scan w/ stack build => O(n)

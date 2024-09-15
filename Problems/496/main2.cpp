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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        stack<int> st;
        unordered_map<int, int> MAP;

        for (int j = m - 1; j >= 0; j--)
        {
            while (!st.empty() && nums2[j] >= st.top())
                st.pop();
            if (!st.empty())
                MAP[nums2[j]] = st.top();
            st.push(nums2[j]);
        }

        vector<int> res(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (MAP.find(nums1[i]) != MAP.end())
                res[i] = MAP[nums1[i]];
        }
        return res;
    }
};

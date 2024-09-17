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
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int N = nums.size();
        for (int i = 0; i < N; i++)
            nums.push_back(nums[i]);

        stack<int> st;
        vector<int> res(N, -1);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if (!st.empty())
                res[i % N] = nums[st.top()];
            st.push(i);
        }
        return res;
    }
};

// 可以直接把元素塞進去 ww

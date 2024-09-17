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
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int n = T.size();
        stack<int> st;

        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && T[st.top()] <= T[i])
                st.pop();
            if (!st.empty())
                res[i] = st.top() - i;
            st.push(i);
        }

        return res;
    }
};

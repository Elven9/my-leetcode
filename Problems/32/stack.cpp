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
    int longestValidParentheses(string s)
    {
        int n = s.size();
        stack<int> st;
        s = ")" + s;
        st.push(0);

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int top = st.top();
            if (s[i] == ')' && s[st.top()] == '(')
            {
                st.pop();
                res = max(res, i - st.top());
            }
            else
                st.push(i);
        }

        return res;
    }
};

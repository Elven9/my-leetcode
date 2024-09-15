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
    int scoreOfParentheses(string s)
    {
        stack<int> st;

        int cur = 0; // 這個 cur 其實省掉了一個 stack w
        for (auto &c : s)
        {
            if (c == ')')
            {
                if (cur == 0)
                    cur = 1;
                else
                    cur *= 2;
                cur += st.top();
                st.pop();
            }
            else
            {
                st.push(cur);
                cur = 0;
            }
        }
        return cur;
    }
};

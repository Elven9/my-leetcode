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
    int minAddToMakeValid(string s)
    {
        stack<char> st;

        for (auto &c : s)
        {
            if (c == ')' && !st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(c);
        }

        return st.size();
    }
};

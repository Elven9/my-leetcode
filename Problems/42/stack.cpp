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

class Solution
{
public:
    int trap(vector<int> &H)
    {
        stack<int> st;

        int ret = 0;
        for (int i = 0; i < H.size(); i++)
        {
            while (!st.empty() && H[st.top()] < H[i])
            {
                int top = st.top();
                st.pop();

                if (!st.empty())
                    ret += (min(H[st.top()], H[i]) - H[top]) * (i - st.top() - 1);
            }
            st.push(i);
        }
        return ret;
    }
};

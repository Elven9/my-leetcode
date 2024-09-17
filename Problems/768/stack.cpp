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
    int maxChunksToSorted(vector<int> &arr)
    {
        stack<int> st;

        // save max of each chunks
        for (auto &n : arr)
        {
            if (st.empty() || n >= st.top())
            {
                st.push(n);
                continue;
            }
            int top = st.top();
            st.pop();
            while (!st.empty() && n < st.top())
                st.pop();
            st.push(top);
        }

        return st.size();
    }
};

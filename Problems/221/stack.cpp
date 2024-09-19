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
    int maximalSquare(vector<vector<char>> &M)
    {
        int m = M.size(), n = M[0].size();
        vector<int> H(n, 0);
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                H[j] = M[i][j] == '1' ? H[j] + 1 : 0;

            res = max(res, maxHistogram(H));
        }

        return res;
    }

    int maxHistogram(vector<int> &H)
    {
        int n = H.size();
        H.push_back(-1);
        stack<int> st;
        st.push(-1);

        int res = 0;
        for (int i = 0; i <= n; i++)
        {
            while (st.size() > 1 && H[st.top()] > H[i])
            {
                int top = st.top();
                st.pop();
                // lc 85 照搬，差別在於 rectangle 裡面的最大 square
                int wid = min(H[top], (i - st.top() - 1));
                res = max(res, wid * wid);
            }
            st.push(i);
        }

        return res;
    }
};

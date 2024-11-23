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
#include <cctype>

using namespace std;

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), m = queries.size();

        vector<int> st(m, 0);
        vector<int> ed(m, 0);

        for (int i = 0; i < m; i++)
        {
            st[i] = queries[i][0];
            ed[i] = queries[i][1];
        }

        sort(st.begin(), st.end());
        sort(ed.begin(), ed.end());

        int cnt = 0;
        int l = 0, r = 0;

        for (int i = 0; i < n; i++)
        {
            while (r < m && st[r] <= i)
            {
                cnt++;
                r++;
            }

            while (l < m && ed[l] < i)
            {
                cnt--;
                l++;
            }

            if (cnt < nums[i])
                return false;
        }

        return true;
    }
};

//

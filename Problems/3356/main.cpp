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

using E = pair<int, int>;

class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), m = queries.size();

        int cnt = 0;
        int k = 0;

        // {end, val}
        priority_queue<E, vector<E>, greater<>> in;
        priority_queue<E, vector<E>, greater<>> out;

        for (int i = 0; i < n; i++)
        {
            while (!out.empty() && out.top().first < i)
            {
                cnt = max(0, cnt - out.top().second);
                out.pop();
            }

            while (!in.empty() && in.top().first <= i)
            {
                cnt += in.top().second;
                in.pop();
            }

            while (cnt < nums[i] && k < m)
            {
                vector<int> &q = queries[k++];
                if (q[1] < i)
                    continue;

                if (q[0] <= i)
                    cnt += q[2];
                else
                    in.push({q[0], q[2]});
                out.push({q[1], q[2]});
            }

            if (cnt < nums[i])
                return -1;
        }

        return k;
    }
};

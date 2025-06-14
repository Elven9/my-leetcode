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
        sort(queries.begin(), queries.end());

        priority_queue<int, vector<int>, greater<>> pq;

        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (!pq.empty() && pq.top() < i)
                pq.pop();

            while (j < m && queries[j][0] <= i)
            {
                pq.push(queries[j][1]);
                j++;
            }

            if (pq.size() < nums[i])
                return false;
        }
        return true;
    }
};

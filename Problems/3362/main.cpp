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
    int maxRemoval(vector<int> &nums, vector<vector<int>> &Q)
    {
        int n = nums.size(), m = Q.size();
        sort(Q.begin(), Q.end()); // by start
        priority_queue<int, vector<int>, greater<>> inUsed;
        priority_queue<int, vector<int>> canUsed;

        int idx = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            while (idx < m && Q[idx][0] <= i)
                canUsed.push(Q[idx++][1]);
            while (!inUsed.empty() && inUsed.top() < i)
                inUsed.pop();

            while (!canUsed.empty() && canUsed.top() >= i && inUsed.size() < nums[i])
            {
                inUsed.push(canUsed.top());
                canUsed.pop();
                cnt++;
            }

            if (inUsed.size() < nums[i])
                return -1;
        }

        return Q.size() - cnt;
    }
};

// greedy sort
//
// sort by length + update .. ? => O(n^2) won't works
//

// 是要挑「可用、最遠」的 segments 這樣可以 cover 最多後續的 interval
// -> greedy 思考方式！

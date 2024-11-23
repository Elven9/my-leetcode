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
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<pair<long, int>> dq;

        // 多考慮到 i, j 靠近的需求
        dq.push_back({0, -1});
        long sum = 0;
        int res = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            // 比 i 遠，即使後續有個更大的 prefix sum，結果也不會在選用這些更遠的結果了
            while (!dq.empty() && dq.back().first >= sum)
                dq.pop_back();

            // 考量過一次結果，就不可能成為後續的 possible solution 了
            while (!dq.empty() && sum - dq.front().first >= k)
            {
                res = min(res, i - dq.front().second);
                dq.pop_front();
            }

            dq.push_back({sum, i});
        }

        return res == INT_MAX ? -1 : res;
    }
};

// sum - prev >= k => prev <= sum -k

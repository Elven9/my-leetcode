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
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());

        int res = 0;
        while (pq.size() >= 2 && pq.top() < k)
        {
            long a = pq.top(); // min
            pq.pop();
            long b = pq.top(); // max
            pq.pop();
            pq.push(a * 2 + b);
            res++;
        }

        return res;
    }
};

// greedy
// smallest one must be process, but with smallest max to ensure last part of the equation (max(x, y)) won't waste it's potential

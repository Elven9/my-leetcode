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
    int minKBitFlips(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = 0;
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            while (!q.empty() && q.front() < i)
                q.pop();
            if (nums[i] ^ (q.size() % 2))
                continue;

            if (n - i < k)
                return -1;
            q.push(i + k - 1);
            res++;
        }

        return res;
    }
};

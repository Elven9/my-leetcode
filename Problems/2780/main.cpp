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
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();

        // Majority Voting Algorithm
        // Boyer-Moore Majority Vote Algorithm
        int freq = 0, cand = -1;
        for (auto &n : nums)
        {
            if (freq == 0)
            {
                cand = n;
                freq++;
            }
            else
                freq += n == cand ? 1 : -1;
        }

        freq = 0;
        for (auto &n : nums)
            freq += n == cand;

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += nums[i] == cand;

            if (cnt > (i + 1) / 2 && freq - cnt > (n - i - 1) / 2)
                return i;
        }

        return -1;
    }
};

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
        int dominant = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
            if (freq[nums[i]] >= (i + 2) / 2)
                dominant = nums[i];
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += nums[i] == dominant;

            if (cnt > (i + 1) / 2 && freq[dominant] - cnt > (n - i - 1) / 2)
                return i;
        }

        return -1;
    }
};

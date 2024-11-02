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
    vector<string> summaryRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<string> res;
        int i = 0;

        while (i < n)
        {
            int j = i + 1;
            while (j < n && long(nums[j]) == long(nums[i]) + j - i)
                j++;
            if (i + 1 == j)
                res.push_back(to_string(nums[i]));
            else
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));

            i = j;
        }

        return res;
    }
};

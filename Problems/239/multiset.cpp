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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        multiset<int> SET;

        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            SET.insert(nums[i]);
            if (SET.size() == k)
            {
                res.push_back(*SET.rbegin());
                SET.erase(SET.find(nums[i - k + 1]));
            }
        }
        return res;
    }
};

// O(nlogk)

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

using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> res;

        for (int i = 1; i <= n; i++)
            while (nums[i] != i && nums[i] != 0)
            {
                if (nums[i] == nums[nums[i]])
                {
                    res.push_back(nums[i]);
                    nums[i] = 0;
                    break;
                }
                swap(nums[i], nums[nums[i]]);
            }

        return res;
    }
};

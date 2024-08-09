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
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), -1);

        for (int i = 1; i <= n; i++)
            while (nums[i] != -1 && nums[i] != i)
            {
                if (nums[i] == nums[nums[i]])
                {
                    nums[i] = -1;
                    break;
                }
                swap(nums[i], nums[nums[i]]);
            }

        vector<int> res;
        for (int i = 1; i <= n; i++)
            if (nums[i] == -1)
                res.push_back(i);
        return res;
    }
};

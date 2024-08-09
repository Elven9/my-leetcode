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
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        for (int i = 1; i <= n; i++)
            while (nums[i] != i)
            {
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                swap(nums[i], nums[nums[i]]);
            }

        return 0;
    }
};

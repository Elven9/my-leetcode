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
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), -1);

        for (int i = 1; i <= n; i++)
            while (nums[i] != i && nums[i] != -1)
                swap(nums[i], nums[nums[i]]);

        for (int i = 0; i <= n; i++)
            if (nums[i] == -1)
                return i;
        return -1;
    }
};

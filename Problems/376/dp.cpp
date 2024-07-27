#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] - nums[i - 1] > 0)
                up = down + 1;
            else if (nums[i] - nums[i - 1] < 0)
                down = up + 1;

        return max(up, down);
    }
};

// previous up or down

// state
// not select
// select -> down
//        -> up

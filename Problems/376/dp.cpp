#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int p = 1, q = 1; // p last negative, q last positive
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] > 0)
            {
                // positive
                q = p + 1;
            }
            else if (nums[i] - nums[i - 1] < 0)
            {
                // negative
                p = q + 1;
            }
        }
        return max(q, p);
    }
};

// state
// not select
// select -> down
//        -> up

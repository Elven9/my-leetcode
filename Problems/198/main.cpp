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
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int rob = nums[0], not_rob = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            int t_rob = rob;
            rob = not_rob + nums[i];
            not_rob = max(t_rob, not_rob);
        }
        return max(rob, not_rob);
    }
};

// choose 4 => not choose 3
// not choose 4 => choose 3
//              => not choose 3

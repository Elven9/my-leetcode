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
    string triangleType(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2])
            return "none";

        int cnt = 1;
        for (int i = 1; i < 3; i++)
            if (nums[i] != nums[i - 1])
                cnt++;

        if (cnt == 3)
            return "scalene";
        else if (cnt == 2)
            return "isosceles";
        return "equilateral";
    }
};

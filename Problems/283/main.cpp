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
    void moveZeroes(vector<int> &nums)
    {
        int l = 0;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                swap(nums[l++], nums[i]);
    }
};

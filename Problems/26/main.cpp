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
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int k = 0;

        for (int i = 1; i < n; i++)
            if (nums[i] != nums[k])
                swap(nums[i], nums[++k]);

        return k + 1;
    }
};

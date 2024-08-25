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
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l < r)
        {
            bool toBreak = true;
            for (int mid = l; mid <= r; mid++)
            {
                if (nums[mid] == 0)
                {
                    swap(nums[l++], nums[mid]);
                    toBreak = false;
                }
                else if (nums[mid] == 2)
                {
                    swap(nums[r--], nums[mid]);
                    toBreak = false;
                }
            }
            if (toBreak)
                break;
        }
    }
};

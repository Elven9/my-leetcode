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
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int l = -1, r = n;

        for (int i = 0; i < n; i++)
            if (nums[i] == 0)
                nums[++l] = 0;
            else if (nums[i] == 2)
                r--;

        l++;
        while (l < n)
            nums[l++] = l < r ? 1 : 2;
    }
};

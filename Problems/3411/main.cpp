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
    int maxLength(vector<int> &nums)
    {
        int n = nums.size();
        // Optimized to Two Pointers
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int gcd = nums[i], lcm = nums[i];
            int prod = nums[i];

            while (j < n && GCD(gcd, nums[j]) * LCM(lcm, nums[j]) == prod * nums[j])
            {
                gcd = GCD(gcd, nums[j]);
                lcm = LCM(lcm, nums[j]);
                prod *= nums[j];
                j++;
            }
            res = max(res, j - i);
        }
        return res;
    }

    int GCD(int num1, int num2)
    {
        if (num2 == 0)
        {
            return num1;
        }

        return GCD(num2, num1 % num2);
    }

    int LCM(int num1, int num2)
    {
        return ((num1 * num2) / GCD(num1, num2));
    }
};

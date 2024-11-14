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

struct Cnt
{
    int cnt[32];
    int val;

    void add(int v)
    {
        int tmp = 0;
        while (v > 0)
        {
            if (v & 1)
            {
                cnt[tmp] += 1;
                if (cnt[tmp] == 1)
                    val += (1 << tmp);
            }
            v >>= 1;
            tmp++;
        }
    }

    void subtract(int v)
    {
        int tmp = 0;
        while (v > 0)
        {
            if (v & 1)
            {
                cnt[tmp] -= 1;
                if (cnt[tmp] == 0)
                    val -= (1 << tmp);
            }
            v >>= 1;
            tmp++;
        }
    }

    int get_val()
    {
        return val;
    }
};

class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        // Since it's OR, it can be solved effectively using two pointers

        int n = nums.size();
        int l = 0, r = -1;
        Cnt *cnt = new Cnt();

        int res = INT_MAX;
        while (r < n)
        {
            if (r < l || cnt->get_val() < k)
            {
                r++;
                if (r < n)
                    cnt->add(nums[r]);
            }
            else if (cnt->get_val() >= k)
            {
                res = min(res, r - l + 1);
                cnt->subtract(nums[l++]);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};

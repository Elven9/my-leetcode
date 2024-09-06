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
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = 1e6;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (check(nums, k, mid))
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    bool check(vector<int> &nums, int k, int diff)
    {
        // 這裡不用 two pointers 的原因是因為，不管怎樣 l 都要一個一個找
        // 且 r 都要 reset，這樣會變成 O(n^2)，還不如 nlogn

        int cnt = 0;
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            auto pos = upper_bound(it, nums.end(), *it + diff);
            cnt += int(pos - it) - 1;
        }
        return cnt < k;
    }
};

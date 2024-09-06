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
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size(), n = nums2.size();
        long l = INT_MIN, r = INT_MAX;

        while (l < r)
        {
            long mid = l + (r - l) / 2;

            if (check(nums1, nums2, k, mid))
                l = mid + 1;
            else
                r = mid;
        }

        vector<vector<int>> res, eq;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (res.size() > k)
                    break;
                int sum = nums1[i] + nums2[j];
                if (sum < l)
                {
                    res.push_back({nums1[i], nums2[j]});
                }
                else if (sum == l && res.size() + eq.size() < k)
                {
                    eq.push_back({nums1[i], nums2[j]});
                }
                else
                    break;
            }

        k = k - res.size();
        for (auto &p : eq)
        {
            if (k-- <= 0)
                break;
            res.push_back(p);
        }
        return res;
    }

    bool check(vector<int> &nums1, vector<int> &nums2, int k, long sum)
    {
        int m = nums1.size(), n = nums2.size();
        long j = n - 1, cnt = 0;

        for (int i = 0; i < m; i++)
        {
            while (j >= 0 && nums1[i] + nums2[j] > sum)
                j--;
            if (j < 0)
                break;
            cnt += j + 1;
        }
        return cnt < k;
    }
};

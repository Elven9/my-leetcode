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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 == 1)
        {
            return findKthSmallest(nums1, nums2, (m + n) / 2 + 1);
        }
        else
        {
            return (findKthSmallest(nums1, nums2, (m + n) / 2) + findKthSmallest(nums1, nums2, (m + n) / 2 + 1)) / 2;
        }
    }

    double findKthSmallest(vector<int> &nums1, vector<int> &nums2, int K)
    {
        int l = INT_MIN / 2, r = INT_MAX / 2;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (ok(nums1, nums2, K, mid))
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    bool ok(vector<int> &a, vector<int> &b, int &K, int &T)
    {
        int cnt1 = upper_bound(a.begin(), a.end(), T) - a.begin();
        int cnt2 = upper_bound(b.begin(), b.end(), T) - b.begin();

        return cnt1 + cnt2 < K;
    }
};

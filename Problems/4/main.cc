#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Naive solution: Merge sort two array, find the mean
        // O(m+n), O(m+n)
        //
        // Specific design of binary search: O(log (m+n)), O(1)
        int m = nums1.size(), n = nums2.size();
        // Must
        if (n < m)
            return findMedianSortedArrays(nums2, nums1);

        // Binary search on nums1
        // Trick 1: Insert imagined cut point
        int start = 0, end = 2 * m;
        while (start <= end)
        {
            int c1 = (start + end) / 2;
            int c2 = m + n - c1;

            // Trick 2: INT_MIN, INT_MAX for clean implementation
            int L1 = c1 == 0 ? INT_MIN : nums1[(c1 - 1) / 2];
            int L2 = c2 == 0 ? INT_MIN : nums2[(c2 - 1) / 2];
            int R1 = c1 == m * 2 ? INT_MAX : nums1[c1 / 2];
            int R2 = c2 == n * 2 ? INT_MAX : nums2[c2 / 2];

            if (L1 > R2)
                end = c1 - 1;
            else if (L2 > R1)
                start = c1 + 1;
            else
                return double(max(L1, L2) + min(R1, R2)) / 2.0;
        }
        return -1.0;
    }
};

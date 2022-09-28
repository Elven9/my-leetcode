#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // Naive solution: heap sort O(nlogn)
        // Using Quick Select: O(n), O(1)
        int lo = 0, hi = nums.size();
        k--;
        while (lo < hi)
        {
            int i = partition(nums, lo, hi);
            if (i < k)
            {
                lo = i + 1;
            }
            else if (i > k)
            {
                hi = i;
            }
            else
            {
                break;
            }
        }
        return nums[k];
    }

    int partition(vector<int> &nums, int lo, int hi)
    {
        // Set last element as pivot
        int pivot = nums[hi - 1], i = lo;
        while (lo < hi - 1)
        {
            if (nums[lo] >= pivot)
                swap(nums[i++], nums[lo]);
            lo++;
        }
        swap(nums[i], nums[hi - 1]);
        return i;
    }
};

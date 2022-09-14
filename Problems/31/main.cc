#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // Finding Turning Point
        int tp = nums.size() - 1;
        while (tp > 0 && nums[tp - 1] >= nums[tp])
            tp--;

        // Search first element that is greater than nums[tp-1]
        if (tp > 0)
        {
            for (int i = nums.size() - 1; i >= tp; i--)
            {
                if (nums[i] > nums[tp - 1])
                {
                    int tmp = nums[tp - 1];
                    nums[tp - 1] = nums[i];
                    nums[i] = tmp;
                    break;
                }
            }
        }

        // Reverse whole list after tp-1
        int tmp = 0;
        int ni = nums.size() - 1;
        while (ni > tp)
        {
            tmp = nums[ni];
            nums[ni--] = nums[tp];
            nums[tp++] = tmp;
        }
    }
};

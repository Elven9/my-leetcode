#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // Naive Solution: O(n^2), Scan and Swap
        // Linear scan solution: O(n), O(1)
        int sid = 0, nswap = 0;
        while (sid < nums.size())
        {
            if (nums[sid] == 0)
                sid++;
            else
                nums[nswap++] = nums[sid++];
        }

        // Zero out
        while (nswap < nums.size())
        {
            nums[nswap++] = 0;
        }
    }
};

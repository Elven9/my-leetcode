#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int p = 0;
        for (auto &n : nums)
            if (n != 0)
                nums[p++] = n;
        while (p < nums.size())
            nums[p++] = 0;
    }
};

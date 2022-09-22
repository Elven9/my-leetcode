#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool canJump_Stemina(vector<int> &nums)
    {
        int stemina = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            stemina--;
            if (stemina == -1)
                return false;
            if (nums[i] > stemina)
                stemina = nums[i];
        }

        return true;
    }

    bool canJump(vector<int> &nums)
    {
        // O(n^2) DP solution
        bool canJump[nums.size()];

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (i + nums[i] >= nums.size() - 1)
                canJump[i] = true;
            else
            {
                canJump[i] = false;
                for (int j = 1; j <= nums[i]; j++)
                {
                    if (canJump[i + j] == true)
                    {
                        canJump[i] = true;
                        break;
                    }
                }
            }
        }

        return canJump[0];
    }
};

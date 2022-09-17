#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        generate(res, tmp, nums, 0);
        return res;
    }

    void generate(vector<vector<int>> &res, vector<int> &tmp, vector<int> &nums, int start)
    {
        res.push_back(tmp);
        for (int i = start; i < nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            generate(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};

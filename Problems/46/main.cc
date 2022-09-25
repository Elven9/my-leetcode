#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        // O(n!), O(n)
        // Design of htable can substitute of map stl for general usege.

        bool htable[21] = {false};
        vector<vector<int>> res;
        vector<int> comb;

        backtrack(res, nums, comb, htable);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &nums, vector<int> &comb, bool *htable)
    {
        if (comb.size() == nums.size())
        {
            res.push_back(comb);
            return;
        }

        for (int n : nums)
        {
            if (!htable[n + 10])
            {
                htable[n + 10] = true;
                comb.push_back(n);
                backtrack(res, nums, comb, htable);
                comb.pop_back();
                htable[n + 10] = false;
            }
        }
    }
};

#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // https://www.cs.utexas.edu/~moore/best-ideas/mjrty
        int major = 0, cand = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cand == 0)
            {
                major = nums[i];
                cand = 1;
            }
            else if (major == nums[i])
            {
                cand++;
            }
            else
            {
                cand--;
            }
        }
        return major;
    }

    int majorityElement_withMap(vector<int> &nums)
    {
        // Naive solution: Sort and Scan -> O(nlogn), O(1)
        // With hashmap: O(n), O(n)
        map<int, int> valCount;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = valCount.find(nums[i]);
            if (it != valCount.end())
            {
                valCount[nums[i]] += 1;
            }
            else
            {
                valCount[nums[i]] = 1;
            }
        }

        // Check Result
        int res, tmp = 0;
        for (auto it = valCount.begin(); it != valCount.end(); it++)
        {
            if (it->second > tmp)
            {
                res = it->first;
                tmp = it->second;
            }
        }

        return res;
    }
};

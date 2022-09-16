#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Naive solution: flag position in space records, O(n^2), O(range)
        // Maybe we can sort interval and scan them
        // -> O(nlogn), O(1)

        // Use custom comparator if it's a MUST.

        // Sort
        sort(intervals.begin(), intervals.end());

        // Scan and Merge
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> &tmp = res.back();

            if (intervals[i][0] > tmp[1])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                tmp[1] = max(tmp[1], intervals[i][1]);
            }
        }

        return res;
    }
};

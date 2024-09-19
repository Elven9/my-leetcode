#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <functional>
#include <sstream>
#include <set>

using namespace std;

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> q;
        vector<int> idx; // => 這個就可以解決 index 問題 ..

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (q.size() == 0 || nums[i] < q.back())
            {
                q.push_back(nums[i]);
                idx.push_back(i);
            }
            else
            {
                auto it = upper_bound(q.rbegin(), q.rend(), nums[i]);
                int j = q.size() - int(it - q.rbegin());
                res = max(res, i - idx[j]);
            }
        }

        return res;
    }
};

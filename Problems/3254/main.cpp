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
#include <cctype>

using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0;

        vector<int> res;
        while (r < n)
        {
            if (r < k - 1)
                r++;
            else
            {
                res.push_back(r - l + 1 >= k ? nums[r] : -1);
                r++;
                if (r >= n)
                    break;
            }
            if (nums[r] < nums[r - 1] || nums[r] != nums[r - 1] + 1)
                l = r;
        }

        return res;
    }
};

// O(n) sliding windows ( two pointers, to maintain whole increasing sequence )
// naive O(n^2) will work too

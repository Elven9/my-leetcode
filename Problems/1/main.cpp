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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<pair<int, int>> N(n);
        for (int i = 0; i < n; i++)
            N[i] = {nums[i], i};

        sort(N.begin(), N.end());
        int l = 0, r = n - 1;
        while (l < r)
        {
            int v = N[l].first + N[r].first;
            if (v == target)
                break;
            else if (v > target)
                r--;
            else
                l++;
        }
        return {N[l].second, N[r].second};
    }
};

// sort
// two pointer scan
//
// if smaller -> l++
// if bigger -> r--

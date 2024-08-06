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

using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();

        int MAX = INT_MIN, right = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < MAX)
                right = i;
            MAX = max(MAX, nums[i]);
        }

        int MIN = INT_MAX, left = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > MIN)
                left = i;
            MIN = min(MIN, nums[i]);
        }

        cout << left << " " << right << endl;
        return left > right ? 0 : right - left + 1;
    }
};

// X X j X i X m X n X

// if i < j => j needs to be swapped

// if n is smaller than at least one element before it (said m) => n needs to be swapped

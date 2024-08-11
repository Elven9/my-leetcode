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
    void wiggleSort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int center = (n - 1) / 2;
        vector<int> cp = nums;

        for (int i = 0; i < n; i++)
            nums[i] = i % 2 == 0 ? cp[center - i / 2] : cp[n - i / 2 - 1];
    }
};

// 居然是反過來 ww

// 1 1 1 4 5 6

// 1 1 1 1 2 2

// 1 6 1 5 1 4

// 5 6 4 5

// Naive solution
// sort and re construct by high low

// 1 1 2 2 3 3
// 1 3 2 2
// X [X] X (X) (Y) Y [Y] Y

// 1 2 1 3 2 3

// 1 4 2 5 3 6

// 1 1 1 1 2 2 2

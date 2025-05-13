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
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (auto &n : nums)
            freq[n]++;

        int limit = n / 3;
        vector<int> res;
        for (auto &[k, v] : freq)
            if (v > limit)
                res.push_back(k);

        return res;
    }
};

// naive solution with hashmap

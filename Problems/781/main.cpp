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
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> freq;
        for (auto &a : answers)
        {
            freq[a]++;
        }

        int res = 0;
        for (auto kv : freq)
            res += ceil(double(kv.second) / double(kv.first + 1)) * (kv.first + 1);

        return res;
    }
};

// minimum => same answer view as one group
// if freq > answer => multiple group

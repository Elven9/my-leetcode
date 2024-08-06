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

using namespace std;

class Solution
{
public:
    string findLongestWord(string s, vector<string> &dict)
    {
        int n = dict.size();
        vector<int> state(n, 0);

        for (auto c : s)
            for (int i = 0; i < n; i++)
                if (dict[i][state[i]] == c)
                    state[i]++;

        string res;
        for (int i = 0; i < n; i++)
        {
            int tmp = dict[i].size();
            if (tmp != state[i])
                continue;
            if (tmp > res.size() || (tmp == res.size() && res.compare(dict[i]) > 0))
                res = dict[i];
        }

        return res;
    }
};

// DP check and get result -> 1e9 too large
// no dp, dp is for check LCS, here we only need to check if a is b subsequence
//
// -> O(Nn) -> 1e6, it will work

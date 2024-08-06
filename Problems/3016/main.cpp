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
    int minimumPushes(string word)
    {
        // count frequency
        // sort by frequency, group by 8

        auto freq = vector<int>(26, 0);
        for (auto c : word)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int res = 0;
        for (int i = 0; i < 26; i++)
            res += freq[i] * (i / 8 + 1);

        return res;
    }
};

// greedy by characteristic
//
// 是有後設性的 所以不可能是 dp

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
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> presum(n + 1, 0);

        // gen prefix sum
        for (int i = 1; i <= n; i++)
        {
            auto &w = words[i - 1];
            presum[i] = presum[i - 1];
            if (vowel.find(w[0]) != vowel.end() && vowel.find(w[w.size() - 1]) != vowel.end())
                presum[i]++;
        }

        vector<int> res;
        for (auto &q : queries)
        {
            res.push_back(presum[q[1] + 1] - presum[q[0]]);
        }
        return res;
    }
};

// prefix sum ... ?

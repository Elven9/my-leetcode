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
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        int cur = !groups[0];

        vector<string> res;
        for (int i = 0; i < n; i++)
            if (groups[i] != cur)
            {
                res.push_back(words[i]);
                cur = groups[i];
            }

        return res;
    }
};

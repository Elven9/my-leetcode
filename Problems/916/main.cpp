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
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> MAX(26, 0);

        for (auto &w : words2)
        {
            vector<int> freq(26, 0);
            for (auto &c : w)
                freq[c - 'a']++;

            for (int i = 0; i < 26; i++)
                MAX[i] = max(MAX[i], freq[i]);
        }

        vector<string> res;
        for (auto &w : words1)
        {
            vector<int> freq(26, 0);
            for (auto &c : w)
                freq[c - 'a']++;

            bool ok = true;
            for (int i = 0; i < 26; i++)
                if (freq[i] < MAX[i])
                {
                    ok = false;
                    break;
                }
            if (ok)
                res.push_back(w);
        }

        return res;
    }
};

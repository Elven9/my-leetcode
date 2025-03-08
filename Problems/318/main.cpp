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
    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        vector<int> freq(n, 0);

        for (int i = 0; i < n; i++)
            for (auto &c : words[i])
                freq[i] |= 1 << (c - 'a');

        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ((freq[i] & freq[j]) == 0)
                    res = max(res, int(words[i].size() * words[j].size()));

        return res;
    }
};

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
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> res;

        for (auto &w : words)
            for (auto &t : words)
            {
                if (w != t && t.find(w) != string::npos)
                {
                    res.push_back(w);
                    break;
                }
            }

        return res;
    }
};

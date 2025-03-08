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
    int minimumLength(string s)
    {
        unordered_map<char, int> freq;
        for (auto &c : s)
            freq[c]++;

        int res = 0;
        for (char c = 'a'; c <= 'z'; c++)
        {
            int f = freq[c];
            if (f >= 3)
                res += f % 2 == 0 ? 2 : 1;
            else
                res += f;
        }
        return res;
    }
};

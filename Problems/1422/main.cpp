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
    int maxScore(string s)
    {
        int one = 0;
        for (auto &c : s)
            if (c == '1')
                one++;

        int zero = 0, res = INT_MIN;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == s.size() - 1)
                break;
            char &c = s[i];
            if (c == '1')
                one--;
            else
                zero++;
            res = max(res, zero + one);
        }

        return res;
    }
};

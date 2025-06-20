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
    int myAtoi(string s)
    {
        // 1. trim left
        int i = 0;
        while (s[i] == ' ')
            i++;
        s = s.substr(i);
        if (!isdigit(s[0]) && s[0] != '+' && s[0] != '-')
            return 0;

        // 2. signedness
        bool isNeg = s[0] == '-';
        if (!isdigit(s[0]))
            s = s.substr(1);

        // 3. trim right non-digit
        i = 0;
        while (isdigit(s[i]))
            i++;
        s = s.substr(0, i);

        // leading zero
        i = 0;
        while (s[i] == '0' && i != s.size() - 1)
            i++;
        s = s.substr(i);

        long long res = 0;
        if (s.size() > 10)
        {
            // Need to refactor this place
            res = isNeg ? INT_MIN : INT_MAX;
        }
        else
        {
            for (char &c : s)
            {
                res *= 10;
                res += c - '0';
            }
            res *= (isNeg ? -1 : 1);
        }

        // 4. rounding
        if (res > INT_MAX)
            res = INT_MAX;
        else if (res < INT_MIN)
            res = INT_MIN;
        return res;
    }
};

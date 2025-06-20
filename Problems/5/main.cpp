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
    string longestPalindrome(string s)
    {
        int n = s.size();

        int len = 0;
        string res;
        for (int i = 0; i < n; i++)
        {
            // aba
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            if (r - l - 1 > len)
            {
                len = r - l - 1;
                res = s.substr(l + 1, len);
            }

            // aa
            l = i - 1;
            r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            if (r - l - 1 > len)
            {
                len = r - l - 1;
                res = s.substr(l + 1, len);
            }
        }
        return res;
    }
};

// O(n^2) easy solution -> check on each viable spot.

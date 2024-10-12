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
    int findSubstringInWraproundString(string s)
    {
        int i = 0, n = s.size();
        vector<int> ch(256, 0);
        while (i < n)
        {
            int j = i + 1;
            while (j < n && (s[j] - s[j - 1] == 1 || (s[j - 1] == 'z' && s[j] == 'a')))
                j++;

            while (i < j)
            {
                ch[s[i]] = max(ch[s[i]], j - i);
                i++;
            }
        }
        return accumulate(ch.begin(), ch.end(), 0);
    }
};

// two pointer + string interval;

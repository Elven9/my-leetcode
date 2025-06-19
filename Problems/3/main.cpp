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

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int l = 0, r = 0;
        vector<int> freq(256, 0);

        int res = 0;
        while (r < n)
        {
            freq[s[r]]++;
            if (freq[s[r]] > 1)
            {
                do
                    freq[s[l]]--;
                while (s[l++] != s[r]);
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};

// sliding windows ->

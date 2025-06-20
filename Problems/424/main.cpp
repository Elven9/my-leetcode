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
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int l = 0, r = 0;
        vector<int> freq(26, 0);

        while (r < n)
        {
            freq[s[r++] - 'A']++;
            if (!isValid(freq, k))
            {
                freq[s[l++] - 'A']--;
            }
        }
        return r - l;
    }

    bool isValid(vector<int> &freq, int &k)
    {
        int sum = 0, MAX = 0;
        for (int i = 0; i < 26; i++)
        {
            sum += freq[i];
            MAX = max(MAX, freq[i]);
        }
        return sum - MAX <= k;
    }
};

// sliding windows
// check is valid -> update answer, move right
// not valid any more -> (move left, move right)

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
    bool canConstruct(string s, int K)
    {
        int n = s.size();
        if (K > n)
            return false;

        unordered_map<char, int> freq;
        int even = 0;
        for (auto &c : s)
        {
            freq[c]++;
            if (freq[c] == 2)
            {
                freq[c] = 0;
                even++;
            }
        }
        int odd = 0;
        for (char i = 'a'; i <= 'z'; i++)
            if (freq[i] == 1)
                odd++;

        return !(odd > K);
    }
};

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
    bool isAnagram(string s, string t)
    {
        vector<int> freq(225, 0);

        for (auto &c : s)
            freq[c]++;
        for (auto &c : t)
            freq[c]--;
        for (auto &f : freq)
            if (f != 0)
                return false;
        return true;
    }
};

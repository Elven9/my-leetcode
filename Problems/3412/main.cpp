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
    long long calculateScore(string s)
    {
        unordered_map<char, stack<int>> freq;

        long long res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (freq[rev(s[i])].size() != 0)
            {
                res += i - freq[rev(s[i])].top();
                freq[rev(s[i])].pop();
            }
            else
            {
                freq[s[i]].push(i);
            }
        }
        return res;
    }
    char rev(char &c)
    {
        return 'z' - c + 'a';
    }
};

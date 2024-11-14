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
    int minChanges(string s)
    {
        vector<int> cnt;

        int i = 0;
        while (i < s.size())
        {
            int j = i + 1;
            while (j < s.size() && s[j] == s[i])
                j++;
            cnt.push_back(j - i);
            i = j;
        }

        int res = 0, n = cnt.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (cnt[i] % 2 == 0)
                continue;
            cnt[i + 1]--;
            res++;
        }
        return res;
    }
};

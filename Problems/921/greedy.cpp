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
    int minAddToMakeValid(string s)
    {
        int cnt = 0, res = 0;
        for (auto &c : s)
        {
            cnt += c == ')' ? -1 : 1;
            if (cnt < 0)
            {
                res++;
                cnt = 0;
            }
        }
        return res + cnt;
    }
};

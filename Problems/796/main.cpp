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
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        int n = s.size();
        int i = 0, j = 0;

        while (true)
        {
            i = 0;
            while (j < n && goal[j] != s[i])
                j++;
            if (j >= n)
                return false;
            int nj = j + 1;

            while (i < n)
            {
                if (s[i] != goal[j])
                    break;
                i++;
                j = (j + 1) % n;
            }
            if (i == n)
                return true;
            j = nj;
        }
        return false;
    }
};

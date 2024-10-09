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
    string convert(string s, int numRows)
    {
        int n = s.size();
        vector<string> segs(numRows, "");

        int dir = 1, cur = 0, i = 0;
        while (i < n)
        {
            segs[cur].push_back(s[i]);
            if (cur + dir == numRows)
            {
                dir = -1;
            }
            else if (cur + dir == -1)
            {
                dir = 1;
            }
            if (cur + dir >= 0 && cur + dir < numRows)
                cur += dir;
            i++;
        }

        stringstream ss;
        for (auto &seg : segs)
            ss << seg;
        return ss.str();
    }
};

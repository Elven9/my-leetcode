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
    string addBinary(string a, string b)
    {
        int m = a.size() - 1, n = b.size() - 1;

        string res;
        int o = 0;
        while (m >= 0 || n >= 0)
        {
            if (m >= 0)
                o += a[m--] == '1' ? 1 : 0;
            if (n >= 0)
                o += b[n--] == '1' ? 1 : 0;
            res = to_string(o & 1) + res;
            o = o >= 2 ? o >> 1 : 0;
        }
        if (o > 0)
            res = to_string(o) + res;
        return res;
    }
};

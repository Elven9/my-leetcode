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
    long long minEnd(int n, int x)
    {
        long long res = x;
        n--;
        long long pos = 1;
        while (n > 0)
        {
            if (!(res & pos))
            {
                res |= (n & 1) * pos;
                n >>= 1;
            }
            pos <<= 1;
        }
        return res;
    }
};

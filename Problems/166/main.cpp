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
    string fractionToDecimal(int n, int d)
    {
        unordered_map<int, int> MAP;
        long N = n, D = d;
        bool isNegative = (N < 0 && D > 0) || (N > 0 && D < 0);
        if (N < 0)
            N *= -1;
        if (D < 0)
            D *= -1;

        string res = to_string(N / D);
        N = N % D * 10;
        if (N > 0)
            res += ".";
        int cnt = 1;
        while (N > 0)
        {
            if (MAP[N] != 0)
            {
                int dist = cnt - MAP[N];
                int n = res.size();
                res = res.substr(0, n - dist) + "(" + res.substr(n - dist, dist) + ")";
                break;
            }
            MAP[N] = cnt++;
            res += to_string(N / D);
            N = N % D * 10;
        }
        if (isNegative)
            res = "-" + res;
        return res;
    }
};

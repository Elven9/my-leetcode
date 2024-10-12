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
    int brokenCalc(int v, int t)
    {
        if (v >= t)
            return v - t;
        else if (t % 2 == 1)
            return brokenCalc(v, t + 1) + 1;
        else
        {
            // 要用 t/2 不然感覺有 overflow 的問題
            if (v <= t / 2)
                return brokenCalc(v, t / 2) + 1;
            else
                return brokenCalc(t / 2, t) + (v - t / 2);
        }
    }
};

// 純 dfs or bfs 都會有 TLE
//
// 加上 heuristic, greedy 的方式去 approach, 找 minimum ops

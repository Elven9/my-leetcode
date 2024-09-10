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
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int res = 0;
        for (auto &c : points)
        {
            unordered_map<int, int> MAP;
            for (auto &p : points)
            {
                if (c[0] == p[0] && c[1] == p[1])
                    continue;
                MAP[dist(c, p)]++;
            }
            for (auto &[k, v] : MAP)
                res += v * (v - 1);
        }

        return res;
    }

    int dist(vector<int> &a, vector<int> &b)
    {
        return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
    }
};

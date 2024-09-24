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
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();
        sort(stations.begin(), stations.end());
        priority_queue<int, vector<int>> pq;
        pq.push(startFuel);

        int cur = 0, res = -1, idx = 0;
        while (cur < target)
        {
            if (pq.empty())
                return -1;
            cur += pq.top();
            res++;
            pq.pop();
            while (idx < n && stations[idx][0] <= cur)
                pq.push(stations[idx++][1]);
        }

        return res;
    }
};

// greedy
// 跟 45 最大的差別，就在於 45 是到某個地方，你的油會全部 reset，
// 啊這個是可以把剩下的油保留下來的，所以 minimum 有可能是在之前經過過的加油站中找最大的那個加油站來用

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
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> proj;
        for (int i = 0; i < n; i++)
            proj.push_back({capital[i], profits[i]});
        sort(proj.begin(), proj.end());

        int idx = 0;
        priority_queue<int, vector<int>> pq;
        while (k > 0)
        {
            while (idx < n && proj[idx].first <= w)
                pq.push(proj[idx++].second);
            if (pq.empty())
                break;
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};

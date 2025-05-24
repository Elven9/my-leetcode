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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        pq.push(newInterval);
        for (auto &i : intervals)
            pq.push(i);

        vector<vector<int>> res;
        do
        {
            int st = pq.top()[0], ed = pq.top()[1];
            pq.pop();
            while (!pq.empty() && pq.top()[0] <= ed)
            {
                ed = max(ed, pq.top()[1]);
                pq.pop();
            }
            res.push_back({st, ed});
        } while (!pq.empty());

        return res;
    }
};

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

using E = array<int, 3>;
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &a, vector<int> &b, int k)
    {
        int m = a.size(), n = b.size();
        priority_queue<E, vector<E>, greater<>> q;
        set<pair<int, int>> visited;

        vector<vector<int>> res;
        q.push({a[0] + b[0], 0, 0});
        while (k > 0 && !q.empty())
        {
            auto top = q.top();
            int i = top[1], j = top[2];
            q.pop();
            res.push_back({a[i], b[j]});
            k--;
            if (i + 1 < m && visited.find({i + 1, j}) == visited.end())
            {
                q.push({a[i + 1] + b[j], i + 1, j});
                visited.insert({i + 1, j});
            }
            if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
            {
                q.push({a[i] + b[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }

        return res;
    }
};

// BFS w/ PQ, 只取最小的數值

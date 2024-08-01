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

using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &E)
    {
        auto comp = [&](vector<int> &a, vector<int> &b) -> bool
        {
            // To handle envelopes with the same width but different heights,
            // reverse the height comparison so that the lower_bound function
            // can correctly override the previous larger height envelope
            if (a[0] == b[0])
                return a[1] > b[1];
            else
                return a[0] < b[0];
        };
        sort(E.begin(), E.end(), comp);

        // It's ok to check height alone, since width has already sorted.
        vector<int> q;
        for (auto &e : E)
        {
            auto pos = lower_bound(q.begin(), q.end(), e[1]);
            if (pos == q.end())
                q.push_back(e[1]);
            else
                *pos = e[1];
        }

        return q.size();
    }
};

// O(n^2) dp solution, it's gonna TLE ww

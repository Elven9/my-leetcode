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
    vector<int> corpFlightBookings(vector<vector<int>> &B, int n)
    {
        int m = B.size();
        sort(B.begin(), B.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> res;

        int val = 0, idx = 0;
        for (int i = 1; i <= n; i++)
        {
            while (idx < m && B[idx][0] <= i)
            {
                pq.push({B[idx][1], B[idx][2]});
                val += B[idx++][2];
            }
            while (!pq.empty() && pq.top().first < i)
            {
                val -= pq.top().second;
                pq.pop();
            }
            res.push_back(val);
        }

        return res;
    }
};

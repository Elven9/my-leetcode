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
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
    {
        sort(updates.begin(), updates.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> res(length, 0);

        int idx = 0, cur = 0;
        for (int i = 0; i < length; i++)
        {
            while (!pq.empty() && pq.top().first < i)
            {
                cur -= pq.top().second;
                pq.pop();
            }
            while (idx < updates.size() && updates[idx][0] == i)
            {
                cur += updates[idx][2];
                pq.push({updates[idx][1], updates[idx++][2]});
            }
            res[i] = cur;
        }
        return res;
    }
};

// 1. sort + end pq
// 2. timestamp solution O(2n), may takes longer to compute

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
#include <cfloat>

using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < n; i++)
            workers.push_back({double(wage[i]) / quality[i], quality[i]});

        sort(workers.begin(), workers.end());

        priority_queue<int, vector<int>> pq;
        int sum = 0;
        double res = DBL_MAX;

        for (int i = 0; i < n; i++)
        {
            auto &[u, q] = workers[i];

            if (pq.size() < k - 1)
            {
                pq.push(q);
                sum += q;
                continue;
            }

            sum += q;
            res = min(res, sum * u);
            pq.push(q);
            sum -= pq.top();
            pq.pop();
        }

        return res;
    }
};

// wageExp[i] / quality[i] >= wage[i] / quality[i]

// wageExp[i] / quality[i] => max wageUnit amount k selected worker

// total money = maxWageUnit * total quality

// => quality as small as possible

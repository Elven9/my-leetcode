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
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &WORKER)
    {
        map<int, int, greater<int>> works;

        for (int i = 0; i < profit.size(); i++)
            works[profit[i]] = INT_MAX;

        for (int i = 0; i < difficulty.size(); i++)
            works[profit[i]] = min(works[profit[i]], difficulty[i]);

        map<int, int, greater<int>> workers;
        for (auto &w : WORKER)
            workers[w]++;

        auto work = works.begin();
        auto worker = workers.begin();

        int res = 0;
        while (work != works.end() && worker != workers.end())
        {
            if (work->second > worker->first)
            {
                work++;
                continue;
            }
            res += worker->second * work->first;
            worker++;
        }

        return res;
    }
};

// difficulty -> max profit
// work-> freq
// scan from best effort than last

// 1. compute difficulty with max profit w/ map
// 2. worker freq
// 3. compute maxima profit

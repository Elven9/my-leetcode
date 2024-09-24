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
    int scheduleCourse(vector<vector<int>> &C)
    {
        sort(C.begin(), C.end(), [](vector<int> &a, vector<int> &b) -> bool
             { return a[1] < b[1]; });
        priority_queue<int, vector<int>> pq;

        int cur = 0;
        for (auto &c : C)
        {
            if (cur + c[0] <= c[1])
            {
                pq.push(c[0]);
                cur += c[0];
            }
            else
            {
                if (pq.empty() || c[0] > pq.top())
                    continue;
                cur -= pq.top();
                pq.pop();
                cur += c[0];
                pq.push(c[0]);
            }
        }

        return pq.size();
    }
};

// Greedy Order -> 先根據 last day 去排，如果超過 due day 就把一個最大時間踢掉 => 前面要塞越小越好
// sort + pq

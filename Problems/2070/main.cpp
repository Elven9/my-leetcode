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
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        sort(items.begin(), items.end());

        for (int i = 1; i < items.size(); i++)
            items[i][1] = max(items[i - 1][1], items[i][1]);

        vector<int> res;
        for (auto &q : queries)
        {
            // 用 {q, INT_MAX} 是因為只有最後一個相同 price 的 element 是對的
            // 這樣一方面可以避掉 comparator 不能傳 reference 的問題（ runtime 超久 )
            auto it = lower_bound(items.begin(), items.end(), vector<int>{q, INT_MAX});
            if (it == items.end())
            {
                res.push_back(items.back()[1]);
            }
            else
            {
                int n = it - items.begin();
                if (q == items[n][0])
                    res.push_back(items[n][1]);
                else
                    res.push_back(n == 0 ? 0 : items[n - 1][1]);
            }
        }

        return res;
    }
};

// O(nlogn) sort, O(n) store biggest price under certain price

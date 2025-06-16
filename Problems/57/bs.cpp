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
    using cc = const vector<int> &;
    vector<vector<int>> insert(vector<vector<int>> &I, vector<int> &ni)
    {
        auto left = lower_bound(I.begin(), I.end(), vector<int>{ni[0], ni[0]}, [](cc a, cc b)
                                { return a[1] < b[1]; });
        // left , right 都要確保有找到
        if (left != I.end())
            ni[0] = min(ni[0], (*left)[0]);
        auto right = upper_bound(I.begin(), I.end(), vector<int>{ni[1], ni[1]}, [](cc a, cc b)
                                 { return a[0] < b[0]; });
        if (right - I.begin() - 1 >= 0)
            ni[1] = max(ni[1], I[right - I.begin() - 1][1]);

        // 整理 result 這樣寫花 O(n)+O(logn), 但比較乾淨 .. 又不會錯 ...
        vector<vector<int>> res;
        for (auto &i : I)
            if (i[1] < ni[0] || i[0] > ni[1])
                res.push_back(i);
        res.insert(upper_bound(res.begin(), res.end(), ni), ni);
        return res;
    }
};

// binary search on both end, => calulate merge interval

// => left: first "end" greater >= than new start
// => right: first "start" greater than new end

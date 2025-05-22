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
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        // Scanning Line !!!
        // 有點像是用 timestamp 在處理這個問題，也不 care 是哪個會議ㄉ
        // 反正就是個 timestamp
        vector<pair<int, int>> ts;
        for (auto &i : intervals)
        {
            ts.push_back({i[0], 1});
            ts.push_back({i[1], -1});
        }

        sort(ts.begin(), ts.end());
        int cnt = 0, res = INT_MIN;
        for (auto &p : ts)
        {
            cnt += p.second;
            res = max(res, cnt);
        }
        return res;
    }
};

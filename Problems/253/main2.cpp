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

        // 這裡反而不能用 start -> -1, end -> 1
        // 因為是取 max 的關係，這樣設定可以讓 -1 的都先被執行到，同個 ts 不會有先開始後結束的問題
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

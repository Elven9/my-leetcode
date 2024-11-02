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
    short visited[1 << 21] = {0};
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        // 小於的話這邊不會 works，最後一個 solution 會是 false 導致誤判
        if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }

    // 狀態壓縮，不用用 set ww
    bool dfs(int state, int sum, int &MAX, int &D)
    {
        if (visited[state] != 0)
            return visited[state] == 1;
        bool res = false;
        for (int i = 1; i <= MAX; i++)
        {
            if ((state >> i) & 1)
                continue;
            if (sum + i >= D)
            {
                res = true;
                break;
            }

            if (!dfs(state + (1 << i), sum + i, MAX, D))
            {
                res = true;
                break;
            }
        }

        visited[state] = res ? 1 : 2;
        return res;
    }
};

// 重點是對手不能贏，然後去 try try 每種 combination

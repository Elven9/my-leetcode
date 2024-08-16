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

using LL = long long;
class Solution
{
public:
    vector<string> res;
    LL T;
    vector<string> addOperators(string num, int target)
    {
        T = target;
        dfs(num, 0, 0, 0, "");
        return res;
    }

    void dfs(string &num, int st, LL cur, LL pro, string expr)
    {
        if (st == num.size())
        {
            if (cur == T)
                res.push_back(expr);
            return;
        }

        for (int i = st + 1; i <= num.size(); i++)
        {
            string curNum = num.substr(st, i - st);

            if (curNum.size() > 1 && curNum[0] == '0')
                break;

            if (expr.size() == 0)
            {
                dfs(num, i, stoll(curNum), stoll(curNum), curNum);
            }
            else
            {
                dfs(num, i, cur + stoll(curNum), stoll(curNum), expr + "+" + curNum);
                dfs(num, i, cur - stoll(curNum), -stoll(curNum), expr + "-" + curNum);
                dfs(num, i, cur - pro + stoll(curNum) * pro, pro * stoll(curNum), expr + "*" + curNum);
            }
        }
    }
};

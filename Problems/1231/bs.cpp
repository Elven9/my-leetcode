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
    int maximizeSweetness(vector<int> &sweetness, int k)
    {
        k++;
        int l = 0, r = INT_MAX;

        while (l < r)
        {
            int mid = r - (r - l) / 2;
            if (!check(sweetness, k, mid))
                r = mid - 1;
            else
                l = mid;
        }

        // 實際 dry run 印出來就會很有感覺，這題是一定會有 solution 的，不用 double check
        return l;
    }

    bool check(vector<int> &S, int k, int &mid)
    {
        // 重點是 not !check()，可以 rule out 整個右側 solution space
        int sum = 0;
        for (auto &s : S)
        {
            sum += s;
            if (sum >= mid)
            {
                k--;
                sum = 0;
            }
        }
        return k <= 0;
    }
};

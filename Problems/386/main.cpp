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

using namespace std;

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;
        int cur = 1;

        while (true)
        {
            res.push_back(cur);
            if (cur * 10 <= n)
            {
                cur *= 10;
                continue;
            }
            while (cur + 1 > n || cur % 10 == 9)
                cur /= 10;
            if (cur == 0)
                break;
            cur++;
        }

        return res;
    }
};

// 100

// greedy 的點在於，原本需要先列出來再 sort 的 strategy 可以因為字典序的特性，
// 直接用 gen 的方式產生 .. ?

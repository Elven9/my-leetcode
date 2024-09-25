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
    string reorganizeString(string s)
    {
        unordered_map<char, int> cnt;
        for (auto &c : s)
            cnt[c]++;

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for (auto &[k, v] : cnt)
            pq.push({v, k});

        string res = "";
        while (!pq.empty())
        {
            vector<pair<int, char>> tmp;
            for (int k = 0; k < 2; k++)
            {
                if (pq.empty())
                    break;
                auto [freq, c] = pq.top();
                pq.pop();
                if (res.size() > 0 && c == res.back())
                    return "";
                res.push_back(c);
                if (freq > 1)
                    tmp.push_back({freq - 1, c});
            }

            for (auto p : tmp)
                pq.push({p.first, p.second});
        }

        return res;
    }
};

// greedy 想法！兩個範圍內不要相等 ( stride k length = 2 )
// 先把頻率最高的排在奇數位
// 剩下隨便亂放
//
// k=2 的特例

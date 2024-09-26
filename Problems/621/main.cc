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
    int leastInterval(vector<char> &tasks, int n)
    {
        n++;
        unordered_map<char, int> cnt;
        for (auto &t : tasks)
            cnt[t]++;

        priority_queue<int, vector<int>> pq;
        for (auto &[_, v] : cnt)
            pq.push(v);

        int res = 0;
        while (!pq.empty())
        {
            int k = min(int(pq.size()), n);

            vector<int> buf;
            res += k;
            for (int i = 0; i < k; i++)
            {
                int freq = pq.top();
                pq.pop();
                if (freq > 1)
                    buf.push_back(freq - 1);
            }
            for (auto &f : buf)
                pq.push(f);
            if (!pq.empty())
                res += n - k;
        }

        return res;
    }
};

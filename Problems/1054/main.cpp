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
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        unordered_map<int, int> cnt;
        for (auto &c : barcodes)
            cnt[c]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (auto &[k, v] : cnt)
            pq.push({v, k});

        vector<int> res;
        while (!pq.empty())
        {
            int k = min(2, int(pq.size()));

            vector<pair<int, int>> buf;
            while (k-- > 0)
            {
                auto [freq, code] = pq.top();
                pq.pop();
                res.push_back(code);
                if (freq > 1)
                    buf.push_back({freq - 1, code});
            }

            for (auto &p : buf)
                pq.push(p);
        }

        return res;
    }
};

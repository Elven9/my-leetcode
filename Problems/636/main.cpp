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

class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> res(n, 0);

        stack<pair<int, int>> st;
        for (auto &l : logs)
        {
            int lp = l.find(":"), rp = l.rfind(":");
            int id = stoi(l.substr(0, lp));
            string op = l.substr(lp + 1, rp - lp - 1);
            int time = stoi(l.substr(rp + 1, l.size() - rp - 1));
            if (st.empty())
            {
                st.push({id, time});
                continue;
            }
            auto [last, t] = st.top();
            if (op == "start")
            {
                res[last] += time - t;
                st.push({id, time});
            }
            else
            {
                res[last] += time - t + 1;
                st.pop();
                if (!st.empty())
                    st.top().second = time + 1;
            }
        }

        return res;
    }
};

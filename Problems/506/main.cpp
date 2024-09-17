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
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<pair<int, int>> tmp;
        for (int i = 0; i < score.size(); i++)
            tmp.push_back({score[i], i});

        sort(tmp.begin(), tmp.end(), greater<pair<int, int>>());

        vector<string> res(score.size());
        for (int i = 0; i < tmp.size(); i++)
        {
            int idx = tmp[i].second;

            if (i == 0)
            {
                res[idx] = "Gold Medal";
            }
            else if (i == 1)
            {
                res[idx] = "Silver Medal";
            }
            else if (i == 2)
            {
                res[idx] = "Bronze Medal";
            }
            else
            {
                res[idx] = to_string(i + 1);
            }
        }

        return res;
    }
};

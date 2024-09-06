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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<int>> MAP;

        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end()); // 這個居然不會很耗時間 ww
            MAP[s].push_back(i);
        }

        vector<vector<string>> res;
        for (auto &[k, v] : MAP)
        {
            res.push_back({});
            for (auto &i : v)
                res.back().push_back(strs[i]);
        }

        return res;
    }
};

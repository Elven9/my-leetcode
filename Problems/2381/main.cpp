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
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        sort(shifts.begin(), shifts.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n = shifts.size(), m = s.size(), r = 0;

        stringstream ss;
        int cur = 0;
        for (int i = 0; i < m; i++)
        {
            while (r < n && shifts[r][0] <= i)
            {
                cur += shifts[r][2] ? 1 : -1;
                pq.push({shifts[r][1], shifts[r][2]});
                r++;
            }
            while (pq.size() != 0 && pq.top().first < i)
            {
                cur -= pq.top().second ? 1 : -1;
                pq.pop();
            }
            int tmp = (s[i] - 'a' + cur) % 26;
            tmp = tmp < 0 ? tmp + 26 : tmp;
            ss << char(tmp + 'a');
        }

        return ss.str();
    }
};

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
    int lengthLongestPath(string input)
    {
        int n = input.size();
        int res = 0, i = 0, len = 0;

        stack<string> s;
        while (true)
        {
            int j = input.find("\n", i);

            int cnt = 0;
            while (i < n && input[i] == '\t')
            {
                cnt++;
                i++;
            }
            while (s.size() > cnt)
            {
                len -= s.top().size();
                s.pop();
            }
            string name = input.substr(i, j - i);
            if (name.find('.') != string::npos)
                res = max(res, len + cnt + int(name.size()));

            if (j == string::npos)
                break;
            s.push(name);
            len += name.size();
            i = j + 1;
        }
        return res;
    }
};

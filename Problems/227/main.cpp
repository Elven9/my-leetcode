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
    int calculate(string s)
    {

        int i = 0;
        vector<int> q; // important point, ADD segments stack
        int st = 0;
        while (i < s.size())
        {
            char &c = s[i];
            if (c == ' ')
            {
                i++;
            }
            else if (isdigit(c))
            {
                int j = i;
                while (isdigit(s[j]))
                    j++;
                int n = stoi(s.substr(i, j - i));
                if (st == 0)
                    q.push_back(n);
                else if (st == 1)
                    q.push_back(-1 * n);
                else if (st == 2)
                    q.back() *= n;
                else if (st == 3)
                    q.back() /= n;
                i = j;
            }
            else
            {
                if (c == '+')
                    st = 0;
                else if (c == '-')
                    st = 1;
                else if (c == '*')
                    st = 2;
                else if (c == '/')
                    st = 3;
                i++;
            }
        }

        int ret = 0;
        for (auto &n : q)
            ret += n;
        return ret;
    }
};

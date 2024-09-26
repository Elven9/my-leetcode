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
    string strWithout3a3b(int a, int b)
    {
        string res = "";
        while (a > 0 || b > 0)
        {
            if (b == 0)
            {
                res.push_back('a');
                a--;
                continue;
            }
            if (a == 0)
            {
                res.push_back('b');
                b--;
                continue;
            }

            if (a > b)
            {
                res.append("aab");
                a -= 2;
                b--;
            }
            else if (b > a)
            {
                res.append("bba");
                b -= 2;
                a--;
            }
            else
            {
                if (res.size() > 0 && res.back() == 'a')
                    res.append("ba");
                else
                    res.append("ab");
                a--;
                b--;
            }
        }

        return res;
    }
};

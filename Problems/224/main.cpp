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
        // clean space
        stack<int> state;
        stack<int> val;

        int i = 0;
        int st = 0, v = 0;
        while (i < s.size())
        {
            char c = s[i];
            if (c == ' ')
            {
                i++;
                continue;
            }
            else if (c == '(')
            {
                state.push(st);
                val.push(v);
                st = v = 0;
            }
            else if (c == ')')
            {
                v = op(state.top(), val.top(), v);
                st = state.top();
                state.pop();
                val.pop();
            }
            else if (c == '+')
            {
                st = 0;
            }
            else if (c == '-')
            {
                st = 1;
            }
            else
            {
                int j = i;
                while (isdigit(s[j]))
                    j++;
                v = op(st, v, stoi(s.substr(i, j - i)));
                i = j - 1;
            }
            i++;
        }

        return v;
    }

    int op(int state, int a, int b)
    {
        return state == 0 ? a + b : a - b;
    }
};

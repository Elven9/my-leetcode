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
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (auto &c : num)
        {
            while (k > 0 && !st.empty() && st.top() > c)
            {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        string res = "";
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        while (res.size() > 0 && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res == "" ? "0" : res;
    }
};

// left most with biggest digit
// place + digit .. ? greedy score function
//
// 轉換成什麼開頭最小，分析問題的能力，在去轉換成 algorithm 好難 Q

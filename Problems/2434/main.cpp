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
    string robotWithString(string s)
    {
        // stack
        stringstream res;
        stack<char> st;
        vector<int> freq(256, 0);
        for (auto &c : s)
            freq[c]++;
        for (auto &c : s)
        {
            st.push(c);
            freq[c]--;
            while (!st.empty() && !hasSmaller(freq, st.top()))
            {
                res << st.top();
                st.pop();
            }
        }

        return res.str();
    }

    bool hasSmaller(vector<int> &freq, char c)
    {
        for (char i = 'a'; i < c; i++)
            if (freq[i] != 0)
                return true;
        return false;
    }
};

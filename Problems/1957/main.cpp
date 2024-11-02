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
    string makeFancyString(string s)
    {
        int n = s.size();
        stringstream ss;

        int i = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && s[i] == s[j])
                j++;
            ss << string(j - i >= 3 ? 2 : j - i, s[i]);
            i = j;
        }

        return ss.str();
    }
};

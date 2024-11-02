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
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> MAP;
        unordered_set<string> inserted;

        int i = 0, j = 0;
        while (j < s.size())
        {
            int next = s.find(' ', j);
            string seg = s.substr(j, next - j);
            if (MAP.find(pattern[i]) == MAP.end() && inserted.find(seg) != inserted.end())
                return false;
            if (MAP.find(pattern[i]) != MAP.end() && MAP[pattern[i]] != seg)
                return false;
            MAP[pattern[i]] = seg;
            inserted.insert(seg);

            i++;
            if (next == string::npos)
                break;
            j = next + 1;
        }
        return i == pattern.size();
    }
};

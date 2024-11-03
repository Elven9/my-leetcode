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
    bool rotateString(string s, string goal)
    {
        // = =
        // Still O(n^2), but cleaner ww
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};

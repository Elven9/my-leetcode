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
    bool checkValidString(string s)
    {
        int lower = 0, upper = 0;
        // upper => * == '('
        // lower => * == ')'

        for (auto &c : s)
        {
            if (c == '(')
            {
                lower++;
                upper++;
            }
            else if (c == ')')
            {
                lower--;
                upper--;
            }
            else
            {
                upper++;
                lower--;
            }

            if (upper < 0)
                return false;
            if (lower < 0)
                lower = 0;
        }

        return lower == 0;
    }
};

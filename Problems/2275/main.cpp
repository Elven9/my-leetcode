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
    int largestCombination(vector<int> &candidates)
    {
        vector<int> cnts(40, 0);

        for (auto c : candidates)
        {
            int i = 0;
            while (c > 0)
            {
                cnts[i] += c & 1 ? 1 : 0;
                c >>= 1;
                i++;
            }
        }
        return *max_element(cnts.begin(), cnts.end());
    }
};

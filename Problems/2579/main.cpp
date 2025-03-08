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
    long long coloredCells(int n)
    {
        long long m = n;
        long long len = 2 * (n - 1) + 1;
        return len * len - 4 * (1 + m - 1) * (m - 1) / 2;
    }
};

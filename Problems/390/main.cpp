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
    int lastRemaining(int n)
    {
        if (n == 1)
            return 1;

        return (n / 2 + 1 - lastRemaining(n / 2)) * 2;
    }
};

// 1 2 3 4 5

// 5 4 3 2 1

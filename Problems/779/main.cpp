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
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        int prev = kthGrammar(n - 1, k / 2 + k % 2);

        if (prev == 0)
            return k % 2 == 0 ? 1 : 0;
        else
            return k % 2 == 0 ? 0 : 1;
    }
};

// 0
// 01
// 0110
// 0110 1001
// 01 10 10 01 10 01 01 10

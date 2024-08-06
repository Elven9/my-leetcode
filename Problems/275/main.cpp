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

using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &C)
    {
        int n = C.size();
        int st = 0, ed = n - 1;

        int res = 0;
        while (st <= ed)
        {
            int c = (st + ed) / 2;

            if (n - c == C[c])
                return n - c;
            else if (n - c < C[c])
            {
                res = n - c;
                ed = c - 1;
            }
            else
            {
                st = c + 1;
            }
        }

        return res;
    }
};

// Binary search

// if C[i] > n-i ==> search ed+st /2

// 0 0 0 0 0

// 5 5 5 5 5

// 6 6 6 6 6

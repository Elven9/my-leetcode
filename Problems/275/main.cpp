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
        int l = 0, r = C.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (n - mid > C[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return n - l;
    }
};

// Binary search

// if C[i] > n-i ==> search ed+st /2

// 0 0 0 0 0

// 5 5 5 5 5

// 6 6 6 6 6

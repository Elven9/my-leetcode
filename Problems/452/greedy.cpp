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
    int findMinArrowShots(vector<vector<int>> &P)
    {
        int n = P.size();
        sort(P.begin(), P.end(), [](vector<int> &a, vector<int> &b) -> bool
             { return a[1] < b[1]; });

        int res = 0, i = 0;
        while (i < n)
        {
            res++;
            int j = i + 1;
            while (j < n && !(P[i][1] < P[j][0]))
                j++;
            i = j;
        }

        return res;
    }
};

// sort by start, end second to make sure overlapping with least lenght interval

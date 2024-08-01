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

using namespace std;

class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>> &R)
    {
        sort(R.begin(), R.end());
        int m = R.size();

        R.insert(R.begin(), {1, 0});
        vector<int> b(m + 1, 0);

        // just like candy
        for (int i = 1; i <= m; i++)
            b[i] = min(R[i][1], b[i - 1] + R[i][0] - R[i - 1][0]);
        for (int i = m - 1; i >= 0; i--)
            b[i] = min(b[i], b[i + 1] + R[i + 1][0] - R[i][0]);

        int res = INT_MIN;
        for (int i = 1; i <= m; i++)
        {
            res = max(res, (R[i][0] - R[i - 1][0] - abs(b[i] - b[i - 1])) / 2 + max(b[i], b[i - 1]));
        }
        // last building ... (48 / 50)
        res = max(res, b[m] + n - R[m][0]);
        return res;
    }
};

// 		    - -
// 	    -		    -
//   -				    -
// 					        -

// 1   				        7   8

// (i-j-diff) / 2 + high one

// 				    -
// 			    -		-
// 		    -
// 	    -
//  -

//  1   				6

// O(nlogn) sort first
// O(n) one scan to get maximum building

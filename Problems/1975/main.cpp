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
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();

        int zero = 0, negs = 0, minNeg = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                zero += matrix[i][j] == 0;
                negs += matrix[i][j] < 0;
                minNeg = min(minNeg, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }

        return zero || negs % 2 == 0 ? sum : sum - 2 * minNeg;
    }
};

// greedy, math problem = =
//
// think of the strategy like passing of negative sign
// * zero can be used to eliminate all negative sign, (thanks to the passing of negative sign)
// * even number of negative can all be resolved
// * single odd number of negative can be pass to the smallest abs element in the matrix;

// 2 9 3
// 5 4 -4
// 1 7 1

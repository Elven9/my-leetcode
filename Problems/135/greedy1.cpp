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
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candy(n, 0);
        candy[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
            else if (ratings[i] == ratings[i - 1])
                candy[i] = 1;
            else
            {
                candy[i] = 1;
                for (int j = i - 1; j >= 0; j--)
                    if (ratings[j] > ratings[j + 1])
                        candy[j] = max(candy[j], candy[j + 1] + 1);
                    else
                        break;
            }
        }

        return accumulate(candy.begin(), candy.end(), 0);
    }
};

// [1, 0, 2]

// 1
// 2 1
// 2 1 2

// O(n^2) solution is ok but 1e8 too large

// [1, 2, 2]

// 1
// 1 2
// 1 2 1

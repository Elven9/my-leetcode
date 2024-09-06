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
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int l = -1e9, r = 1e9;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (check(matrix, k, mid))
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    bool check(vector<vector<int>> &matrix, int &k, int T)
    {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;

        int cnt = 0;
        while (i >= 0 && j < n)
        {
            int val = matrix[i][j];
            if (val <= T)
            {
                cnt += i + 1;
                j++;
            }
            else
            {
                i--;
            }
        }

        return cnt < k;
    }
};

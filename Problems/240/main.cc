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
    bool searchMatrix(vector<vector<int>> &M, int T)
    {
        int m = M.size(), n = M[0].size();
        int i = M.size() - 1, j = 0;

        while (i >= 0 && j < n)
        {
            int &val = M[i][j];
            if (val == T)
                return true;
            else if (val > T)
                i--;
            else
                j++;
        }
        return false;
    }
};

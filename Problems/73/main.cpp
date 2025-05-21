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
    void setZeroes(vector<vector<int>> &M)
    {
        int m = M.size(), n = M[0].size();

        bool fc = false;
        for (int i = 0; i < m; i++)
            if (M[i][0] == 0)
            {
                fc = true;
                break;
            }

        bool fr = false;
        for (int i = 0; i < n; i++)
            if (M[0][i] == 0)
            {
                fr = true;
                break;
            }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (M[i][j] == 0)
                    M[i][0] = M[0][j] = 0;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (M[i][0] == 0 || M[0][j] == 0)
                    M[i][j] = 0;

        if (fc)
        {
            for (int i = 0; i < m; i++)
                M[i][0] = 0;
        }

        if (fr)
        {
            for (int i = 0; i < n; i++)
                M[0][i] = 0;
        }
    }
};

// will overlapped if updated first
// no bit manipulation
// no marker (since value range is from INT_MIN to INT_MAX)

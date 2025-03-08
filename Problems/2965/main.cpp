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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<short> freq(n * n, 0);

        int dup = 0, miss = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                freq[grid[i][j] - 1]++;
                if (freq[grid[i][j] - 1] == 2)
                    dup = grid[i][j];
            }

        for (int i = 0; i < freq.size(); i++)
            if (freq[i] == 0)
            {
                miss = i + 1;
                break;
            }

        return {dup, miss};
    }
};

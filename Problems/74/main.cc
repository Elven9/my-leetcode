#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // Naive solution: Scan row, scan column: O(m+n), O(1)
        // 2 Binary search on both row and columns will be fine
        // O(logm + logn), O(1)

        int m = matrix.size(), n = matrix[0].size();
        int st = 0, ed = m, cen;

        // Search row
        int tRow = -1;
        while (st < ed)
        {
            cen = (st + ed) / 2;
            if (target > matrix[cen][n - 1])
                st = cen + 1;
            else if (target < matrix[cen][0])
                ed = cen;
            else
            {
                tRow = cen;
                break;
            }
        }
        if (tRow == -1)
            return false;

        // Search columm
        st = 0;
        ed = n;
        while (st < ed)
        {
            cen = (st + ed) / 2;
            if (target > matrix[tRow][cen])
                st = cen + 1;
            else if (target < matrix[tRow][cen])
                ed = cen;
            else
                return true;
        }
        return false;
    }
};

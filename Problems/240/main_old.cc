#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // O(m+n), O(1)
        int m = matrix.size(), n = matrix[0].size();
        // Edge Case
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
            return false;

        int i = m - 1, j = 0;
        // Searching
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
            {
                j++;
            }
            else
            {
                i--;
            }
        }
        return false;
    }
    bool searchMatrix_NotALl(vector<vector<int>> &matrix, int target)
    {
        // 118 / 129 Test Cases
        int m = matrix.size(), n = matrix[0].size();
        // Edge Case
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
            return false;

        // Search Row Index
        vector<int> row;
        for (int i = 0; i < m; i++)
            row.push_back(matrix[i][0]);

        int ith = binarySearch(row, target);
        int jth = binarySearch(matrix[0], target);

        if (matrix[ith][0] == target || matrix[0][jth] == target)
            return true;

        // Scan Cross
        int jres = binarySearch(matrix[ith], target);
        if (jres >= 0 && jres < n && matrix[ith][jres] == target)
            return true;

        row.clear();
        for (int i = 0; i < m; i++)
            row.push_back(matrix[i][jth]);

        int ires = binarySearch(row, target);
        if (ires >= 0 && ires < m && matrix[ires][jth] == target)
            return true;

        cout << ith << " " << jth << " " << jres << " " << ires << endl;
        return false;
    }

    int binarySearch(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size(), half;
        while (s < e)
        {
            half = (s + e) / 2;
            if (nums[half] == target)
            {
                return half;
            }
            else if (nums[half] < target)
            {
                s = half + 1;
            }
            else
            {
                e = half;
            }
        }
        return s - 1;
    }
};

int main()
{
    vector<vector<int>> payload = {
        vector<int>{1, 4, 7, 11, 15},
        vector<int>{2, 5, 8, 12, 19},
        vector<int>{3, 6, 9, 16, 22},
        vector<int>{10, 13, 14, 17, 24},
        vector<int>{18, 21, 23, 26, 30}};

    Solution sol;
    sol.searchMatrix(payload, 5);

    return 0;
}

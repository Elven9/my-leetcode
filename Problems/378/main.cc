#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        // Viewed as sorted in k sorted list.
        int n = matrix[0].size(), ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        for (int r = 0; r < n; ++r)
            minHeap.push({matrix[r][0], r, 0});

        for (int i = 0; i < k; ++i)
        {
            auto top = minHeap.top();
            minHeap.pop();
            int r = top[1], c = top[2];
            ans = top[0];
            if (c + 1 < n)
                minHeap.push({matrix[r][c + 1], r, c + 1});
        }
        return ans;
    }
};

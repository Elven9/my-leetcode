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
    int maxDistance(vector<vector<int>> &A)
    {
        int n = A.size();
        int MAX[2] = {0, 0}, MIN[2] = {0, 0};
        A.insert(A.begin(), {INT_MAX, INT_MIN});

        for (int i = 1; i <= n; i++)
        {
            auto arr = A[i];
            if (arr.back() >= A[MAX[0]].back())
            {
                swap(MAX[0], MAX[1]);
                MAX[0] = i;
            }
            else if (arr.back() >= A[MAX[1]].back())
                MAX[1] = i;

            if (arr.front() <= A[MIN[0]].front())
            {
                swap(MIN[0], MIN[1]);
                MIN[0] = i;
            }
            else if (arr.front() <= A[MIN[1]].front())
                MIN[1] = i;
        }

        if (MAX[0] == MIN[0])
            return max(A[MAX[1]].back() - A[MIN[0]].front(), A[MAX[0]].back() - A[MIN[1]].front());
        else
            return A[MAX[0]].back() - A[MIN[0]].front();
    }
};

// greedy O(n)
// brute force O(n^2) => Choose 2

// same max

// max, min at diff array
// second max - min
// max - second min

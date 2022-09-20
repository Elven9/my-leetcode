#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        // May be a dp solution I think
        vector<int> table(n + 1, 1);
        for (int i = 2; i <= n; i++)
        {
            table[i] = 0;
            for (int j = 0; j < i; j++)
            {
                table[i] += table[j] * table[i - j - 1];
            }
        }
        return table[n];
    }
};

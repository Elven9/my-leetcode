#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // Naive Solution, Scan Twice: O(n^2), O(1)
        // Stack Based Solution: O(n), O(n)

        // Runtime Complexity: Stack to use simple array. STL is BAD for simple case.

        vector<int> res(temperatures.size(), 0);
        int n = temperatures.size(), tmp;
        int stack[n], sp = -1;

        for (int i = 0; i < n; i++)
        {
            // Update Stack
            while (sp != -1)
            {
                tmp = stack[sp];
                if (temperatures[tmp] < temperatures[i])
                {
                    res[tmp] = i - tmp;
                    sp--;
                }
                else
                {
                    break;
                }
            }
            stack[++sp] = i;
        }

        return res;
    }
};

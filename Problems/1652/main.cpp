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
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            if (k > 0)
            {
                for (int j = 1; j <= k; j++)
                    sum += code[(i + j) % n];
            }
            else if (k < 0)
            {
                for (int j = 1; j <= -k; j++)
                    sum += code[(n + i - j) % n];
            }
            res[i] = sum;
        }

        return res;
    }
};

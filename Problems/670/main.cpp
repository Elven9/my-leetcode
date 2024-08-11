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
    int maximumSwap(int num)
    {
        vector<int> N;
        while (num > 0)
        {
            N.push_back(num % 10);
            num /= 10;
        }
        reverse(N.begin(), N.end());

        vector<int> MAP(10, INT_MIN);
        int n = N.size();
        for (int i = 0; i < n; i++)
            if (i > MAP[N[i]])
                MAP[N[i]] = i;

        // scan from left to right
        bool swapped = false;
        for (int i = 0; i < N.size(); i++)
        {
            for (int j = 9; j > N[i]; j--)
            {
                if (MAP[j] == INT_MIN || MAP[j] < i)
                    continue;
                swap(N[i], N[MAP[j]]);
                swapped = true;
                break;
            }
            if (swapped)
                break;
        }

        int res = 0;
        for (auto &d : N)
            res = res * 10 + d;

        return res;
    }
};

// 9 X X X X X

// 1. change to char list
// 2. create digit idx map
// 3. check from left to right, check swappable place

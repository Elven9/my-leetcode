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
        // greedy
        vector<int> digits;
        while (num > 0)
        {
            digits.insert(digits.begin(), num % 10);
            num /= 10;
        }

        vector<int> cand(digits.size(), -1);
        int MAX = INT_MIN, idx = -1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < MAX)
            {
                cand[i] = idx;
            }

            if (digits[i] > MAX)
            {
                MAX = digits[i];
                idx = i;
            }
        }

        for (int i = 0; i < digits.size(); i++)
        {
            if (cand[i] != -1)
            {
                swap(digits[i], digits[cand[i]]);
                break;
            }
        }

        int res = 0;
        for (auto &d : digits)
        {
            res += d;
            res *= 10;
        }
        res /= 10;
        return res;
    }
};

// 9 X X X X X

// 1. change to char list
// 2. create digit idx map
// 3. check from left to right, check swappable place

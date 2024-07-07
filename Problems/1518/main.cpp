#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int res = 0;
        while (numBottles >= numExchange)
        {
            res += numExchange;
            numBottles -= numExchange;
            numBottles++;
        }

        return res + numBottles;
    }
};

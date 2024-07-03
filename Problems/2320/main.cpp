#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

using LL = long long;
LL M = 1e9 + 7;
class Solution
{
public:
    int countHousePlacements(int n)
    {
        LL toTake = 1, notTake = 1;
        for (int i = 1; i < n; i++)
        {
            LL tmpToTake = toTake;
            toTake = notTake;
            notTake = (tmpToTake + notTake) % M;
        }
        LL ret = toTake + notTake;
        return ret * ret % M;
    }
};

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
    int maxArea(vector<int> &H)
    {
        int l = 0, r = H.size() - 1;

        int res = INT_MIN;
        while (l < r)
        {
            res = max(res, (r - l) * min(H[l], H[r]));
            if (H[l] < H[r])
                l++;
            else
                r--;
        }
        return res;
    }
};

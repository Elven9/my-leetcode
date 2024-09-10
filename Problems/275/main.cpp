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

using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &C)
    {
        // search on index
        int n = C.size();
        int l = 0, r = n - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (n - mid > C[mid])
                l = mid + 1;
            else
                r = mid;
        }

        // 可能會有找不到的狀況
        return n - l <= C[l] ? n - l : 0;
    }
};

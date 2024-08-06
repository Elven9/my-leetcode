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

using namespace std;

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        if (target.size() != arr.size())
            return false;

        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        for (int i = 0; i < target.size(); i++)
            if (target[i] != arr[i])
                return false;

        return true;
    }
};

// sort and compare .. ? .... ??? O(nlogn)
// scan and check map -> O(n), space O(n)

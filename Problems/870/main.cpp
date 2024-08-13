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
    vector<int> advantageCount(vector<int> &n1, vector<int> &n2)
    {
        int n = n1.size();
        multiset<int> set(n1.begin(), n1.end());
        for (int i = 0; i < n; i++)
        {
            auto item = *set.rbegin() <= n2[i] ? set.begin() : set.upper_bound(n2[i]);
            n1[i] = *item;
            set.erase(item);
        }
        return n1;
    }
};

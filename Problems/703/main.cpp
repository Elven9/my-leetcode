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

class KthLargest
{
public:
    vector<int> a;
    int k;
    KthLargest(int _k, vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        a = nums;
        k = _k;
    }

    int add(int val)
    {
        a.insert(lower_bound(a.begin(), a.end(), val), val);
        return *(a.rbegin() + k - 1);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

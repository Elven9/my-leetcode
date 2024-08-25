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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int pt1 = m - 1, pt2 = n - 1, cur = m + n - 1;

        while (pt1 >= 0 || pt2 >= 0)
            if (pt2 < 0 || (pt1 >= 0 && nums1[pt1] > nums2[pt2]))
                nums1[cur--] = nums1[pt1--];
            else
                nums1[cur--] = nums2[pt2--];
    }
};

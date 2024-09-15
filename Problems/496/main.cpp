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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            while (j < m && nums2[j] != nums1[i])
                j++;
            j++;
            while (j < m && nums2[j] < nums1[i])
                j++;
            if (j < m)
                res[i] = nums2[j];
        }

        return res;
    }
};

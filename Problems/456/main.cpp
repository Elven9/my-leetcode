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
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> mins(n, 0);
        mins[0] = nums[0];

        for (int i = 1; i < n; i++)
            mins[i] = min(mins[i - 1], nums[i]);

        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            int second = INT_MIN;
            while (!st.empty() && st.top() < nums[i])
            {
                second = st.top();
                st.pop();
            }
            if (mins[i] < second && second < nums[i])
                return true;
            st.push(nums[i]);
        }
        return false;
    }
};

// 這題很 greedy 誒

//             Y
//         X
//                 Z
// if 上面那個 solution 不存在 => min before Y is between Y, Z
// => X is min or between (Y, min)
// => Z can't be a solution any more
//
// 所以即使 Z 被剃掉，也沒差，因為就代表那個 Z 不可能在 solution 中了

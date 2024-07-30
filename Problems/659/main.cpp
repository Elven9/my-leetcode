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
    bool isPossible(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> seq;
        vector<bool> checked(n, false);

        for (int i = 0; i < n; i++)
        {
            if (checked[i])
                continue;
            if (seq[nums[i] - 1] != 0)
            {
                // append
                seq[nums[i] - 1]--;
                seq[nums[i]]++;
            }
            else
            {
                // create
                int cur = i;
                for (int j = i + 1; j < n && nums[j] < nums[i] + 3; j++)
                    if (!checked[j] && nums[j] == nums[cur] + 1)
                    {
                        cur = j;
                        checked[cur] = true;
                    }

                if (nums[cur] - 2 != nums[i])
                    return false;
                seq[nums[cur]]++;
            }
            checked[i] = true;
        }

        return true;
    }
};

// try greedy solution
//
// append to previous established sequence first,
// create new sequence second
//
// 如果連這樣都建不出來，就真的沒機會ㄌ

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        unordered_map<int, vector<pair<int, int>>> buckets;
        unordered_map<int, int> count;
        for (int n : nums)
        {
            count[n] += 1;
        }
        for (auto [val, cnt] : count)
        {
            buckets[val % k].push_back({val, cnt});
        }
        int res = 1;
        for (auto it = buckets.begin(); it != buckets.end(); it++)
        {
            res *= robber((*it).second, k);
        }
        return res - 1;
    }
    int robber(vector<pair<int, int>> &bucket, int k)
    {
        sort(bucket.begin(), bucket.end());
        int take = pow(2, bucket[0].second) - 1, notTake = 1;
        for (int i = 1; i < bucket.size(); i++)
        {
            int oldTake = take;
            if (bucket[i].first - k == bucket[i - 1].first)
            {
                take = notTake * (pow(2, bucket[i].second) - 1);
            }
            else
            {
                take = (take + notTake) * (pow(2, bucket[i].second) - 1);
            }
            notTake = oldTake + notTake;
        }
        return take + notTake;
    }
};

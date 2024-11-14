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
#include <cctype>

using namespace std;

class Solution
{
public:
    bool primeSubOperation(vector<int> &nums)
    {
        vector<int> primes;

        for (int n = 2; n <= 1000; n++)
        {
            int cnt = 0;
            for (int i = 2; i * i <= n; i++)
                if (n % i == 0)
                    cnt++;

            if (cnt == 0)
                primes.push_back(n);
        }

        int n = nums.size();
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n; i++)
        {
            int pos = lower_bound(primes.begin(), primes.end(), nums[i]) - primes.begin() - 1;
            bool ok = false;
            while (pos >= 0)
            {
                if (nums[i] - primes[pos] > nums[i - 1])
                {
                    nums[i] = nums[i] - primes[pos];
                    ok = true;
                    break;
                }
                pos--;
            }
            if (!ok && nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }
};

// O(nlogn) greedy solution 1e4
//
// check is prime O(n)

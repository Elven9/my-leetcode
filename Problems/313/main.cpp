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
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        vector<long> ugs = {1};
        vector<int> idx(primes.size(), 0);

        while (ugs.size() < n)
        {
            long m = LONG_MAX;
            for (int i = 0; i < idx.size(); i++)
                m = min(m, ugs[idx[i]] * primes[i]);

            for (int i = 0; i < idx.size(); i++)
                if (m == ugs[idx[i]] * primes[i])
                    idx[i]++;

            ugs.push_back(m);
        }

        return ugs[n - 1];
    }
};

// Ugly Number II, same

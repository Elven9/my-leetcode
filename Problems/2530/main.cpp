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
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>> pq;

        for (auto &n : nums)
            pq.push(n);

        long long score = 0;
        while (k-- > 0)
        {
            int top = pq.top();
            pq.pop();

            score += top;
            pq.push(int(ceil(double(top) / 3)));
        }

        return score;
    }
};

// pq

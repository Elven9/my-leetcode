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
    int nthUglyNumber(int n)
    {
        priority_queue<long, vector<long>, greater<long>> pq;

        pq.push(1);
        while (n-- > 0)
        {
            long top = pq.top();
            pq.pop();
            if (n == 0)
                return top;

            while (!pq.empty() && pq.top() == top)
                pq.pop();
            pq.push(top * 2);
            pq.push(top * 3);
            pq.push(top * 5);
        }

        return 0;
    }
};

// 1
// 2 3 5
// 4 6 10
// 9

// BFS gen and hashmap and cnt .. ?

// priority_queue wwwwwwww

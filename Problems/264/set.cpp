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
    int nthUglyNumber(int n)
    {
        set<long long> q;
        q.insert(1);

        long long res;
        while (n > 0)
        {
            res = *q.begin();
            q.insert(res * 2);
            q.insert(res * 3);
            q.insert(res * 5);
            q.erase(q.begin());
            n--;
        }
        return res;
    }
};

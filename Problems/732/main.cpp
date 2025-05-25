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

class MyCalendarThree
{
public:
    multiset<pair<int, int>> ts;
    MyCalendarThree()
    {
    }

    int book(int startTime, int endTime)
    {
        // timestamp solution -> O(nlogn)
        ts.insert({startTime, 1});
        ts.insert({endTime, -1});

        // check
        int res = INT_MIN, cnt = 0;
        for (auto &v : ts)
        {
            cnt += v.second;
            res = max(res, cnt);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */

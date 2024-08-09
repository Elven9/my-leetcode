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

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

class MyCalendarTwo
{
public:
    multiset<pair<int, int>> Set;
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        vector<pair<int, int>> p;
        for (auto &i : Set)
            if (!(end <= i.first || start >= i.second))
                p.push_back(i);

        for (int i = 1; i < p.size(); i++)
            if (p[i].first < p[i - 1].second)
                return false;

        Set.insert({start, end});
        return true;
    }
};

// X X X X store interval by using start as ordering

// find overlapping with existing interval

// check if each one overlapped interval is overlapping with each other

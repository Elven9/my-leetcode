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

class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (int i = nestedList.size() - 1; i >= 0; i--)
            st.push(nestedList[i]);
    }

    int next()
    {
        int res = st.top().getInteger();
        st.pop();
        return res;
    }

    bool hasNext()
    {
        while (!st.empty() && !st.top().isInteger())
        {
            auto list = st.top().getList();
            st.pop();
            for (int i = list.size() - 1; i >= 0; i--)
                st.push(list[i]);
        }
        return !st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

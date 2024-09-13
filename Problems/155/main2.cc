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

class MinStack
{
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {}

    void push(int val)
    {
        st.push(val);
        minSt.push(min(minSt.empty() ? INT_MAX : minSt.top(), val));
    }

    void pop()
    {
        st.pop();
        minSt.pop();
    }

    int top()
    {
        return int(st.top());
    }

    int getMin()
    {
        return int(minSt.top());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

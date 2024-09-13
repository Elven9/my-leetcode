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

class MyQueue
{
public:
    stack<int> st;
    stack<int> tmp;
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!st.empty())
        {
            tmp.push(st.top());
            st.pop();
        }
        st.push(x);
        while (!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
    }

    int pop()
    {
        int f = int(st.top());
        st.pop();
        return f;
    }

    int peek()
    {
        return int(st.top());
    }

    bool empty()
    {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

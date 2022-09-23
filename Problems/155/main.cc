#include <vector>
#include <iostream>
#include <string>

using namespace std;

class MinStack
{
private:
    // Better implementation should use linked list for efficient memory utilization

    // AMAZING FINDING: using heap is slower than stack lol .....
    int container[30000], minContainer[30000], sp = -1, minsp = -1, curMin = INT_MAX;

public:
    MinStack()
    {
        // container = new int[30000];
        // minContainer = new int[30000];
    }

    // ~MinStack()
    // {
    //     delete[] container;
    //     delete[] minContainer;
    // }

    void push(int val)
    {
        container[++sp] = val;
        minContainer[++minsp] = val < curMin ? val : curMin;
        curMin = minContainer[minsp];
    }

    void pop()
    {
        sp--;
        minsp--;
        curMin = minsp >= 0 ? minContainer[minsp] : INT_MAX;
    }

    int top()
    {
        return container[sp];
    }

    int getMin()
    {
        return minContainer[minsp];
    }
};

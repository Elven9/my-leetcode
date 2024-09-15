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
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        // greedy stack check
        // pop element as fast as possibie
        int n = pushed.size();
        int push = 0, pop = 0;

        stack<int> st;
        while (push < n || pop < n)
        {
            if (!st.empty() && st.top() == popped[pop])
            {
                st.pop();
                pop++;
            }
            else
            {
                if (push == n)
                    return false;
                st.push(pushed[push++]);
            }
        }
        return true;
    }
};

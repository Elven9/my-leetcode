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

class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        int n = H.size();
        stack<int> st;
        st.push(-1);
        H.push_back(-1);

        int res = 0;
        for (int i = 0; i <= n; i++) {
            while (st.size() > 1 && H[st.top()] > H[i]) {
                int top = st.top();
                st.pop();
                res = max(res, H[top]*(i-st.top()-1));
            }
            st.push(i);
        }

        return res;
    }
};

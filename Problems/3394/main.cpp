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

class Solution
{
public:
    bool checkValidCuts(int n, vector<vector<int>> &R)
    {
        int m = R.size();
        // check horizontal
        sort(R.begin(), R.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int cut = 0, i = 0;
        while (i < m)
        {
            int ed = R[i][3];
            while (++i < m && R[i][1] < ed)
                ed = max(ed, R[i][3]);
            cut++;
            if (cut >= 2 && i < m)
                return true;
        }

        // check vertical
        cut = i = 0;
        sort(R.begin(), R.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        while (i < m)
        {
            int ed = R[i][2];
            while (++i < m && R[i][0] < ed)
                ed = max(ed, R[i][2]);
            cut++;
            if (cut >= 2 && i < m)
                return true;
        }
        return false;
    }
};

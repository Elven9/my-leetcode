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
    int intersectionSizeTwo(vector<vector<int>> &I)
    {
        int n = I.size();
        sort(I.begin(), I.end(), [](vector<int> &a, vector<int> &b) -> bool
             { return a[1] < b[1]; });

        vector<int> set;
        set.push_back(I[0][1] - 1);
        set.push_back(I[0][1]);
        for (int i = 1; i < n; i++)
        {
            if (I[i][0] <= *(set.end() - 2))
                continue;
            if (I[i][0] <= *(set.end() - 1))
                if (I[i][1] == *(set.end() - 1))
                    set.insert(set.end() - 1, I[i][1] - 1);
                else
                    set.push_back(I[i][1]);
            else
            {
                set.push_back(I[i][1] - 1);
                set.push_back(I[i][1]);
            }
        }

        return set.size();
    }
};

//  X X X        X X X       X X X
//   [X X] X

// sort by ending
// find  at least two intersection

// 1 2
// 2 3
// 2 4
// 4 5

// 1 2

// 考量 set 裡面已經有啥 分別討論 intersection set 的狀態
// 真的差一點 QQQ 太累ㄌ

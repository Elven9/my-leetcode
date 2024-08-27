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
    vector<vector<int>> intervalIntersection(vector<vector<int>> &F, vector<vector<int>> &S)
    {
        int m = F.size(), n = S.size();
        vector<vector<int>> res;
        int f = 0, s = 0;

        while (f < m && s < n)
        {
            if (F[f][1] < S[s][0])
                f++;
            else if (S[s][1] < F[f][0])
                s++;
            else
            {
                res.push_back({max(F[f][0], S[s][0]), min(F[f][1], S[s][1])});
                if (F[f][1] < S[s][1])
                    f++;
                else
                    s++;
            }
        }

        return res;
    }
};

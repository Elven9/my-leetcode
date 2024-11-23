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
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++)
        {
            int st = n - 1;
            for (int j = n - 1; j >= 0; j--)
            {
                if (box[i][j] == '*')
                {
                    st = j - 1;
                    res[j][m - i - 1] = '*';
                }
                else if (box[i][j] == '#')
                {
                    res[st][m - i - 1] = '#';
                    st--;
                }
            }
        }

        return res;
    }
};

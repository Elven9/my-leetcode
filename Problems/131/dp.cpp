#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        auto isPal = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++)
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                {
                    if (i == j || i == j - 1)
                        isPal[i][j] = true;
                    else
                        isPal[i][j] = isPal[i + 1][j - 1];
                }
            }

        auto temp = vector<string>();
        dfs(isPal, s, 0, temp);
        return res;
    }

    void dfs(vector<vector<bool>> &isPal, string &s, int start, vector<string> &temp)
    {
        if (start == s.size())
            res.push_back(temp);
        for (int i = start; i < s.size(); i++)
            if (isPal[start][i])
            {
                temp.push_back(s.substr(start, i - start + 1));
                dfs(isPal, s, i + 1, temp);
                temp.pop_back();
            }
    }
};

// step1: create dp for palindrome check
// step2: construct result

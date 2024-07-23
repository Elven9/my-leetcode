#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        // Backtracking Recursive Solution
        vector<vector<string>> res;
        vector<string> cur;
        backtrack(res, cur, s);

        return res;
    }

    void backtrack(vector<vector<string>> &res, vector<string> &cur, string s)
    {
        int n = s.size();
        if (n == 0)
        {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            string tmp = s.substr(0, i + 1);
            if (isPalimdrome(tmp))
            {
                cur.push_back(tmp);
                backtrack(res, cur, s.substr(i + 1));
                cur.pop_back();
            }
        }
    }

    bool isPalimdrome(string s)
    {
        int n = s.size();
        int anchor = n / 2 - 1;

        while (anchor >= 0)
        {
            if (s[anchor] != s[n - anchor - 1])
                return false;
            anchor--;
        }
        return true;
    }
};

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        recurPrint(res, "", 0, 0, n);

        return res;
    }

    void recurPrint(vector<string> &res, string str, int open, int close, int max)
    {
        if (str.length() == max * 2)
        {
            res.push_back(str);
            return;
        }

        if (open < max)
        {
            // More Open
            recurPrint(res, str + "(", open + 1, close, max);
        }
        if (close < open)
        {
            recurPrint(res, str + ")", open, close + 1, max);
        }
    }

    vector<string> generateParenthesis_sthWrong(int n)
    {
        // () -> )( ??
        vector<string> res;
        if (n == 0)
            return res;
        else if (n == 1)
        {
            res.push_back("()");
            return res;
        }

        // Recursive Solution, it can be modified as dp solution if the
        // input is a list of n
        vector<string> child = generateParenthesis_sthWrong(n - 1);

        for (auto it = child.begin(); it != child.end(); it++)
        {
            // ( element )
            res.push_back("(" + *it + ")");

            // () element or () element
            res.push_back("()" + *it);
            if (*it + "()" != res.back())
            {
                res.push_back(*it + "()");
            }
        }
        return res;
    }
};

int main(void)
{
    Solution sol;

    vector<string> res1 = sol.generateParenthesis(4);
    vector<string> res2 = sol.generateParenthesis_sthWrong(4);

    for (auto it = res1.begin(); it != res1.end(); it++)
        cout << *it << " ";
    cout << endl;
    for (auto it = res2.begin(); it != res2.end(); it++)
        cout << *it << " ";

    cout << endl
         << endl;

    sort(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());

    for (auto it = res1.begin(); it != res1.end(); it++)
        cout << *it << " ";
    cout << endl;
    for (auto it = res2.begin(); it != res2.end(); it++)
        cout << *it << " ";
}

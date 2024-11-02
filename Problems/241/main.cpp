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
    vector<int> diffWaysToCompute(string exp)
    {
        int n = exp.size();

        vector<int> res;
        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && isdigit(exp[j]))
                j++;

            if (j == n)
                break;

            auto left = diffWaysToCompute(exp.substr(0, j));
            auto right = diffWaysToCompute(exp.substr(j + 1));

            for (auto &l : left)
                for (auto &r : right)
                {
                    if (exp[j] == '+')
                        res.push_back(l + r);
                    else if (exp[j] == '-')
                        res.push_back(l - r);
                    else
                        res.push_back(l * r);
                }

            i = j + 1;
        }
        if (res.size() == 0)
            res.push_back(stoi(exp));
        return res;
    }
};

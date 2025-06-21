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

using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> list;
        for (auto &n : nums)
            list.push_back(to_string(n));

        sort(list.rbegin(), list.rend(), [](string &a, string &b)
             {
            // 這真的好 greedy, 但一想卻很直觀 ..
            // https://leetcode.com/problems/largest-number/solutions/53157/a-simple-c-solution
            // https://github.com/wisdompeak/LeetCode/tree/master/Greedy/179.Largest-Number
            return a+b < b+a; });

        stringstream ss;
        for (auto &s : list)
            ss << s;
        string res = ss.str();
        int i = 0;
        while (i < res.size() - 1 && res[i] == '0')
            i++;

        return res.substr(i);
    }
};

// convert to string
//
// sort reversely

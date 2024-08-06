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
    string largestNumber(vector<int> &N)
    {
        vector<string> nums;
        for (auto &n : N)
            nums.push_back(to_string(n));

        sort(nums.begin(), nums.end(), [](string a, string b) -> bool
             { return (a + b) > (b + a); });

        stringstream ss;
        for (auto &s : nums)
            ss << s;

        if (ss.str()[0] == '0')
            return "0";
        return ss.str();
    }
};

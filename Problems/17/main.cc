#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<char>> map = vector<vector<char>>{
        vector<char>{'a', 'b', 'c'},
        vector<char>{'d', 'e', 'f'},
        vector<char>{'g', 'h', 'i'},
        vector<char>{'j', 'k', 'l'},
        vector<char>{'m', 'n', 'o'},
        vector<char>{'p', 'q', 'r', 's'},
        vector<char>{'t', 'u', 'v'},
        vector<char>{'w', 'x', 'y', 'z'},
    };

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return vector<string>{};

        // Naive Solution
        // Permutation: O(3^n), O(1)
        // Implement w/ Recursive Stack
        vector<string> res;
        // Edge Case
        if (digits.length() == 1)
        {
            for (auto mc = map[digits[0] - '2'].begin(); mc != map[digits[0] - '2'].end(); mc++)
            {
                res.push_back(string(1, *mc));
            }
            return res;
        }

        vector<string> child = letterCombinations(digits.substr(1, string::npos));

        // Map Character
        for (auto mc = map[digits[0] - '2'].begin(); mc != map[digits[0] - '2'].end(); mc++)
        {
            for (auto cs = child.begin(); cs != child.end(); cs++)
            {
                res.push_back(*mc + *cs);
            }
        }
        return res;
    }
};

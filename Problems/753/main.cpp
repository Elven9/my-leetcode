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
    string crackSafe(int n, int k)
    {
        unordered_map<string, int> MAP;
        string ans = "";

        for (int i = 0; i < n - 1; i++)
            ans += "0";

        for (int i = 0; i < pow(k, n); i++)
        {
            string key = ans.substr(ans.size() - (n - 1), n - 1);
            MAP[key] = (MAP[key] + 1) % k;
            ans.push_back('0' + MAP[key]);
        }

        return ans;
    }
};

// 所有 combination 都要走過
// 這很像 greedy 誒 wwww union find .. ?

// 00
// 01
// 10
// 11

// 00110

// 10011

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
    // e 1
    // f 0
    // g 0
    // h 0
    // i 0
    // n 1
    // o 1
    // r 0
    // s 0
    // t 0
    // u 0
    // v 0
    // w 0
    // x 0
    // z 0

    // 0 2 8 6 3 4 5 9 7 1
    // Frequency analysis, greedy strategy => rule out low frequency first
    vector<string> tbl = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };
    int seq[10] = {0, 2, 8, 6, 3, 4, 5, 9, 7, 1};
    string originalDigits(string s)
    {
        int ch[256];
        for (int i = 0; i < 256; i++)
            ch[i] = 0;

        // check frequency
        // for (auto &n: tbl)
        //     for (auto &c: n)
        //         ch[c]++;

        // for (char c='a'; c <= 'z'; c++)
        //     cout << c << " " << ch[c] << endl;
        // return "";

        for (auto &c : s)
            ch[c]++;

        string res;
        for (auto &i : seq)
        {
            int MIN = INT_MAX;
            for (auto &c : tbl[i])
                MIN = min(MIN, ch[c]);

            res.append(string(MIN, '0' + i));
            for (auto &c : tbl[i])
                ch[c] -= MIN;
        }

        sort(res.begin(), res.end());
        return res;
    }
};

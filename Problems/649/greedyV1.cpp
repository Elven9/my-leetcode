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
    bool banned[10005] = {false};
    string predictPartyVictory(string senate)
    {
        int n = senate.size();
        int rCnt = 0, dCnt = 0;
        for (auto &c : senate)
            if (c == 'R')
                rCnt++;
            else
                dCnt++;

        while (rCnt != 0 && dCnt != 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (banned[i])
                    continue;
                int r = i, d = i;
                while (r < n && rCnt != 0 && (banned[r] || senate[r] != 'R'))
                    r = (r + 1) % n;
                while (d < n && dCnt != 0 && (banned[d] || senate[d] != 'D'))
                    d = (d + 1) % n;

                if (senate[i] == 'R' && dCnt != 0)
                {
                    banned[d] = true;
                    dCnt--;
                }
                else if (senate[i] == 'D' && rCnt != 0)
                {
                    banned[r] = true;
                    rCnt--;
                }
                if (rCnt == 0 || dCnt == 0)
                    break;
            }
        }

        return rCnt == 0 ? "Dire" : "Radiant";
    }
};

// DRRDRDRDRDDRDRDR
//  X X X X X X X X

// DRRRRDDD
//  X   XXX
// DRRR
// XX

// R R D D R D R D

// Best Strategy, Ban Left First, if no other party left, ban right

// [R] [D] D

// ONE row for alive
// two pointer for next alive R, D

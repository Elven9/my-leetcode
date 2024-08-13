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
    string predictPartyVictory(string senate)
    {
        int n = senate.size();
        queue<int> R, D;

        for (int i = 0; i < n; i++)
            if (senate[i] == 'R')
                R.push(i);
            else
                D.push(i);

        while (!R.empty() && !D.empty())
        {
            int nextR = R.front(), nextD = D.front();
            if (nextR < nextD)
            {
                D.pop();
                R.push(nextR + n);
                R.pop();
            }
            else
            {
                R.pop();
                D.push(nextD + n);
                D.pop();
            }
        }

        return R.empty() ? "Dire" : "Radiant";
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

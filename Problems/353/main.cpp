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

class SnakeGame
{
public:
    queue<pair<int, int>> f;
    set<pair<int, int>> SET; // for collision detection
    queue<pair<int, int>> body;
    int w, h;
    int score;
    SnakeGame(int width, int height, vector<vector<int>> &food)
    {
        for (auto &c : food)
            f.push({c[0], c[1]});
        body.push({0, 0});
        SET.insert({0, 0});
        w = width;
        h = height;
        score = 0;
    }

    int move(string d)
    {
        int i = body.back().first, j = body.back().second;

        if (d == "U")
            i--;
        else if (d == "R")
            j++;
        else if (d == "D")
            i++;
        else if (d == "L")
            j--;

        if (i < 0 || i >= h || j < 0 || j >= w)
            return -1;
        if (f.front().first == i && f.front().second == j)
        {
            score++;
            f.pop();
            body.push({i, j});
            SET.insert({i, j});
            // Condition: When a piece of food appears on the screen, it is guaranteed that it will not appear on a block occupied by the snake.
            //
            // So it's unnecessary to check collision between head and body.
        }
        else
        {
            // move first .. QQQQ
            SET.erase(body.front());
            body.pop();
            if (SET.find({i, j}) != SET.end())
                return -1;
            body.push({i, j});
            SET.insert({i, j});
        }
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

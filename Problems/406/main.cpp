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
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) -> bool
             {
            if (a[0] == b[0]) return a[1] < b[1];
            else return a[0] > b[0]; });

        vector<vector<int>> res;
        for (auto &p : people)
            res.insert(res.begin() + p[1], p);

        return res;
    }
};

// clean solution, arrange higher person first, lower person won't affect
// previous established queue.

// X X i X X X

// [5, 0]
// [5, 0], [7, 0]
// [5, 0], [7, 0], [6, 1]

// scan left to right, record higher or equal count ( check higher first )
// [5, 0], [7, 0], [6, 1]

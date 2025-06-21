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

class SnapshotArray
{
public:
    // double linked list
    unordered_map<int, vector<pair<int, int>>> snapshot;
    vector<int> cur;
    int ver;
    SnapshotArray(int length)
    {
        // 只存 diff
        cur = vector<int>(length, 0);
        ver = 0;
    }

    void set(int index, int val)
    {
        // O(1)
        if (ver > 0 && cur[index] != val)
        {
            // cow
            if (snapshot[index].empty() || snapshot[index].back().first != ver - 1)
                snapshot[index].push_back({ver - 1, cur[index]});
        }
        cur[index] = val;
    }

    int snap()
    {
        return ver++;
    }

    int get(int index, int snap_id)
    {
        // O(snap_id)
        // can be optimized to using lower_bound ( binary search )
        auto &vals = snapshot[index];

        auto it = lower_bound(vals.begin(), vals.end(), pair<int, int>{snap_id, -1});
        return it == vals.end() ? cur[index] : it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

// 存 diff
//
// set -> 有 update -> cow -> add to snapshot
// snapshot -> no op
// traverse bucket list -> O(snapshot)

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
    vector<vector<int>> snapshot;
    SnapshotArray(int length)
    {
        snapshot.push_back(vector<int>(length, 0));
    }

    void set(int index, int val)
    {
        snapshot.back()[index] = val;
    }

    int snap()
    {
        snapshot.push_back(snapshot.back());
        return snapshot.size() - 2;
    }

    int get(int index, int snap_id)
    {
        return snapshot[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

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

class RandomizedSet
{
public:
    unordered_map<int, int> MAP;
    vector<int> list;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (MAP.find(val) != MAP.end())
            return false;
        MAP[val] = list.size();
        list.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (MAP.find(val) == MAP.end())
            return false;
        list[MAP[val]] = list.back();
        MAP[list.back()] = MAP[val];
        list.pop_back();
        MAP.erase(val);
        return true;
    }

    int getRandom()
    {
        int idx = rand() % list.size();
        return list[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// 別耍白痴還想存 iterator XDD 那個是個 new 出來的東西 XDD
// 會 use after free

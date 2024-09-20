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
    string simplifyPath(string path)
    {
        vector<string> p;
        int i = 0;
        while (i != string::npos && i + 1 < path.size())
        {
            int j = path.find("/", i + 1);
            string seg = path.substr(i + 1, j - i - 1);

            if (seg == "..")
            {
                if (!p.empty())
                    p.pop_back();
            }
            else if (seg != "" && seg != ".")
                p.push_back(seg);

            i = j;
        }

        string ret = "";
        for (auto &seg : p)
        {
            ret.append("/");
            ret.append(seg);
        }

        return ret == "" ? "/" : ret;
    }
};

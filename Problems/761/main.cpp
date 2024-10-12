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
    string makeLargestSpecial(string s)
    {
        if (s.size() == 0)
            return s;

        vector<string> segs;

        int one = 0, zero = 0, last = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                one++;
            if (s[i] == '0')
                zero++;

            if (one == zero)
            {
                segs.push_back(s.substr(last, i - last + 1));
                last = i + 1;
                one = 0;
                zero = 0;
            }
        }

        if (segs.size() == 1)
        {
            return '1' + makeLargestSpecial(s.substr(1, s.size() - 2)) + '0';
        }
        else
        {
            for (int i = 0; i < segs.size(); i++)
                segs[i] = makeLargestSpecial(segs[i]);
        }

        sort(segs.begin(), segs.end(), greater<string>());
        stringstream ss;
        for (auto &seg : segs)
            ss << seg;
        return ss.str();
    }
};

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
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int n = words.size();
        vector<string> res;

        int i = 0;
        while (i < n)
        {
            int j = i + 1, len = words[i].size(), cnt = 1;
            while (j < n && len + words[j].size() + cnt <= maxWidth)
            {
                len += words[j].size();
                cnt++;
                j++;
            }

            int GAP = cnt == 1 ? maxWidth - len : (maxWidth - len) / (cnt - 1);
            int B4 = cnt == 1 ? j : (maxWidth - len) % (cnt - 1) + i;
            string tmp = "";
            if (j == n)
            {
                while (i < j)
                {
                    tmp.append(words[i]);
                    if (i + 1 != j)
                        tmp.push_back(' ');
                    i++;
                }
            }
            else
            {
                while (i < j)
                {
                    tmp.append(words[i]);
                    if (i + 1 < j)
                        tmp.append(string(GAP + int(i < B4), ' '));
                    i++;
                }
            }
            if (tmp.size() < maxWidth)
                tmp.append(string(maxWidth - tmp.size(), ' '));
            // cout << tmp << endl;
            res.push_back(tmp);
            i = j;
        }

        return res;
    }
};

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
    string countOfAtoms(string formula)
    {
        auto MAP = count(formula);

        vector<pair<string, int>> q;
        for (auto &[k, v] : *MAP)
            q.push_back({k, v});

        sort(q.begin(), q.end());

        string res = "";
        for (auto &[k, v] : q)
        {
            res.append(k);
            if (v > 1)
                res.append(to_string(v));
        }

        return res;
    }

    unordered_map<string, int> *count(string s)
    {
        int n = s.size();
        int i = 0;

        auto MAP = new unordered_map<string, int>();
        while (i < n)
        {
            char &c = s[i];

            if (isupper(c))
            {
                int j = i + 1;
                while (j < n && islower(s[j]))
                    j++;
                string name = s.substr(i, j - i);

                i = j;
                int cnt = 1;
                while (j < n && isdigit(s[j]))
                    j++;
                if (i != j)
                    cnt = stoi(s.substr(i, j - i));

                (*MAP)[name] += cnt;
                i = j;
            }
            else if (c == '(')
            {
                int cnt = 1;
                int j = i + 1;
                while (cnt > 0)
                {
                    if (s[j] == '(')
                        cnt++;
                    else if (s[j] == ')')
                        cnt--;
                    j++;
                }

                auto tmp = count(s.substr(i + 1, j - i - 2));
                i = j;
                while (j < n && isdigit(s[j]))
                    j++;
                int scale = 1;
                if (i != j)
                    scale = stoi(s.substr(i, j - i));
                for (auto &[k, v] : *tmp)
                    (*MAP)[k] += v * scale;

                delete tmp;
                i = j;
            }
        }

        return MAP;
    }
};

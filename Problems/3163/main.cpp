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
    string compressedString(string word)
    {
        stringstream ss;

        int i = 0, n = word.size();
        while (i < n)
        {
            int j = i + 1;
            while (j < n && j - i < 9 && word[j] == word[i])
                j++;

            ss << to_string(j - i) + word[i];
            i = j;
        }

        return ss.str();
    }
};

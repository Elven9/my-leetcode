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
    bool isCircularSentence(string sentence)
    {
        int n = sentence.size();
        if (sentence.front() != sentence.back())
            return false;

        int i = 0;
        while (i < n)
        {
            int pos = sentence.find(' ', i);
            if (pos == string::npos)
                break;
            if (sentence[pos - 1] != sentence[pos + 1])
                return false;

            i = pos + 1;
        }
        return true;
    }
};

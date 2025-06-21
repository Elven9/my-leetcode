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

class Codec
{
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs)
    {
        // SEP of STRING => ||
        // SEP of SEG => ,

        stringstream ss;
        for (auto &s : strs)
        {
            int i = 0, n = s.size();
            while (i < n)
            {
                int cur = i;
                while (i < n && s[i] == s[cur])
                    i++;
                ss << s[cur] << to_string(i - cur) << ",";
            }
            ss << "||";
        }
        return ss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        cout << s << endl;
        vector<string> res;
        int i = 0, n = s.size();
        while (i < n)
        {
            stringstream ss;
            do
            {
                if (s[i] == '|' && s[i + 1] == '|')
                    break;
                int cur = ++i;
                while (isdigit(s[i]))
                    i++;
                ss << string(stoi(s.substr(cur, i - cur)), s[cur - 1]);
                i++;
            } while (true);
            res.push_back(ss.str());
            i += 2;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// bandwidth efficient -> size of the message sent over the network should be as low as possibile

// -> compress first
// -> a12b2
// first simple solution
//
// it takes O(n) to encode, O(n) to decode single string

// seperator => a single character of , => with no count => seperator

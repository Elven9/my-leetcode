#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        // Naive Recursive solution
        stringstream ss;

        // Parse string
        int n = s.size(), i = 0;
        while (i < n)
        {
            // Check if next char is a digit
            if (isdigit(s[i]))
            {
                int ds = i, de = i + 1;
                while (de < n && s[de] != '[')
                    de++;
                int repeat = stoi(s.substr(ds, de - ds));

                // Extract next string
                ds = de + 1;
                de = ds + 1;
                int bc = 1;
                while (de < n && bc > 0)
                {
                    if (s[de] == '[')
                        bc++;
                    if (s[de] == ']')
                        bc--;
                    de++;
                }
                i = de;
                de--;
                string extract = decodeString(s.substr(ds, de - ds));

                // Append String
                while (repeat-- > 0)
                    ss << extract;
            }
            else
            {
                ss << s[i++];
            }
        }

        return ss.str();
    }
};

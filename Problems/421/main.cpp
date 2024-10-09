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

struct Node {
    Node *ch[2];
    Node() {
        for (int i = 0; i < 2; i++) ch[i] = nullptr;
    }
};

class Solution {
public:
    Node* root;
    int findMaximumXOR(vector<int>& N) {
        root = new Node();

        for (auto &n: N) {
            Node* cur = root;
            for (int i = 31; i >= 0; i--) {
                int idx=(n>>i)&1;
                if (!cur->ch[idx]) cur->ch[idx] = new Node();
                cur=cur->ch[idx];
            }
        }

        int res = INT_MIN;
        for (auto &n: N) {
            Node* cur = root;
            int tmp=0;
            for (int i = 31; i >= 0; i--) {
                tmp<<=1;
                int idx=(n>>i)&1;
                if (cur->ch[!idx]) {
                    cur=cur->ch[!idx];
                    tmp+=1;
                } else {
                    cur=cur->ch[idx];
                }
            }
            res=max(res, tmp);
        }

        return res;
    }
};

// O(n^2) won't works ww

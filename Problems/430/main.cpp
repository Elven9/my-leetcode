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

// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        construct(head);
        return head;
    }

    Node *construct(Node *head)
    {
        Node *cur = head, *last = head;
        while (cur)
        {
            if (cur->child)
            {
                Node *cLast = construct(cur->child);
                Node *tmp = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;
                if (tmp)
                {
                    tmp->prev = cLast;
                    cLast->next = tmp;
                }
                cur->child = nullptr;

                last = cLast;
                cur = tmp;
                continue;
            }
            last = cur;
            cur = cur->next;
        }
        return last;
    }
};

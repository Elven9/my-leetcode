#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        // Implement as Merge Sort
        // Cut half the list
        ListNode *s = head, *f = head, *prev = nullptr;
        while (f != nullptr && f->next != nullptr)
        {
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        prev->next = nullptr;

        f = sortList(head);
        s = sortList(s);

        return merge(s, f);
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode, *p = res;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if (l1 != nullptr)
        {
            p->next = l1;
        }
        else
        {
            p->next = l2;
        }

        p = res->next;
        delete res;
        return p;
    }

    void quickSort(ListNode *head)
    {
        // 26 / 30
        // Some cases when TLE, guess it is worst cases for Quicksort
        if (head->next == nullptr)
            return;
        ListNode *pivot = head->next, *small = new ListNode, *big = new ListNode;
        ListNode *cur = pivot->next, *scur = small, *bcur = big;

        while (cur != nullptr)
        {
            if (cur->val < pivot->val)
            {
                scur->next = cur;
                scur = scur->next;
            }
            else
            {
                bcur->next = cur;
                bcur = bcur->next;
            }
            cur = cur->next;
        }
        scur->next = nullptr;
        bcur->next = nullptr;
        quickSort(small);
        quickSort(big);

        // Concat
        pivot->next = big->next;
        head->next = small->next;
        cur = small->next;
        while (cur != nullptr && cur->next != nullptr)
            cur = cur->next;

        if (cur == nullptr)
        {
            head->next = pivot;
        }
        else
        {
            cur->next = pivot;
        }
        delete small, big;
    }
};

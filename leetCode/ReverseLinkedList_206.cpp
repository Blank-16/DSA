/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    // it will return head of the reversed list
    Node *reversal(Node *head)
    {
        // base case;
        if (head == NULL || head->next == NULL)
            return head;

        int smallHead = reversal(haed->next);
        head->next->next = head;
        head->next = NULL;
        return smallHead;
    }
    void reverse(Node *&head, Node *curr, Node *prev)
    {
        // base case;
        if (curr == NULL)
        {
            head = prev;
            return;
        }
        Node *forward = curr->next;
        reverse(head, forward, curr);
        curr->next = prev;
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nxt = nullptr;

        while (curr != nullptr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};
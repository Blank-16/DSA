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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode *temp = head;
        ListNode *forward = head;
        ListNode *curr = NULL;
        while(forward != NULL  && forward->next != NULL) {
            curr = temp;
            temp = temp->next;
            forward = forward->next->next;
        }
        curr->next = temp->next;
        delete temp;
        return head;
    }
};




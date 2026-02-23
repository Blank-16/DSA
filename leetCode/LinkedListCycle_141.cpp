/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        ListNode *temp = head;
        ListNode *curr = head;
        while(temp != nullptr && temp->next != nullptr) {
            curr = curr->next;
            temp = temp->next->next;
            if(temp == curr) return true;
        }
        return false;
    }
};

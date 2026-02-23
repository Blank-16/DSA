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
    int len(ListNode* head) {
        int count = 0;
        while (head != NULL) {
            head = head->next;
            count++;
        }
        return count/2;
    }
    ListNode* middleNode(ListNode* head) {
        int l = len(head);
        int c = 0;
        ListNode* temp = head;
        while (temp->next != NULL) {
            if (c == l) {
                break;
            }
            temp = temp->next;
            c++;
        }
        return temp;
    }
};


class Solution2{
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

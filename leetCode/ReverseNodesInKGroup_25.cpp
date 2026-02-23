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

// recursive solution 


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == nullptr) return nullptr;

        // Step 0: Check if at least k nodes exist
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }

        if (count < k) return head;  // do not reverse

        // Step 1: Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        count = 0;

        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 2: Recursively process remaining list
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        // Step 3: Return new head of this segment
        return prev;
    }
};



class Sol{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* curr = head;
        ListNode* prevGroupTail = nullptr;
        ListNode* newHead = nullptr;

        while (curr) {

            // Step 1: Check if k nodes exist
            ListNode* check = curr;
            int count = 0;
            while (check && count < k) {
                check = check->next;
                count++;
            }

            if (count < k) break;  // do not reverse last smaller group

            // Step 2: Reverse k nodes
            ListNode* prev = nullptr;
            ListNode* groupHead = curr;

            count = 0;
            while (curr && count < k) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                count++;
            }

            // Step 3: Connect previous group
            if (!newHead)
                newHead = prev;  // first group defines new head

            if (prevGroupTail)
                prevGroupTail->next = prev;

            // Step 4: Connect tail of reversed group
            groupHead->next = curr;

            // Move prevGroupTail
            prevGroupTail = groupHead;
        }

        return newHead ? newHead : head;
    }
};


class Sol2{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }
            if (kth == nullptr) break;

            ListNode* groupNext = kth->next;

            // Reverse group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy.next;
    }
};

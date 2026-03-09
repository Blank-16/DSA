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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode *temp = head;
        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        temp = head;
        int i = 0;
        while(temp) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};


class Solution {
public:

    // Function to find middle of linked list
    ListNode* findMiddleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Move slow by 1 step and fast by 2 steps
        // When fast reaches end, slow will be at middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // middle node
    }

    // Function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        // Dummy node helps simplify merging logic
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curNode = dummyNode;

        // Compare nodes and attach smaller one
        while (head1 && head2) {
            if (head1->val < head2->val) {
                curNode->next = head1;
                head1 = head1->next;
            } else {
                curNode->next = head2;
                head2 = head2->next;
            }
            curNode = curNode->next;
        }

        // Attach remaining nodes (if any)
        if (head1)
            curNode->next = head1;
        else
            curNode->next = head2;

        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {

        // Base case
        if (!head || !head->next)
            return head;

        // Step 1: Find middle
        ListNode* middleNode = findMiddleNode(head);

        // Step 2: Split list into two halves
        ListNode* rightHead = middleNode->next;
        middleNode->next = NULL;

        // Step 3: Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        // Step 4: Merge sorted halves
        return mergeTwoLists(left, right);
    }
};


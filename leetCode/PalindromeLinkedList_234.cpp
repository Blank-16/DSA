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
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        ListNode *temp = head;
        while(temp != nullptr) {
            a.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> b = a;
        reverse(b.begin(), b.end());
        return a == b;
    }
};


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
class Solution2{
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head;

        // find middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode *prev = nullptr, *temp;
        while (slow) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // compare halves
        ListNode *first = head;
        ListNode *second = prev;

        while (second) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};

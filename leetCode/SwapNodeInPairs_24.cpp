class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = head->next;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;

            second->next = curr;
            curr->next = nextPair;

            if (prev) prev->next = second;

            prev = curr;
            curr = nextPair;
        }

        return newHead;
    }
};



// recursive solution

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* newHead = head->next;

        head->next = swapPairs(newHead->next);
        newHead->next = head;

        return newHead;
    }
};

// iterative solution 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while(prev->next && prev->next->next) {
            ListNode* a = prev->next;
            ListNode* b = a->next;

            a->next = b->next;
            b->next = a;
            prev->next = b;

            prev = a;
        }

        return dummy.next;
    }
};


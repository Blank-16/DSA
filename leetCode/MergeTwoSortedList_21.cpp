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
    void iah(ListNode*& head, int value) {
        ListNode* temp = new ListNode(value);
        temp->next = head;
        head = temp;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;

        if(list1 == nullptr && list2 == nullptr)  return head;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        vector<int> arr;
        while (list1 != nullptr) {
            arr.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            arr.push_back(list2->val);
            list2 = list2->next;
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        for (auto n : arr) {
            iah(head, n);
        }
        return head;
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while(l1 != nullptr && l2 != nullptr){ 
            if(l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if(l1 !=  nullptr) {
            tail->next = l1;
        }
        else {
            tail->next = l2;
        }
        return dummy.next;
    }
};

/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        if (!head) return head;

        unordered_set<int> seen;
        Node* temp = head;
        seen.insert(temp->data);

        while (temp->next) {
            if (seen.count(temp->next->data)) {
                temp->next = temp->next->next;
            } else {
                seen.insert(temp->next->data);
                temp = temp->next;
            }
        }

        return head;
    }
};

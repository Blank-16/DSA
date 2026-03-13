
// recursive appraoch

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev =curr;
                curr->child = NULL;
                while(curr->next !=NULL){
                    curr = curr->next;
                }
                if(next != NULL){
                    curr->next = next;
                    next->prev = curr;
                }

            }
            curr = curr->next;

        }
        return head;

    }
};


// normal appraoch

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *temp = head;
        while(temp) {
            if(temp->child != nullptr){ 
                Node *tail = temp->child;
                while(tail->next != nullptr) {
                    tail = tail->next;
                }
                tail->next = temp->next;
                if(temp->next != nullptr) temp->next->prev = tail;
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = nullptr;
            }
            temp = temp->next;
        }
        return head;
        
    }
};

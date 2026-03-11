/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node *newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        // crate a clone list;
        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;

        Node *temp = head;
        while(temp) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        //step 2 = create an unordered map;
        unordered_map<Node*, Node*> oldToNew;
        Node *originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode && cloneNode) {
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // arranging random pointers;
        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode) {
            cloneNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};


// for constant space approach;
/*
 * we can change links instead of using a different map to store the random pointers;
 * clone list in between the og list 
 * random pointers then get copied to cloned list 
 */


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution2{
public:
    void insertAtTail(Node*& head, Node*& tail, int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        // create clone list

        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;

        Node* temp = head;
        while (temp) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // clone nodes add in between og list

        Node* ogNode = head;
        Node* cloneNode = cloneHead;

        while (ogNode && cloneNode) {
            Node* next = ogNode->next;
            ogNode->next = cloneNode;
            ogNode = next;

            next = cloneNode->next;
            cloneNode->next = ogNode;
            cloneNode = next;
        }

        // random pointers copy

        temp = head;
        while (temp) {
            if (temp->next != nullptr) {
                temp->next->random =
                    temp->random ? temp->random->next : temp->random;
            }
            temp = temp->next->next;
        }

        // revert changes of s-2

        ogNode = head;
        cloneNode = cloneHead;
        while (ogNode && cloneNode) {
            ogNode->next = cloneNode->next;
            ogNode = ogNode->next;

            if (ogNode != nullptr) {
                cloneNode->next = ogNode->next;
            }
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};



class Sol3{
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        
       
        unordered_map<Node*, Node*> oldToNew;
        
     
        Node* curr = head;
        while (curr != nullptr) {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
       
        curr = head;
        while (curr != nullptr) {
            Node* copy = oldToNew[curr];
            
            
            if (curr->next != nullptr) {
                copy->next = oldToNew[curr->next];
            }
            
            
            if (curr->random != nullptr) {
                copy->random = oldToNew[curr->random];
            }
            
            curr = curr->next;
        }
        
        
        return oldToNew[head];
    }
};

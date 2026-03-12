
class Node {
  public:
    int data;
    Node *next;
    Node(int data) {
      this->data = data;
      this->next = nullptr;
    }
}

Node *findMid(Node *head){
  Node *slow = head, *fast = head->next;

  while(fast && fast->next){
    slow = slow->next; 
    fast = fast->next->next;
  }
  return slow;
}

Node *merge(Node *left, Node *right) {
  
  if(left == nullptr) return right;
  if(right == nullptr) return left;

  Node *ans = new Node(-1); // dummy node
  Node *temp = ans;

  while(left != nullptr && right != nullptr) {
    if(left->data < right->data) {
      temp->next = left;
      temp = left;
      left = left->next;
    } else {
        temp->next = right;
        temp = right;
        right = right->next;
    }
  }
  
  while(left != nullptr) {
      temp->next = left;
      temp = left;
      left = left->next;
  }

  while(right != nullptr) {
      temp->next = right;
      temp = right;
      right = right->next;
  }

  Node *res = ans->next;
  delete ans;
  return res;
}

Node *mergeSort(Node *head) {
  // base case
  if(head == nullptr || head->next == nullptr) {
    return head;
  }

  // break linkedlist into 2 halves after finding mid;
  Node *mid = findMid(head);

  Node *left = head;
  Node *right = mid->next;
  mid->next = nullptr;

  // recursive calls to sort both halves;
  left = mergeSort(left);
  right = mergeSort(right);

  // merge both left and right halves;
  Node *result = merge(left, right);

  return result;
}

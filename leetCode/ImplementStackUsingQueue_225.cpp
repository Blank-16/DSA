#include <iostream>
#include <queue>

using namespace std;

/**
 * https://leetcode.com/problems/implement-stack-using-queues/
 * 
 * This implementation uses a SINGLE queue.
 * To maintain LIFO order, every time we push an element, we rotate the queue 
 * so that the newly added element moves to the front.
 * 
 * Time Complexity:
 *   Push: O(N)
 *   Pop: O(1)
 *   Top: O(1)
 *   Empty: O(1)
 * 
 * Space Complexity: O(N)
 */

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        q.push(x);
        
        // Rotate the queue n times to bring the new element to the front
        for(int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << "Top: " << obj->top() << endl;   // Should be 2
    cout << "Pop: " << obj->pop() << endl;   // Should be 2
    cout << "Empty: " << (obj->empty() ? "Yes" : "No") << endl; // Should be No
    
    delete obj;
    return 0;
}

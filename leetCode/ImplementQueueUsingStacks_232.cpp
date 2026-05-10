#include <iostream>
#include <stack>

using namespace std;

/**
 * https://leetcode.com/problems/implement-queue-using-stacks/
 * 
 * Time Complexity:
 *   Push: O(1)
 *   Pop: Amortized O(1)
 *   Peek: Amortized O(1)
 *   Empty: O(1)
 * 
 * Space Complexity: O(N) to store elements.
 */

class MyQueue {
private:
    stack<int> s1; // For pushing
    stack<int> s2; // For popping/peeking

    // Helper function to move elements from s1 to s2
    // Elements are moved only when s2 is empty, which ensures FIFO order
    void shiftStacks() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        shiftStacks();
        if (s2.empty()) return -1;
        int val = s2.top();
        s2.pop();
        return val;
    }

    /** Get the front element. */
    int peek() {
        shiftStacks();
        if (s2.empty()) return -1;
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout << "Peek: " << obj->peek() << endl; // Should be 1
    cout << "Pop: " << obj->pop() << endl;   // Should be 1
    cout << "Empty: " << (obj->empty() ? "Yes" : "No") << endl; // Should be No
    
    delete obj;
    return 0;
}

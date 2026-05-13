// using stacks

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int> s;

        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }

        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
    }
};


/*
 * using recursion
 */

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        if (q.empty())
            return;

        int x = q.front();
        q.pop();

        reverseQueue(q);

        q.push(x);
    }
};

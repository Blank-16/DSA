
class Solution {
	public:
	queue<int> reverseFirstK(queue<int> q, int k) {
		// code here
		if (k > q.size())
			return q;
		queue<int> qu;
		stack<int> s;
		int n = 0;
		while (n < k) {
			s.push(q.front());
			q.pop();
			n++;
		}
		while (!s.empty()) {
			qu.push(s.top());
			s.pop();
		}
		while (!q.empty()) {
			qu.push(q.front());
			q.pop();
		}
		return qu;
	}
};



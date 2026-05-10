#include <bits/stdc++.h>
using namespace std;

int mini = INT_MAX; // global minimum

void push(stack<int>& s, int data) {
	if (s.empty()) {
		s.push(data);
		mini = data;
	} else {
		if (data < mini) {
			// encode previous minimum
			s.push(2*data - mini);
			mini = data;
		} else {
			s.push(data);
		}
	}
}

int pop(stack<int>& s) {
	if (s.empty())
		return - 1;
	
	int top = s.top();
	s.pop();
	
	if (top < mini) {
		// top was encoded, decode previous min
		int prevMin = mini;
		mini = 2*mini - top;
		return prevMin;
	} else {
		return top;
	}
}

int getMin(stack<int>& s) {
	if (s.empty())
		return - 1;
	return mini;
}

bool isEmpty(stack<int>& s) {
	return s.empty();
}

bool isFull(stack<int>& s, int n) {
	return s.size() == n;
}


// another sol


#include <bits/stdc++.h>
using namespace std;

stack<int> minStack;

void push(stack<int>& s, int a) {
    s.push(a);
    if (minStack.empty() || a <= minStack.top()) {
        minStack.push(a);
    }
}

int pop(stack<int>& s) {
    if (s.empty()) return -1; // stack underflow
    int topElement = s.top();
    s.pop();
    if (!minStack.empty() && topElement == minStack.top()) {
        minStack.pop();
    }
    return topElement;
}

// Return current minimum
int getMin(stack<int>& s) {
    if (minStack.empty()) return -1; // stack is empty
    return minStack.top();
}

bool isEmpty(stack<int>& s) {
    return s.empty();
}

bool isFull(stack<int>& s, int n) {
    return s.size() >= n;
}

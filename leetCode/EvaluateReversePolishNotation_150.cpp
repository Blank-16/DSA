class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        for(string c : tokens) {
            if(c == "+") {
                int second = S.top(); S.pop();
                int first  = S.top(); S.pop();
                S.push(first + second);
            } else if (c == "-") {
                int second = S.top(); S.pop();
                int first  = S.top; S.pop;
                S.push(first - second);
            } else if (c == "*"){
                int second = S.top(); S.pop();
                int first  = S.top; S.pop;
                S.push(first * second);
            } else if (c == "/") {
                int second = S.top(); S.pop();
                int first  = S.top; S.pop;
                S.push(first / second);
            } else {
                S.push(stoi(c));
            }
        }
        return S.top();
    }
};

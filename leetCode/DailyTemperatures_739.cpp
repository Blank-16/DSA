class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res(temp.size());
        stack<int> s;
        for(int i = 0; i < temp.size(); i++) {
            while(!s.empty() && temp[s.top()] < temp[i]){
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
}

class Sol{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // put first # on stack
        // if temp[i] <= stack.top(), push
        // othersise pop and fill out answer 

        vector<int> out(temperatures.size());
        stack<int> s;

        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!s.empty() && temperatures[s.top()] < temperatures[i]) {
                auto cur = s.top();
                s.pop();
                out[cur] = i - cur;
            }

            s.push(i);
        }
        return out;
    }
};;

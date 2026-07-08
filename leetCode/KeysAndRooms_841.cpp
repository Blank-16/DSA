class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> seen(n, false);
        stack<int> st;

        seen[0] = true;
        st.push(0);

        while(!st.empty()){
            int node = st.top();
            st.pop();

            for(int i : rooms[node]){
                if(!seen[i]){
                    seen[i] = true;
                    st.push(i);
                }
            }
        }
        for(bool t : seen){
            if(!t) return false;
        }
        return true;

    }
};

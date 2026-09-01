class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int asteroid : asteroids) {
            if(asteroid > 0) {
                st.push(asteroid);
                continue;
            }
            while(!st.empty() && st.top() > 0 && st.top() < abs(asteroid))
                st.pop();
            if(st.empty())
                st.push(asteroid);
            else if(st.top() == abs(asteroid))
                st.pop();
            else if(st.top() < 0)
                st.push(asteroid);
        }
        int n = st.size();
        vector<int> ans(n);
        while(n--) {
            int val = st.top();
            st.pop();
            ans[n] = val;
        }
        return ans;
    }
};
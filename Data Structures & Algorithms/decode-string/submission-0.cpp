class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(char ch : s) {
            if(ch != ']') {
                st.push(string(1, ch));
            }
            else {
                string str = "";
                while(!st.empty() && st.top() != "[") {
                    str = st.top() + str;
                    st.pop();
                }
                st.pop();
                string k = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    k = st.top() + k;
                    st.pop();
                }
                int cnt = stoi(k);
                string repeatedStr = "";
                while(cnt--) {
                    repeatedStr += str;
                }
                st.push(repeatedStr);
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
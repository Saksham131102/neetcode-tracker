class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(const char &ch : s) {
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else {
                if(ch == ')') {
                    if(st.empty())
                        return false;
                    if(st.top() != '(')
                        return false;
                    st.pop();
                }
                if(ch == ']') {
                    if(st.empty())
                        return false;
                    if(st.top() != '[')
                        return false;
                    st.pop();
                }
                if(ch == '}') {
                    if(st.empty())
                        return false;
                    if(st.top() != '{')
                        return false;
                    st.pop();
                }
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};

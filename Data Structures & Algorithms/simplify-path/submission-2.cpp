class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        path.push_back('/');
        int n = path.size();
        string str = "";
        for(int i=1;i<n;i++) {
            if(path[i] == '/') {
                if(str == "" || str == ".") {
                    str = "";
                    continue;
                }
                if(str == "..") {
                    if(!st.empty())
                        st.pop();
                    str = "";
                    continue;
                }
                st.push(str);
                str = "";
            }
            else {
                str.push_back(path[i]);
            }
        }
        string ans = "";
        if(st.empty())
            return "/";
        while(!st.empty()) {
            str = st.top();
            st.pop();
            ans = "/" + str + ans;
        }
        return ans;
    }
};
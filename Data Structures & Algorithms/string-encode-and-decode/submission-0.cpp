class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(const string &str : strs) {
            string len = to_string(str.size());
            ans += (len + "#" + str);
        }
        cout << ans << endl;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp;
        int len = 0;
        for(int i=0;i<s.size();i++) {
            if('0' <= s[i] && s[i] <= '9') {
                len = len * 10 + (s[i] - '0');
            }
            if(s[i] == '#') {
                int j;
                for(j=i+1;j<i+1+len;j++) {
                    temp.push_back(s[j]);
                }
                ans.push_back(temp);
                temp.clear();
                i = j - 1;
                len = 0;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<strs.size();i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            mp[str].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it : mp) {
            vector<string> temp;
            vector<string> t = it.second;
            for(int i=0;i<t.size();i++)
                temp.push_back(t[i]);
            ans.push_back(temp);
        }
        return ans;
    }
};

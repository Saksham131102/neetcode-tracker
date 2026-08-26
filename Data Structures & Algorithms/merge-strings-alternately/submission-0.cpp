class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int pointer1 = 0, pointer2 = 0;
        int n1 = word1.size(), n2 = word2.size();
        while(pointer1 < n1 && pointer2 < n2) {
            ans.push_back(word1[pointer1]);
            ans.push_back(word2[pointer2]);
            pointer1++;
            pointer2++;
        }
        while(pointer1 < n1) {
            ans.push_back(word1[pointer1]);
            pointer1++;
        }
        while(pointer2 < n2) {
            ans.push_back(word2[pointer2]);
            pointer2++;
        }
        return ans;
    }
};
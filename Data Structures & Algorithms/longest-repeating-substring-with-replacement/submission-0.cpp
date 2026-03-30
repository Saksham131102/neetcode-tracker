class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxSize = 0;
        for(char ch='A';ch<='Z';ch++) {
            int op = k;
            int left = 0, right = 0;
            while(right < n) {
                if(s[right] != ch) {
                    if(op == 0) {
                        while(s[left] == ch)
                            left++;
                        left++;
                    }
                    else {
                        op--;
                    }
                }
                maxSize = max(maxSize, right - left + 1);
                right++;
            }
        }
        return maxSize;
    }
};

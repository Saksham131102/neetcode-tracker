class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(char ch : s) {
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
                str.push_back(ch);
        }
        for(char &ch : str)
            ch = tolower(ch);
        int left  = 0;
        int right = str.size()-1;
        while(left < right) {
            if(str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

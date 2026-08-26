class Solution {
private:
    bool solve(int left, int right, int count, string &s, int n) {
        // base case
        if(left >= right)
            return true;
        // recursive relation
        if(s[left] == s[right])
            return solve(left+1, right-1, count, s, n);
        else {
            if(count == 0)
                return false;
            bool pos1 = solve(left+1, right, count - 1, s, n);
            bool pos2 = solve(left, right-1, count - 1, s, n);
            return pos1 || pos2;
        }
    }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        return solve(l, r, 1, s, n);
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        for(const int &num : nums)
            st.insert(num);
        int val = 1;
        while(st.count(val))
            val++;
        return val;
    }
};
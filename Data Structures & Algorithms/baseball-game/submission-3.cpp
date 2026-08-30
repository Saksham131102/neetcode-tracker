class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for(string operation : operations) {
            if(operation == "C")
                ans.pop_back();
            else if(operation == "D")
                ans.push_back(ans.back() * 2);
            else if(operation == "+") {
                int n = ans.size();
                ans.push_back(ans[n-1] + ans[n-2]);
            }
            else
                ans.push_back(stoi(operation));
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};
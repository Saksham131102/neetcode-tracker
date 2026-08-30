class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n = operations.size();
        int sum = 0;
        for(string operation : operations) {
            if(operation == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                sum += (a + b);
                st.push(a);
                st.push(a+b);
            }
            else if(operation == "D") {
                int a = st.top();
                st.push(a * 2);
                sum += (a*2);
            }
            else if(operation == "C") {
                int a = st.top();
                st.pop();
                sum -= a;
            }
            else {
                int a = stoi(operation);
                sum += a;
                st.push(a);
            }
            if(st.empty())
                cout << "empty" << endl;
            else
                cout << st.top() << endl;
        }
        return sum;
    }
};
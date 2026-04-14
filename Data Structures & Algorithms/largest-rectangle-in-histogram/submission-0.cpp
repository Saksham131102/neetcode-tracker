class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        vector<int> leftPrefix(n), rightPrefix(n);
        for(int i=0;i<n;i++) {
            int height = heights[i];
            while(!st.empty() && heights[st.top()] >= height)
                st.pop();
            if(st.empty())
                leftPrefix[i] = -1;
            else
                leftPrefix[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--) {
            int height = heights[i];
            while(!st.empty() && heights[st.top()] >= height)
                st.pop();
            if(st.empty())
                rightPrefix[i] = n;
            else
                rightPrefix[i] = st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++) {
            int height = heights[i];
            maxArea = max(maxArea, height * (rightPrefix[i] - leftPrefix[i] - 1));
        }

        return maxArea;
    }
};

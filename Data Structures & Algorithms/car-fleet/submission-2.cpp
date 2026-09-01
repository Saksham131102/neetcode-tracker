class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int fleetCnt = 0;
        int n = speed.size();
        for(int i=0;i<n;i++)
            cars.push_back({position[i], speed[i]});
        sort(cars.begin(), cars.end());
        stack<double> st;
        for(int i=n-1;i>=0;i--) {
            double time = (target - cars[i].first)*1.0 / cars[i].second*1.0;
            while(!st.empty() && st.top() < time)
                st.pop();
            if(st.empty())
                fleetCnt++;
            st.push(time);
        }
        return fleetCnt;
    }
};

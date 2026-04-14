class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleets = 0;
        int n = position.size();
        vector<pair<int, int>> cars;
        for(int i=0;i<position.size();i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        double time = (target - cars[n-1].first) * 1.0 / cars[n-1].second * 1.0;
        for(int i=n-2;i>=0;i--) {
            int pos = cars[i].first;
            int sp = cars[i].second;
            double t = (target - pos) * 1.0 / sp * 1.0;
            if(t > time) {
                fleets++;
                time = t;
            }
        }
        return fleets+1;
    }
};

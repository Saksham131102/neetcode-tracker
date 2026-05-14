class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())
            return "";
        vector<pair<string, int>> &temp = mp[key];
        int ans = -1;
        int left = 0, right = temp.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(temp[mid].second == timestamp)
                return temp[mid].first;
            if(temp[mid].second <= timestamp) {
                ans = mid;
                left = mid + 1;
            }
            if(temp[mid].second > timestamp)
                right = mid - 1;
        }
        if(ans == -1)
            return "";
        return temp[ans].first;
    }
};

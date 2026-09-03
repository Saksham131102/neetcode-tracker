class FreqStack {
private:
    unordered_map<int, int> mp;
    priority_queue<vector<int>> pq;
    int idx;
public:
    FreqStack() {
        idx = 0;
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val], idx++, val});
    }
    
    int pop() {
        auto top = pq.top();
        pq.pop();
        int val = top[2];
        mp[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
class FreqStack {
private:
    unordered_map<int, int> mp;
    unordered_map<int, stack<int>> stacks;
    int maxCnt;
public:
    FreqStack() {
        maxCnt = 0;
    }
    
    void push(int val) {
        mp[val]++;
        int cnt = mp[val];
        if(cnt > maxCnt)
            maxCnt = cnt;
        stacks[cnt].push(val);
    }
    
    int pop() {
        int val = stacks[maxCnt].top();
        stacks[maxCnt].pop();
        mp[val]--;
        if(stacks[maxCnt].empty())
            maxCnt--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
class StockSpanner {
private:
    int cnt;
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        cnt = 1;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price)
            st.pop();
        int span = (st.empty() ? cnt : cnt - st.top().second);
        st.push({price, cnt++});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
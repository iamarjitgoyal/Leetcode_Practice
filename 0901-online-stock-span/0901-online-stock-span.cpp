class StockSpanner {
public:
    vector<int> arr;
    int cur=0;
    stack<pair<int,int>> st;
    StockSpanner() {
        arr.clear();
        stack<pair<int,int>> ss;
        st=ss;
        cur=0;
    }
    int next(int price) {
        int res=0;
        while(!st.empty() && price>=st.top().first)
        {
            res+=arr[st.top().second];
            st.pop();
        }
        st.push({price,cur});
        cur++;
        arr.push_back(res+1);
        return res+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
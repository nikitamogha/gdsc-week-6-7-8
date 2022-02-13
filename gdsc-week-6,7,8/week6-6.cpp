class StockSpanner {
public:
    stack<int>s;
    vector<int>p;
    int i=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        p.push_back(price);
        int res;
        while(!s.empty() && price >=p[s.top()])
            s.pop();
        if(s.empty())
            res=i+1;
        else 
            res=i-s.top();
        
        s.push(i++);
        return res;
      
        
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
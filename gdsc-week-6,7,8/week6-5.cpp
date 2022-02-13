class MinStack {
public:
    stack<int>s;
    stack<int>help;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(help.size()==0 || val<=help.top())
            help.push(val);
    }
    
    void pop() {
        if(s.size()==0)
            return ;
        int ans=s.top();
         s.pop();
        if(ans==help.top())
            help.pop();
        
    }
    
    int top() {
        if(s.size()==0)
            return -1;
        return s.top();
    }
    
    int getMin() {
        if(help.size()==0)
            return -1;
        return help.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
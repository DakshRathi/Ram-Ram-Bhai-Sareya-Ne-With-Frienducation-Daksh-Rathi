class MinStack {
    vector<int> st;      
    vector<int> min_val;   
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        if (min_val.empty() || val <= min_val.back()) min_val.push_back(val);
    }
    
    void pop()
    {
        if (st.back() == min_val.back()) min_val.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.empty() ? -1 : st.back();
    }
    
    int getMin() {
        return min_val.empty() ? -1 : min_val.back();
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
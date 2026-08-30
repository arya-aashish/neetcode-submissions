class MinStack {
    vector<int> st;
    vector<int> minm;
    int size = 0;
    
public:
    MinStack() {  
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push_back(val);
            minm.push_back(val);
        } else {
            st.push_back(val);
            minm.push_back(min(minm[size-1], val));
        }
        size++;
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop_back();
            minm.pop_back();
            size--;
        }
    }
    
    int top() {
        return st[size-1];        
    }
    
    int getMin() {
        return minm[size-1];
    }
};
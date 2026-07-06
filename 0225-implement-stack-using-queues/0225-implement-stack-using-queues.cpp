class MyStack {
private:
    int arr[1000];
    int t;
public:
    MyStack() {
        t = -1;
    }
    
    void push(int x) {
        arr[++t] = x;
    }
    
    int pop() {
        if (t == -1) {
            return -1;
        }
        return arr[t--];
    }
    
    int top() {
        if (t == -1) {
            return -1;
        }
        return arr[t];
    }
    
    bool empty() {
        return t == -1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
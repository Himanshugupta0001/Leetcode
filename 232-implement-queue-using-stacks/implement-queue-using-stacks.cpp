class MyQueue {
public:
stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st1.size() == 0){
            st1.push(x);
            return;
        }
        else{
            while(st1.size() > 0){
                st2.push(st1.top());
                st1.pop();
            }
            st1.push(x);
            while(st2.size() > 0){
                st1.push(st2.top());
                st2.pop();
            }
        }
    }
    
    int pop() {
        int x = st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        if(st1.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
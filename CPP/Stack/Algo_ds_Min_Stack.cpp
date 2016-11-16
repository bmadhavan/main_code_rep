Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Solution: Have 2 stacks within the MinStack class. One adding the current value and one that maintains the min at any time. 
Complexity:  O(1)
Memory : 2n

class MinStack {
private:
    stack<int> st; 
    stack<int> min;
public:
    void push(int x) {
        st.push(x);
        if ( min.empty() || min.top() > x ) min.push(x);
        else min.push( min.top() );
    }
    
    void pop() {
        st.pop();
        min.pop();
    }
    
    int top() {
        return (st.top());
    }
    
    int getMin() {
        return (min.top());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
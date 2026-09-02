class MinStack {
    private Stack<Integer> st;
    private Stack<Integer> stMin;

    public MinStack() {
        st = new Stack<>();
        stMin = new Stack<>();
    }
    
    public void push(int val) {
        st.push(val);
        if(stMin.empty()){
            stMin.push(val);
        }else{
            stMin.push(Math.min(val, stMin.peek()));
        }
    }
    
    public void pop() {
        st.pop();
        stMin.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return stMin.peek();
    }
}

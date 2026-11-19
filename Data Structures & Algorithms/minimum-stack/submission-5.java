class MinStack {
 Stack<Integer> stack;
  Stack<Integer> min;
    public MinStack() {
        stack = new Stack<>();
        min = new Stack<>();
    }
    
    public void push(int val) {
        if(!min.isEmpty()){
            if(min.peek() > val) min.push(val);
            else min.push(min.peek());
        }
        else min.push(val);
        stack.push(val);
        
    }
    
    public void pop() {
        if(!stack.isEmpty()){
        stack.pop();
        min.pop();
        }

    }
    
    public int top() {
        if(!stack.isEmpty()){
            return stack.peek();
        }
        return 0;
    }
    
    public int getMin() {
        return min.peek();
    }
}

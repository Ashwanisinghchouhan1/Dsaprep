class MyQueue {
    stack<int> inputStack;
    stack<int> outputStack;

public:
    MyQueue() {}
    
    void push(int x) {
        inputStack.push(x);
    }
    
    int pop() {
        // Ensure outputStack has the front elements ready
        peek();
        int topElement = outputStack.top();
        outputStack.pop();
        return topElement;
    }
    
    int peek() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        return outputStack.top();
    }
    
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
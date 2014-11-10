class MinStack {
public:
    void push(int x) {
        s.push(x);
        if (mins.empty() || x<=mins.top()) {
            mins.push(x);
        }
    }

    void pop() {
        int temp = s.top();
        s.pop();
        if (temp == mins.top()) {
            mins.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return mins.top();
    }

private:
    stack<int> s;
    stack<int> mins;
};
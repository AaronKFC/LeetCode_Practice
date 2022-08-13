/*
    Design stack that supports push, pop, top, & retriving min element
    
    2 stacks, 1 normal & 1 monotonic decr, only push if lower than top
    
    Time: O(1)
    Space: O(n)
*/

// Solution1 (NeetCode) a little bit faster
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        
        if (minStk.empty() || val < minStk.top().first) {
            minStk.push({val, 1});
        } else if (val == minStk.top().first) {
            minStk.top().second++;
        }
    }
    
    void pop() {
        if (stk.top() == minStk.top().first) {
            minStk.top().second--;
            if (minStk.top().second == 0) {
                minStk.pop();
            }
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top().first;
    }
private:
    stack<int> stk;
    stack<pair<int, int>> minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Solution2 (My implementation)
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if (minstk.empty() || val < minstk.top()) {
            minstk.push(val);
        // } else if (val >= minstk.top()) {
        } else {
            minstk.push(minstk.top());
        }
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
private:
    stack<int> stk;
    stack<int> minstk;
};



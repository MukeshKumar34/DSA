class MinStack {
public:
    #define MAX 10000

    int stack[MAX];
    int minStack[MAX];
    int topIndex;
    int minTop;

    MinStack() {
        topIndex = -1;
        minTop = -1;
    }

    void push(int val) {
        if (topIndex == MAX - 1) {
            return;
        }

        stack[++topIndex] = val;

        if (minTop == -1 || val <= minStack[minTop]) {
            minStack[++minTop] = val;
        }
    }

    void pop() {
        if (topIndex == -1) {
            return;
        }

        if (stack[topIndex] == minStack[minTop]) {
            minTop--;
        }
        topIndex--;
    }

    int top() {
        if (topIndex == -1) {
            return -1;
        }
        return stack[topIndex];
    }

    int getMin() {
        if (minTop == -1) {
            return -1;
        }
        return minStack[minTop];
    }
};

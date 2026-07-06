class MyQueue {
private:
    int arr[1000];
    int start;
    int end;

public:
    MyQueue() {
        start = -1;
        end = -1;
    }

    void push(int x) {
        if (start == -1)
            start = 0;

        arr[++end] = x;
    }

    int pop() {
        if (start == -1)
            return -1;

        int val = arr[start];

        if (start == end)
            start = end = -1;
        else
            start++;

        return val;
    }

    int peek() {
        if (start == -1)
            return -1;

        return arr[start];
    }

    bool empty() {
        return start == -1;
    }
};
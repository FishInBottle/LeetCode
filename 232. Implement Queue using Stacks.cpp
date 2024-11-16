/*
Implement a first in first out (FIFO) queue using only two stacks. 
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
+ void push(int x) Pushes element x to the back of the queue.
+ int pop() Removes the element from the front of the queue and returns it.
+ int peek() Returns the element at the front of the queue.
+ boolean empty() Returns true if the queue is empty, false otherwise.

Notes:
You must use only standard operations of a stack, 
which means only push to top, peek/pop from top, size, and is empty operations are valid.

Depending on your language, the stack may not be supported natively. 
You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

Constraints:
1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
 
Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

https://leetcode.com/problems/implement-queue-using-stacks/description/
 */

#include <iostream> // std::cout
#include <stack>    // std::stack

class MyQueue {
private:
    std::stack<int> pushStack;  //Called stack1, top is the last data
    std::stack<int> popStack;   //Called stack2, top is the first data
    int dataLocation = 0;       //Indicate in which stack the data is currently placed

    /* Move data to specified stack */
    void shiftData(int stackId) {
        if (stackId != dataLocation) {
            if (0 == stackId) {
                while (false == popStack.empty()) {
                    pushStack.push(popStack.top());
                    popStack.pop();
                }
                dataLocation = 0;
            } else {
                while (false == pushStack.empty()) {
                    popStack.push(pushStack.top());
                    pushStack.pop();
                }
                dataLocation = 1;
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        shiftData(0);
        pushStack.push(x);
    }

    int pop() {
        shiftData(1);
        if (false == popStack.empty()) {
            int value = popStack.top();
            popStack.pop();
            return value;
        } else
            return -1;
    }

    int peek() {
        shiftData(1);
        if (false == popStack.empty())
            return popStack.top();
        else
            return -1;
    }

    bool empty() {
        if (0 == dataLocation)
            return pushStack.empty();
        else
            return popStack.empty();
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
/*

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

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


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */

*/


// Method 1: Push heavy - Pushing into Queue takes O(N) time.

class MyQueue {
    Stack<Integer> s1 = new Stack<>();
    Stack<Integer> s2 = new Stack<>();
    public MyQueue() { 
    }
    
    public void push(int x) {
        while(!s1.empty())  s2.push(s1.pop());
        s1.push(x);
        while(!s2.empty()) s1.push(s2.pop());
    }
    
    public int pop() {
        return s1.pop();
    }
    
    public int peek() {
        return s1.peek();
    }
    
    public boolean empty() {
       return s1.empty();
    }
}


// Method 2: Pop heavy - Popping an element out of queue takes O(N) time

class MyQueue {
    Stack<Integer> s1 = new Stack<>();
    Stack<Integer> s2 = new Stack<>();
    int front = Integer.MAX_VALUE;
    public MyQueue() {
    }
    
    public void push(int x) {
        if(front == Integer.MAX_VALUE) front = x;
        s1.push(x);
    }
    
    public int pop() {
        while(!s1.empty()) s2.push(s1.pop());
        int x = s2.peek();
        s2.pop();
        if(!s2.empty()) front = s2.peek();
        else front = Integer.MAX_VALUE;
        while(!s2.empty()) s1.push(s2.pop());
        return x;
    }
    
    public int peek() {
        return front;
    }
    
    public boolean empty() {
       return s1.empty();
    }
}
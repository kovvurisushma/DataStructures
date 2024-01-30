/*
LeetCode 232 Problem

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

====================================================================================================================================================================================================================================

// Method 1: Push heavy - Pushing into Queue takes O(N) time.

/* Approach

     Push()
*  - Before Pushing an element to a stack first pop all the existing elements from the first stack and push them into second stack
*  - Now push the current element to the first stack, here we are push the latest element to the last
*  - Now pop the remaining elements from the second stack and push them to the first stack 
     so that the first pushed element will always be on the top and the latest pushed element on the bottom.

   Time Complexity: O(N + N) - for Push

   Pop(): 
*  - since the first entered element will always be on the top of the stack, pop the fist element from the first stack. 
   Time Complexity: O(1) - for Pop

   Peek():
* - similar to the pop, since the first entered element will always be on the top of the stack, return the fist element from the stack.
   Time Complexity: O(1) - for Peek
*/

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

/*
   Approach

   Push()
* - Here while pushing we will push directly on to the top of the stack.
    Time Complexity: O(1)

    Pop():
* - Similar to the above approach, but here the first entered element will be at the bottom of the stack so to remove that element,
  - we have to pop all the elements from this stack and push them to the second stack.
  - now pop the top element from the second stack and return it.
  - now after that again push all the elements from second stack to the first stack.
  Time Complexity: O(N + N)

  Peek():
* - Here if we don't store the latest element in a seperate variable then for Peek also we need to follow the same pop() kind of functionality.
  - so to not to increase complexity we will use one variable that always contains the front value of the Queue.
  - to do that, first we have to initialise the front with a value (which wont be present in the queue) most likely something like Integer.MAX_VALUE or Integer.MIN_VALUE
  - now before pushing element to stack, check if the front value is still initialised value i.e., Integer.MAX_VALUE
    - if it is equal to Integer.MAX_VALUE, that means the front has not assigned any value. and the current element is the first element of Queue. so make front = current element
    - if it is not equal dont do anything as there are already elements in the queue and front variable is pointing to first element.
  - and also after popping of element we have to update front value of the queue as the first element is getting popped.
  - so after popping the element, check if the stack is empty or not 
    - if the stack is empty that means there are no elements in the stack and the element that comes next will be first element, so make front = Integer.MAX_VALUE
    - if the stack is not empty then front = stack.top value
  - so at any point for getting the peek element return this front variable as this always points to the front of queue.
*/

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

# DataStructures

# Stack DataStructure
The following are the most common Problems that can be solved using Stacks

## first concept
The following 4 types of questions can be solved using single concept - Monotonic Stack 
keywords to remember: closest/nearest, greater/smaller/largest, towards right/left. 
- Next Greater/Largest Element to Left
- Next Greater/Largest Element to Right
- Next Smaller Element to Left
- Next Smaller Element to Right

## second concept
- Stock Span Problem
- maximum area of histogram

## third concept
- Max area of rectangle in binary matrix

## fourth concept
- Rain water trapping
- Implementing a min stack
- Implement Stack using heap
- the celebrity problem
- longest valid parenthesis
- Iterative TOH

# Hints to Identify a Stack Problem
- If the question contains an Array in most cases we can solve it using either stack or heap
  - if it feels like we have to do some sorting to solve the problem then use heaps
  - or else in most of the cases stacks will solve the problem
- Also if any problem has O(n^2) complexity and of the form like this
  - for(int i = 0; i < n; i++)
      - and if the nested j loop is dependent on i
      - like for j in 1 to i
      - for j in i to 1
      - for j in i to n
      - for j in n to 1
- in this kind of loopings also mostly can be solved using stack datastructure.

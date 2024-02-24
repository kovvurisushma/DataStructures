# Dynamic Programming

- DP Problems can be Solved in 2 ways
    - Tabular approach (Top-down approach)
    - Enhanced recursion (recursion + memoisation)

   ## identification of a DP Problem
 - if a problem has a **choice** to decide and have to check for an **optimal** version then will consider it as a DP Problem
 - choice refers to two recursive calls

  ## Parent Problems of DP
    - 0/1 Knapscak (6 sub problems)
    - Unbounded Knapsack (5)
    - Fibonacci (7)
    - Longest Common Subsequence LCS(15)
    - Longest Increasing Subsequence LIS(10)
    - Kandanes Algorithm
    - Matrix Chain Multiplication   **Important concept**
    - DP on Trees (4)
    - DP on Grid (14)
    - others (5)
 
## Base Condition for a recursion
    - Always think about the smallest valid input
    - for example, in 0/1 knapsack the smalles valid input will be, 0 number of items and weight of the knapsack can also be 0
    - so base condition will be length(knapsack) == 0 || weight(knapsack) == 0 and in both cases the result(maximum profit) is 0
    - if(length(knapsack) == 0 || weight(knapsack) == 0) return 0

## Recursive Function
    - The main idea of recursive function will always be - make the recursive call with smallest input
    - if the fun(n) then recursive call will be fun(n - 1)
    - if we make the recusrive call also as fun(n) then the calls will never complete
    - so for recursion always call for smallest input.
 
 
 ## Choice diagram
    - choice diagram is most important in writing a recursive function
    -  <img width="452" alt="Screenshot 2024-02-24 at 12 02 14 PM" src="https://github.com/kovvurisushma/DataStructures/assets/50438716/423e5076-b903-4ebb-ab36-7e0ccd4fcebd">
    - The choice diagram will be your recursive condition
    
  
    ```CPP
    
      int knapsack(int weights[], int values[], int W, int N) {
          if(N == 0 || W == 0) return 0; // Base condition
          // recursive condition based on choice diagram
          if(weights[N - 1] <= W) {
            return max( knapsack(weights, values, W - weights[N - 1], N - 1) + values[N - 1] , knapsack(weights, values, W, N - 1) );
          }
          else return knapsack(weights, values, W, N - 1)
      }
    ```

    - memoised version
       

    ```CPP
    
      int DP[N + 1][W + 1] = {-1}; 
      int knapsack(int weights[], int values[], int W, int N) {
          if(N == 0 || W == 0) return 0; 
          if(DP[N][W]) != -1 return DP[N][W]; 
          if(weights[N - 1] <= W) {
            return DP[N][W] =  max( knapsack(weights, values, W - weights[N - 1], N - 1) + values[N - 1] , knapsack(weights, values, W, N - 1) );
          }
          else DP[N][W] =  return knapsack(weights, values, W, N - 1)
      }
    ```

## Converting this recursive to Tabular
  - To decide on the martix dimensions and length, check for the values that are changing in the recursive code, in the above code 2 values are changing(N, W). so we need a 2D array to store this values.
  - now run a loop to complete the base condition, in base consition we are saying if N == 0 or W == 0 then value will be 0
  - here N, W will be our i, j now.
  - so the code snippet will be

   ```CPP
   for(i = 0; i < N + 1; i++)
     for(int j = 0; j < W + 1; j++ ) {
       if(i == 0 || j == 0) DP[i][j] = 0;
     }
  ```

  - How to identify Knapsack realted problems
    - The knapsack related problems always follows this pattern - there will be a list of N items and for each item we will have a choice of either adding it or leaving it behind.
    - and there will be a max value W.
    - so if there is pattern of this one(items + choice and capacity + optimal(max,min..) ) 

    


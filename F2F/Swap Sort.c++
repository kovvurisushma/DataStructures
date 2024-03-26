/*

Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers in order of one space.

Input:[3 1 2 5 3] 

Output:[3, 4] 

Duplicate = 3, Missing = 4 . 

*/

/*
Approach 1:
- sort the entire array and compare adjacent elements for finding the missing and duplicate number
- Time Complexity: O(nlogn + n) - sorting + travsering array for comparing
- Space Complexity: O(n) - in case of merge sort

Approach 2:
- Traverse the array and store the elements , count in a hash map or count array. again traverse from range 1 to n to get the missing and duplicate element
- Time Complexity: O(n) - populating hash map + travsering range
- Space Complexity: O(n) - hash map

Approach 3:
- using simple math: Intresting approach :-))
- lets represent the array of numbers as the range of numbers: X - [a, b, c, d, e] and the input array will be like Y -  [b, c, b, d, a] - b is duplicate and e is missing in the array
- now to find the values of b and e
- calculate sum(X) - sum(Y) i.e., a + b + c + d + e - (b + c + b + d + a) = a + b + c + d + e - b - c - b - d - a = e - b
- sum(X) - sum(Y) = e - b  -----> equation 1
- caculate sum(X^2) - sum(Y^2) i.e., a^2 + b^2 + c^2 + d^2 + e^2 - b^2 - c^2 - b^2 - d^2 - a^2 = e^2 - b^2
- sum(X^2) - sum(Y^2) = e^2 - b^2   -----> equation 2
- now if you do (equation 2) / (equation 1) = e + b -----> equation 3
- now if we add (equation 1 + equation 3) / 2 = e
- and if we substitute the e value in any of the above equations we will get b value
- now return a, b values
- Time Complexity: O(N) - for finding sum of array
- Space complexity: O(1)

Approach 4:
- using swap sort
- for every element in the array, we will try to move it to the correct position.
- for i in range o to n:
    if arr[i] == i + 1 then element is in correct position, so continue with next iteration
    while(arr[i] != i + 1) {
        swap(arr[i], arr[i] - 1)
    }
- now traverse the array to find the missing and duplicate element, if arr[i] < i + 1 then missing number will be i + 1 and duplicate number will be arr[i]

Solution for this Approach:
for(int i = 0; i < nums.size();i++) {
  if(nums[i] == i + 1) continue;
  else {
    while(nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
      int temp = nums[i];
      nums[i] = nums[nums[i] - 1];
      nums[temp - 1] = temp;
    }
  }
}
for(int i = 0; i < nums.size(); i++) {
  if(nums[i] != i + 1) return nums[i];
}
*/

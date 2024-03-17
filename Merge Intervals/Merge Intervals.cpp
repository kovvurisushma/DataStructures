/*
Problem Statement: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
link: https://leetcode.com/problems/merge-intervals/description/
*/

/* 

Approach:
- First lets sort the array based on start time of interval
- so if the two intervals won't coincide if the end time of interval 1 < start time of interval 2
- in case of non-coincidence we dont need to do any thing so add this interval to the result array and move forward
- in case of the intervals coincidence, update the end time of the interval as prev_end = max(prev_end, max(cur_start, cur_end)); 
*/

// Solution using CPP

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<vector<int>> res;
  sort(intervals.begin(), intervals.end());
  int prev_start = intervals[0][0], prev_end = intervals[0][1];
  for(int i = 1; i < intervals.size(); i++) {
    int cur_start = intervals[i][0], cur_end = intervals[i][1];
    if(prev_end < cur_start) {
      res.push_back({prev_start, prev_end});
      prev_start = cur_start;
      prev_end = cur_end;
    }
    else prev_end = max(prev_end, max(cur_start, cur_end));
  }
  res.push_back({prev_start, prev_end});
  return res;
}

/*
Problem Solving: Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
link: https://leetcode.com/problems/non-overlapping-intervals/description/
*/

// Solution

static bool compareIntervals(vector<int> a, vector<int> b) {
        return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareIntervals);
        int count = 0;
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            int x = intervals[i][0], y = intervals[i][1];
            if(end > x) {
                count++;
            } else {
                end = y;
            }
        }
        return count;
    }

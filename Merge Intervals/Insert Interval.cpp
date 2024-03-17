/*
Problem Statement: You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.

link: https://leetcode.com/problems/insert-interval/description/?envType=daily-question&envId=2024-03-17
*/

// Solution:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int dest_start = newInterval[0], dest_end = newInterval[1];
        int indx = 0;
        while(indx < intervals.size()) {
            if(intervals[indx][1]  < newInterval[0]) {
                res.push_back({intervals[indx][0], intervals[indx][1]});
            } else if(newInterval[1] < intervals[indx][0]) {
                res.push_back({newInterval[0], newInterval[1]});
                newInterval = intervals[indx];
            } else {
                newInterval[0] = min(newInterval[0], intervals[indx][0]);
                newInterval[1] = max(newInterval[1], intervals[indx][1]);
            }
         indx++;     
        }
        res.push_back({newInterval[0], newInterval[1]});
        return res;
    }

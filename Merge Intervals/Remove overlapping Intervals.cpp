/* 
Problem Statement: Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d. Return the number of remaining intervals.

link: https://leetcode.com/problems/remove-covered-intervals/description/

*/

// Solution

    static bool compareInterval(vector<int>& interval1, vector<int>& interval2) {
        if(interval1[0] < interval2[0]) return true;
        else if(interval1[0] > interval2[0]) return false;
        else if(interval1[1] > interval2[1]) return true;
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1], res = 0;
        for(int i = 1; i < intervals.size(); i++) {
            int cur_start = intervals[i][0], cur_end = intervals[i][1];
            if(end >= cur_start && end >= cur_end) {
                res++;
            }
            start = min(cur_start, start);
            end = max(end, cur_end);
        }
        return intervals.size() - res;
    }


Merge Intervals


Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool mysort( Interval &a, Interval &b ) { 
        return ( a.start < b.start );   
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
    if ( intervals.size() < 2 ) return intervals;
    
    std::sort(intervals.begin(), intervals.end(), mysort );
    int next;
    for ( int i = 0, next=i+1; next < intervals.size() ; ) { 
        if ( intervals[i].end >= intervals[next].start ) { 
            intervals[i].end = intervals[i].end > intervals[next].end ?  intervals[i].end : intervals[next].end;
            ++next;
        } else {
            i=next;
            next++;
        }
    }
    
    for ( int i = 0; i < intervals.size()-1 ; ) {
        if ( intervals[i].end >= intervals[i+1].start ) { 
            intervals.erase( intervals.begin() + (i+1) );
        } else { i++; }
    }
    return intervals;
    }
};


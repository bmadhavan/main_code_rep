Given input which is a vector of (log-in time, log-out time), 
output time series which will have number of users logged in at each given time slot in the input,
output should only contain time slots which are given in input 

for example if the input is ("September", 1.2, 4.5), ("June", 3.1, 6.7), ("August", 8.9, 10.3) 

output should contain only 1.2, 3.1, 4.5, 6.7, 8.9, 10.3 

Example: /* [ ("September", 1.2, 4.5), ("June", 3.1, 6.7), ("August", 8.9, 10.3) ] => [(1.2, 1), (3.1, 2), (4.5, 1), (6.7, 0), (8.9, 1), (10.3, 0)] */

1.2  3.1  8.9 
4.5  6.7  10.3 

 struct Interval {
     int start;
     int end;
 };

 static bool mysort ( Interval& a, Interval& b ) {
	 return (a.start < b.start);
 }

 int main() {
	 vector<Interval> intervals = {{1, 4} ,{3,6}, {9, 20}};
	 if ( intervals.size() == 0 ) return 0;
	 std::sort( intervals.begin() , intervals.end() , mysort );
	 vector<Interval> result;
	 Interval t;
	 //Min heap
	 priority_queue< int, vector<int> , std::greater<int> > pq_min;

	 for ( int i=0; i < intervals.size() ; ) {
		 if ( !pq_min.empty() && intervals[i].start >= pq_min.top() ) {
			 t.start = pq_min.top();
			 t.end = pq_min.size()-1;
			 pq_min.pop();
		 } else {
			 pq_min.push( intervals[i].end );
			 t.start =  intervals[i].start ;
			 t.end = pq_min.size();
			 i++;
		 }
		 result.push_back(t);
	 }
	 // Add all remaining entries in pq.
	 while ( !pq_min.empty() ) {
		 t.start = pq_min.top();
		 t.end = pq_min.size()-1;
		 pq_min.pop();
		 result.push_back(t);
	 }

	 for ( int i = 0; i < result.size(); i++ ) {
		 cout << result[i].start << " - " << result[i].end << endl;
		 cout << endl;
	 }
 }





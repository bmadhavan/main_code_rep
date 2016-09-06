/*
 * quicksort.cpp
 *
 *  Created on: Sep 5, 2016
 *      Author: bmadhava
 */

#include <vector>
#include <iostream>

using namespace std;

static int k = 3;

int GetPartition( int start , int end )
{
	return ((start + ((end - start)/2)));
}

void quicksort( int start, int end , vector<int> &n)
{
	int part = n[GetPartition(start, end)];
	int low  = start;
	int high = end;

	while ( low < high  )
	{
		while ( n[low] < part )
			low++;

		while ( n[high] > part )
			high--;

		if ( low <= high )
		{
			int temp = n[low];
			n[low] = n[high];
			n[high] = temp;
			low++;
			high--;
		}
	}

	if (part == n[k-1]) {
		cout << "kth element is " << part << endl;
		return;
	}
	if ( start < high )
		quicksort( start, high, n );
	if ( end > low )
		quicksort( low, end, n );
}


int main()
{
	vector<int> num { 3, 2, 1, 5, 6, 4 };
	int start = 0;
	int end = num.size()-1;


	quicksort(start, end, num );
	int i = 0;
	while ( i < (int)num.size() )
		cout << num[i++] << endl;
}


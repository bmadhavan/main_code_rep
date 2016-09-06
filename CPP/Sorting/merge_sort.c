/*
 * merge_sort.c
 *
 *  Created on: Jun 10, 2015
 *      Author: bmadhava
 */

void mergeSort(int a[],int low,int mid,int high)
{
	int temp[10] = {0};
	int i=low,k;
	int l = low;
	int m = mid+1;
	int h = high;


	while ((l <= mid) && (m <= h))
	{
		if (a[l] <= a[m])
		{
			temp[i] = a[l];
			l++;
		} else {
			temp[i] = a[m];
			m++;
		}
		i++;
	}

	if(l>mid) {
		for(k=m;k<=h;k++){
			temp[i] = a[k];
			i++;
		}
	} else {
		for(k=l;k<=mid;k++){
			temp[i] = a[k];
			i++;
		}
	}

    for(k=low; k<=high; k++){
    	a[k] = temp[k];
	}


}

void split(int a[], int start, int end)
{
	int mid;

	if (start >= end)
	return;

	mid = (start + end)/2;
	split(a, start, mid);
	split(a, mid+1, end);
	mergeSort(a, start, mid, end);

}

int main()
{
	int i=0;
	int a[]= { 9,3,8,2,1,5,10,4,6,7 };

	split(a, 0, 9);

	while(i<10)
		printf("\t %d", a[i++]);

}

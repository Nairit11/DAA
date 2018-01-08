// C++ program to demonstrate performance of Quick Sort
// algorithm by hybrid it with insertion sort
#include <bits/stdc++.h>
using namespace std;

// Number of elements to be sorted
#define N 1000000
// Number of sorting runs
#define NUM 10

// perform insertion sort on arr[]
void insertionSort(int arr[], int low, int n)
{
	// Start from second element (element at index 0 
	// is already sorted)
	for (int i = low + 1; i <= n; i++) 
	{
		int value = arr[i];
		int j = i;
		
		// Find the index j within the sorted subset arr[0..i-1]
		// where element arr[i] belongs
		while (j > low && arr[j - 1] > value) 
		{
			arr[j] = arr[j - 1];
			j--;
		}
		// Note that subarray arr[j..i-1] is shifted to
		// the right by one position i.e. arr[j+1..i]
		
		arr[j] = value;
	}
}
 
int Partition (int a[], int low, int high)
{
	// Pick rightmost element as pivot from the array
	int pivot = a[high];

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int pIndex = low;	
	
	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot. 
	for (int i = low; i < high; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	// swap pIndex with Pivot
	swap (a[pIndex], a[high]);
	
	// return pIndex (index of pivot element)
	return pIndex;
}

void QuickSort(int a[], int low, int high)
{
	// base condition
	if(low >= high)
		return;

	// rearrange the elements across pivot
	int pivot = Partition(a, low, high);

	// recurse on sub-array containing elements that are less than pivot
	QuickSort(a, low, pivot - 1);

	// recurse on sub-array containing elements that are more than pivot
	QuickSort(a, pivot + 1, high);
}

void optimizedQuickSort(int A[], int low, int high)
{
	while (low < high) 
	{
		// do insertion sort if 10 or smaller
		if(high - low < 10)
		{
			insertionSort(A, low, high);
			break;
		}
		else 
		{
			int pivot = Partition(A, low, high);
			
			// tail call optimizations - recurse on smaller sub-array
			if (pivot - low < high - pivot) {
				optimizedQuickSort(A, low, pivot - 1);
				low = pivot + 1;
			} else {
				optimizedQuickSort(A, pivot + 1, high);
				high = pivot - 1;
			}
		}
	}	
}

// Function to check if arr is sorted in ascending order or not
bool isSorted(int arr[])
{
	int prev = arr[0];
	for (int i = 1 ; i < N; i++)
	{
		if(prev > arr[i])
		{
			cout << "QuickSort Failed!!";
			return false;
		}
		prev = arr[i];
	}

	return true;
}

int main()
{
	int arr[N], dupArr[N];
    
	// seed for random input
	srand(time(NULL));
 
	// to measure time taken by optimized
	// and non-optimized Quicksort 
	clock_t begin, high;
	double time_spent1 = 0.0, time_spent2 = 0.0;
	
	// perform Quicksort NUM times and take average
	for(int i = 0; i < NUM; i++)
	{
		// generate random input
    	for (int i = 0; i < N; i++)
    		dupArr[i] = arr[i] = rand()%100000;
    	
		// Perform non-optimized Quicksort on arr
		begin = clock();
	    QuickSort(arr, 0, N-1);
		high = clock();
		
		if (!isSorted(arr)) {
			cout << "ERRROR";
		}
		
		// calculate time taken by Non-Optimized QuickSort
		time_spent1 += (double)(high - begin) / CLOCKS_PER_SEC;
		
		// Perform Optimized Quicksort on dupArr
		begin = clock();
	    optimizedQuickSort(dupArr, 0, N-1);
		high = clock();
		
		if (!isSorted(dupArr)) {
			cout << "ERRROR";
		}
		
		// calculate time taken by optimized QuickSort
		time_spent2 += (double)(high - begin) / CLOCKS_PER_SEC;
	}
	
	cout << "Average time taken by Non-Optimized Quick Sort - " 
		 << time_spent1/NUM << endl;

	cout << "Average time taken by Optimized Quick Sort - " 
		 << time_spent2/NUM << endl;
    
    return 0;
}
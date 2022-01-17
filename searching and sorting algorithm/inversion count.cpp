// Inversion Count
// Send Feedback
// For a given integer array/list 'ARR' of size 'N', find the total number of 'Inversions' that may exist.
// An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
// A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

// 1. 'ARR[i] > 'ARR[j]' 
// 2. 'i' < 'j'

// Where 'i' and 'j' denote the indices ranging from [0, 'N').
// Input format :
// The first line of input contains an integer 'N', denoting the size of the array.

// The second line of input contains 'N' integers separated by a single space, denoting the elements of the array 'ARR'.
// Output format :
// Print a single line containing a single integer that denotes the total count of inversions in the input array.
// Note:
// You are not required to print anything, it has been already taken care of. Just implement the given function.  
// Constraints :
// 1 <= N <= 10^5 
// 1 <= ARR[i] <= 10^9

// Where 'ARR[i]' denotes the array element at 'ith' index.

// Time Limit: 1 sec
// Sample Input 1 :
// 3
// 3 2 1
// Sample Output 1 :
// 3
// Explanation of Sample Output 1:
// We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
// Sample Input 2 :
// 5
// 2 5 1 3 4
// Sample Output 2 :
// 4
// Explanation of Sample Output 1:
// We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).
#include<iostream>
using namespace std;

//function to merge array
long long merge(long long *arr, int start, int mid, int end)
{
	int *temp=new int [end-start+1];
	long long count=0;
	int i=start;
	int j=mid;
	int k=0;
	while(i<mid&&j<=end)
	{
		if(arr[i]<=arr[j])
		{
			temp[k]=arr[i];
			i++;
		}
		else
		{
			temp[k]=arr[j];
			j++;
			count+=mid-i;
		}
		k++;
	}
	while(i<mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=end)
	{
		temp[k++]=arr[j++];
	}
	for(int i=start, k=0; i<=end; i++, k++)
	{
		arr[i]=temp[k];
	}
	delete[]temp;
	return count;
}
//Function to split two subarrays and then merge them and count inversions
long long merge_sort(long long *arr, int start, int end)
{
	long long count=0;
	if(start<end)
	{
		int mid=(start+end)/2;
    /*
    divide the array into two parts total inversion will be the sum of
    'INVCOUNT'of left part + 
    sum of'INVCOUNT of right part'+
    IN count of their combine part
    */
		long long count_left=merge_sort(arr, start, mid);
		long long count_right=merge_sort(arr, mid+1, end);
		long long count_merge=merge(arr, start, mid+1, end);
		return count_left+count_right+count_merge;
	}
	return count;
}
long long getInversions(long long *arr, int n)
{
	long long count=merge_sort(arr, 0, n-1);
	return count;
}


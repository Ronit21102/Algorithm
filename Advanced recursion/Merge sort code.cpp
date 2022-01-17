// Merge Sort Code
// Send Feedback
// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.
// Input format :
// First line of input will contain T number of test cases
// First line of every input will contain a single integer N size of the input array.
// second line of each input will contain N space-separated integers.
// Output format :
// For every test case print, array elements in increasing order (separated by space) in a separate line.
// Constraints :
// 1 <= T <= 10
// 1 <= n <= 10^5
// Sample Input 1 :
// 1
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 1
// 5
// 2 1 5 2 3
// Sample Output 2 :
// 1 2 2 3 5 
#include<iostream>
using namespace std;
void merge(long long *arr, int start, int mid, int end)
{
	int *temp=new int [end-start+1];
	
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

}
void merge_sort(long long *arr, int start, int end)
{
	
	if(start<end)
	{
		int mid=(start+end)/2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);
		merge(arr, start, mid+1, end);
		
	}

}
int main(){
  
   int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
       long long *arr = new long long [n];
        
        for(int i = 0 ;  i< n ; i++)
        {
         cin>>arr[i];
        }
        merge_sort(arr ,0 ,  n-1);
         for(int i = 0 ;  i< n ; i++)
        {
         cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

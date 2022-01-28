// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int l = 0;
        int h = n-1;
        int mid = 0;
        while(l<h)
        {
            mid = (l+h)/2;
            if(h > mid && arr[mid] > arr[mid +1])
            {
                return arr[mid+1];
            }
            else if (l< mid && arr[mid]< arr[mid-1])
            {
                return arr[mid];
            }
            else if(arr[mid]>arr[h])
            {
                l = mid+1;
                cout<<arr[mid]<<" ";
            }
            else{
                h=mid-1;
                cout<<arr[mid]<<" ";
            }
        }
        return arr[mid];
    }
};

// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends


/*
   5
 3   4
1      2    

All permutations that will exist follow such an order. 
They rise from behinnd to a point and then fall essentially there will be a peak at a point so
What we need to do is to find out the element just behind the peak and then find an element in the 
rising end that will replace 
*/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int locswap = -1;
        for(int i = N-1;i>0;i--)
        {
            if(arr[i]>arr[i-1])
            {
                locswap = i-1;
                break;
            }   
        }
        int nextlargest = -1;
        if(locswap < 0)
        {
            reverse(arr.begin(),arr.end());
        }
        else
        {
            for( int i = N-1;i > 0;i--){
                if(arr[locswap]<arr[i])
                {
                    nextlargest = i;
                    break;
                }
            }
            swap(arr[locswap],arr[nextlargest]);
            reverse(arr.begin() + locswap + 1 ,arr.end());
        }
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

/*
I do not have to check every row completely.
so i start checking from the top right corner and the moment I a Zero I start going down and checking if
another row has a one there so that would mean the number of ones in that row is higher than this one
and then we repeat this process.
at worst we need to go to the bottom left element from thr top righgt element that is n+m moves.
and so we are done.
*/
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1;
	    int j = m-1;
	    int i = 0;
	    while(i<n && j>=0)
	    {
	        if(arr[i][j] ==1)
	        {
	            ans = i;
	            j--;
	        }
	        else
	        {
	            i++;
	        }
	    }
	    if(ans == -1)
	    {
	        return -1;
	    }
	    else
	    {
	        return ans;
	    }
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Endss

  
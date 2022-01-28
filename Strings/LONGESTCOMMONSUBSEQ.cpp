/* Longest repeating subseq.*/
// { Driver Code Starts
#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.length();
            int dp[n+1][n+1];

            for(int i =0 ;i<n+1;i++)
            {
                for(int j =0;j<n+1;j++)
                {
                    dp[i][j]=0;
                }
            }

            for(int i = 1; i<n+1;i++)
            {
                for(int j =1; j< n+1;j++)
                {
                    if(str[i-1] == str[j-1] && i != j)
                    {
                        dp[i][j] = 1 + dp[i-1][j-1]; 
                        //Toh agar 1 hua toh mai dekhoonga ki dono strings ko agar ek chota kiya
                        // toh fir mera kitna value ara hai lcs ka and jo bhi wo hai usme ek add krdenge
                    }
                    else{
                        dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                    }
                }
            }
            return dp[n][n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends

#include<bits/stdc++.h>
using namespace std;
// DP approach
// ---@ ""	A 	B	C	D	E	F
//""    0	1	2	3	4	5	6
// A	1	0	1	2	3	4	5
// B	2	1	0	1	2	3	4
// Z	3	2	1	1	2	3	4
// D	4	3	2	2	1	.	.
// E	5	.	.	.	.	.	.
// F	6	.	.	.	.	.	.
int min3(int x, int y, int z) { return min(min(x, y), z); }

int Solve(string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];

    for(int i =0; i<m+1;i++)
    {
        for(int j =0; j<n+1;j++)
        {
            if(i==0)
            {
                dp[i][j] = j;
            }

            else if(j==0)
            {
                dp[i][j] = i;
            }

            else{
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min3(
                        dp[i-1][j], //remove a letter from s1 and then check how much cost to make them same
                        dp[i-1][j-1], //replace the last letter of s1 same as s2 and then check cost to make rest same
                        dp[i][j-1] //add a letter to s1 so that s1[i+1]==s2[j] now check cost to make rest same.
                    );
                }
            }
        }
        
    }return dp[m][n];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int m = s1.length();
    int n =  s2.length();

    int ans = Solve(s1,s2,m,n);

    cout<<ans<<endl;
    return 0;
}

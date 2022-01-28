#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    int PAL(string S, int s, int e)
    {
        while(s<=e && s>=0 && e<S.size())
        {
            if(S[s]==S[e])
            {
                s--;
                e++;
            }
            else{
                break;
            }
        }
        if(e==s) return 1;
        return (e-s+1-2);
    }
    string longestPalin (string S) {
        string ans ="";
        int slen=-1;
        for(int i =0; i<S.size();i++)
        {
            int temp = max(PAL(S,i,i),PAL(S,i,i+1));
            cout<<temp<<endl;
            if(slen < temp)
            {
                slen = temp;
                if(temp%2==1 && temp!=0)
                {
                    ans = S.substr(i-(temp-1)/2 ,temp);
                }
                else if(temp !=0)
                {
                    ans= S.substr( i -(temp/2 - 1) ,temp);
                }
                else{
                    ans = S.substr(i,1);
                    slen =1;
                }
            }
        }
        return ans;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
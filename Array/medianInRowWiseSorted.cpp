// { Driver Code Starts
//Initial template for C++
#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int req = (r*c+1)/2;
        
        int max = INT_MIN;
        int min = INT_MAX
        for(int i = 0;i<r;i++)
        {
            if(matrix[i][0] < min)
            {
                min = matrix[i][0];
            }
            if(matrix[i][c-1]>max)
            {
                max = matrix[i][c-1]; 
            }
        }

        int mid = (max+min)/2;
        int count = 0;
        while(max>min)
        {
            mid = (max+min)/2;
            for(int i =0;i<r;i++)
            {
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid);
            }
            if(count == req) return mid;

            if(count > req)
            {
                max = mid -1;
            }
            else{
                min = mid+1;
            }
        }
        return mid;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends
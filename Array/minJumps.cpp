#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
int solve(int arr[], int n)
{
    for(int i =0;i<n;i++) arr[i]+=i;
    //making a reach array;

    int cur = arr[0];
    int flagend = -1;
    int max_ = 0;
    int j = 0;
    for(int i =0;i<n;i++)
    {   
        if(n == 1) return 0;
        if(cur >= n) {j++; flagend =1;break;}
        if(cur == i)
        {
            j++;
            cur = max(arr[i],max_);
            if(cur == 0)
            {
                flagend = -1;
                break;
            }
            max_ = 0;
            if(i == n-1) flagend =1;
        }
        else if(max_<arr[i] && i>0) max_=arr[i];
    }
    if(flagend == -1) return -1;
    else return j;
}
int main(){
    int arr[] = {1, 3, 3, 1, 0, 7};
    int n = 6;
    for(int i =0;i<n;i++) arr[i]+=i;
    //making a reach array;

    
    cout<<solve(arr,n)<<endl;
    return 0;
}

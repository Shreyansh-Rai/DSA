#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
int findSum(int arr[], int n, int x)
{
    int sum=0;
    int l =0;
    int r=n-1;
    int triplets=0;
    sort(arr,arr+n);
    for(int i =0 ;i<n;i++)
    {
        int a = arr[i];
        l=i+1;
        r=n-1;
        while(l<r)
        {
            sum = a + arr[l] + arr[r];
            if(sum>x)
            {
                r--;//wanna go backwards 
            }
            else if(sum<x)
            {
                l++; //wanna increase sum and check
            }
            else
            {
                triplets++;//incase of equality we will count them.
                break;
            }
        }
    }
    return triplets;
}
int main(){
    int arr[]= { 1,2,3,5,1,0};
    int x = 6;
    int n = 6;
    cout<<findSum(arr,n,x)<<endl;
    
    return 0;
}

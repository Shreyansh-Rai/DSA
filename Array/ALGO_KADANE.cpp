#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
void LargestSumSubArray(int arr[], int n)
{
    int max=-INT_MAX;
    int cur=0;
    for(int i =0;i<n;i++)
    {
        cur += arr[i];
        if(max < cur)
        {
            max = cur;
        }
        if(cur < 0)
        {
            cur = 0;
        }
    }

    cout<<max<<endl;
    /*
        This is called kadane's algorithm so basically:
        We know that if the current sum becomes negative at any given point of time there is no point in 
        finding the sum with further elements since it will only reduce the sum from that point onwards.

        Since max is being set based on the largest value of current sum, Think of it like this-

        if a subarray becomes negative, that is if the current sum becomes negative then that sub array will 
        not contribute in the final sum and so at this point the current sum needs to be reset.

        The largest value of the current sum is going to be the value that max sum is going to get assigned and
        then from there on out all we need to do is pick up a valid subarray find out the value that max takes in that
        array.

        Note that even if the current sum becomes 0 the largest value up until that point is still maintend in the
        max sum variable.
    */
}
int main(){
    int arr [] =  {
        5,-4,3,3,1,-2,6,-1
    };
    LargestSumSubArray(arr,8);
    return 0;
}

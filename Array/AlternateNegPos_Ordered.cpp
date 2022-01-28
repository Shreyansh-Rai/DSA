// Input:  arr[] = {1, 2, 3, -4, -1, 4}
// Output: arr[] = {-4, 1, -1, 2, 3, 4}

// Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
// output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}

#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
void rightrotate(int arr [], int start, int end)
{
    int temp = arr[end];
    for(int i=end; i>=start;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[start] = temp;
}
int main(){
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int oop=-1; //outofplace index
    for(int i = 0; i < 10; i++)
    {
        if(oop>-1)
        {
            if((arr[i] > 0 && arr[oop]<0) || (arr[i]<0 && arr[oop] >0))
            {
                rightrotate(arr,oop,i);
                //This part was the key step in finding the answer
                if((i - oop) >=2){ oop +=2 ;}
                else oop=-1;
            }
        }
        else{
            if(arr[i]>0 && i%2 ==0) oop = i;
            else if (arr[i]<0 && i%2 ==1) oop =i;
        }
    }

    for(int i =0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
// O(n^2) time O(1) space conditions imposed and order must be maintained
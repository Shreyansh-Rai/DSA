#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
void countsort(int arr[],int l)
{
    int max=arr[0];
    for( int i = 0; i<l ; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    
    int count[10000];
    for(int i=0;i<l;i++)
    {
        count[arr[i]]++;
    }
    for(int i =1; i<max+1;i++)
    {
        count[i]=count[i] + count[i-1];
    }
    int output [l];
    for(int i = 0; i < l; i++)
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--; 
    }
    for(int i = 0; i<l;i++)
    {
        arr[i]= output[i];
    }
}
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
  
// Driver Code
int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1, 0}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    countsort(arr,n); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
} 
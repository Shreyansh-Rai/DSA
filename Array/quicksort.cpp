#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
int Partition(int arr[], int l, int h)
{
    int p =  rand()%(h-l+1) +l;
    swap(arr[l],arr[p]);
    int pivot = arr[l];
    int i = l;
    int j = h;
    while(i<j)
    {
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[j]);
    return j;
}
void QuickSort(int arr[], int l, int h)
{
    if(l<h)
    {
        int pivot = Partition(arr, l, h);
        QuickSort(arr,l,pivot-1);
        QuickSort(arr,pivot+1,h);
    }
}
int main(){
    int arr [] = { 9,1,8,7,2,6,3,5,4};
    QuickSort(arr , 0, 8);
    for(int i =0; i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

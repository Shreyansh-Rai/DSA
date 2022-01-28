#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
int Partition(int arr[], int l, int h)
{
    int i = l;
    int j = h;
    int pivot = 0;

    while(i<j)
    {
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i<j)
            swap(arr[i],arr[j]);
    }
    return i;
}

int main(){
    int arr[] = {-5, 2, -5, -2, -4, -7, -1, -8, -1, -8};
    int posind = Partition(arr,0,9);
    int numpos = 9 - posind +1;
    int t = posind;
    for(int i = 1;i<2*posind;i+=2)
    {
        if(numpos > 0){
            swap(arr[i],arr[t++]);
            numpos--;

        }
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//Conditions imposed : O(1) Space O(n) time but no order needs to be maintained in the output array
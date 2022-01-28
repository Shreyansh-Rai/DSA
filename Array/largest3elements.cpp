#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
int main(){
    int arr[] = {10, 4, 3, 50, 23, 90};
    int num [] = {0,0,0};
    for(int j =0;j<3;j++)
    {
        for(int i =0;i<6;i++)
        {
            if(j==0)  if(num[0] < arr[i]) num[0] = arr[i];
            if(j==1)  if(num[1] < arr[i] && arr[i] < num [0]) num[1] = arr[i];
            if(j==2)  if(num[2] < arr[i] && arr[i] < num [1]) num[2] = arr[i];
        }
    }
    cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;
    return 0;
}

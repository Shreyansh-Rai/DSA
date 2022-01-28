#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
int main(){
    // https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/
    int arr[] = {10, 22, 5, 75, 65, 80};
    int n = 6;
    //So first we need to make an array that will store the profits.
    //it is important to remember this approach of solving.
    //We need the array populated in O(n) and so consider only one trasaction.
    //so we could just go and say that from i to n-1 either the i+1 th transaction was the maximum OR 
    //The maximum value - current stock price is the answer.
    //this will fill the array with the highest profit in i to n-1 range. Now we need to consider the first transaction.
    //So basically grab the min stock price and calculate the dif between that and the current price.
    //either the i-1 th profit is asnwer or the current profit  + dif .

    //To get to implement that= >
    
    int profit[n];
    for(int i =0;i<n;i++) profit[i] =0;
    int maxprice = arr[n-1];
    for(int i = n-2;i>=0;i--)
    {
        if(maxprice<arr[i]) maxprice = arr[i];
        profit[i] = max(profit[i+1],maxprice - arr[i]);
    }
    int minprice = arr[0];
    for(int i =1;i<n;i++)
    {
        if(minprice > arr[i]) minprice = arr[i];
        profit[i] = max(profit[i-1] , profit[i] + (arr[i] - minprice));
    }
    cout<<profit[n-1];
    return 0;
}

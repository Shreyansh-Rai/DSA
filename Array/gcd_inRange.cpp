#include<iostream>

#include<bits/stdc++.h>

using namespace std;
int n = 0;
const int N = 1e5;
int segT[N];
int query(int st, int en, int l, int r, int node)
{
    if(l>en || r<st) return 0;
    if(l<=st && r >= en)
    {
        return segT[node];
    }
    int mid = (en+st)/2;
    return __gcd(query(st,mid,l,r,2*node+1),query(mid+1,en,l,r,2*node +2));
}
int constructTree(int arr[],int node, int st, int en)
{
    if(st == en)
    {
        segT[node] = arr[st];
        return segT[node];
    }
    int mid = (st+en)/2;
    segT[node] = __gcd(constructTree(arr,2*node+1,st,mid),constructTree(arr,2*node+2,mid+1,en));
    return segT[node];
}
int main(){
    int n = 5;
    int arr[] = {2, 3, 60, 90, 50};
    constructTree(arr,0,0,n-1);
    // cout<<segT[2];
    cout<<query(0,n-1,0,2,0)<<endl;
    return 0;
}

//Today is the last time you get to master this segtree stuff.
/*
simple
create =>
break array into two and seg[node] = Divide from middle and conquer and for base case seg[node] = arr[st]

update =>
just add the difference incase the pos is in the range if not just return (so if pos = 4 and current seg is 0,3 return)
also after updating make an if condition until st!=en get mid split array and recursively update.

seacrh =>
If no overlap return
if full overlap return answer
if partial overlap then find out the mid and divide and conquer. remember to return the operation(query(),query()) pagal jaisa dont
return the sum and call it a day
*/
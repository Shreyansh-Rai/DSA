#include <iostream>
#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
const int N = 1e5;
int segt[4*N];
void update(int st, int en, int node, int dif, int pos)
{
	if(pos<st || pos>en) return;
	segt[node] += dif;
	if(st!=en)
	{
		int mid = (st+ en)/2;
		update(st,mid,2*node+1,dif,pos);
		update(mid +1, en, 2*node+2, dif,pos);
	}
}
int getsum(int st, int en, int l, int r,int node)
{
	if(l<=st && en<=r)
	{
		return segt[node];
	}
	if(r<st || en< l)
	{
		return 0;
	}
	else{
		int mid = (st+en)/2;
		return (getsum(mid+1,en,l,r,node*2 + 2) + getsum(st,mid,l,r,2*node +1));
	}
}
int segtree(int arr[], int node, int st, int en)
{
	if(st == en)
	{
		segt[node] = arr[st];
		return segt[node];
	}
	int mid = (st+en)/2;
	
	segt[node] = segtree(arr, 2*node+1, st, mid ) + segtree(arr, 2*node+2, mid+1, en);
	return segt[node];
	//The hwight of the segtree is going to be log(n+1) and the size of the segarray needs to be 2^h -1 for efficient space usage
}
int main(int argc, char **argv)
{
	int arr[] = {1,2,3,4,5,6};
	int n = 6;
	int max = segtree(arr,0,0,n-1);
	cout<<max<<endl;
	for(int i =0; i<4*n;i++)
	{
		cout<<segt[i]<<" ";
	}
	cout<<endl;
	cout<<getsum(0,n-1,0,2,0)<<endl;
	update(0,n-1,0,1,0);
	cout<<getsum(0,n-1,0,5,0);
	return 0;
}



// int search(int node,int st, int en, int l, int r)
// {
// 	if(st>r || en<l)
// 	return 0;
// 	if(l<=st && r>=en)
// 	{
// 		return segt[node];
// 	}
// 	else
// 	{
// 		int mid = (st+en)/2;
// 		return search(2*node+1,st,mid,l,r) + search(2*noode +2, mid+1,en,l,r);
// 	}
// }
// void update(int pos, int dif, int st, int en, int node)
// {
// 	if(st> pos || en< pos)
// 	{
// 		return;
// 	}
// 	int mid = (st+en)/2;
// 	segt[node] += dif;
// 	if(st!=en)
// 	{
// 		update(pos,dif,st,mid, 2*node+1);
// 		update(pos,dif,mid+1,2*node +2);
// 	}
// }
// int build(int arr[], int st, int en, int node)
// {
// 	if(st ==  en)
// 	{
// 		segt[node] = arr[st];
// 		return segt[node];
// 	}
// 	int mid = (st + en)/2;
// 	segt[node] = build(arr, st, mid, 2*node + 1) + build(arr, mid +1, en, 2*node +2);
// 	return segt[node];
// }

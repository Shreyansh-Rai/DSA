#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map <int,int> umap;
    int m,n;
    cin>>m>>n;
    int a[m];
    int cnt = 0;
    int b[n];
    for(int i =0; i<m;i++)
    {
        cin>>a[i];
    }    
    for(int i =0; i<n;i++)
    {
        cin>>b[i];
    }    
    for(int i =0; i<m;i++)
    {
        if(umap[a[i]]==0)
        {
            cnt++;
            umap[a[i]] = 1;
        }
    }
    for(int i = 0 ; i<n; i++)
    {
        if(umap[b[i]]==0)
        {
            cnt++;
            umap[b[i]] = 1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

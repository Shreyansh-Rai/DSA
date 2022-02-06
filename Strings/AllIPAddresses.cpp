#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

void Solve(string st, int s, int e, int lvl, string a,vector <string> &ans)
{   
    if(s>e+1)
    {
        cout<<"ccccccc"<<a<<" "<<s<<" "<<e<<endl;
        return ;
    }
    if(lvl == 5)
    {
        if(s==e+1)
        {
            ans.push_back(a);
            return;
        }
        else{
            cout<<"BBBBBBB"<<a<<endl;
            return;
        }
    }
    string temp;
    for(int i = s; i<s+3; i++)
    {
        if((e-i)<(4-lvl)) return;
        
        if(i<=e)
        {
           temp = st.substr(s,i-s+1);
           cout<<temp<<" "<<lvl<<endl;
           
        }
        int num = stoi(temp);
        if(num>255 || (temp[0]==0 && temp.length()>1))
        {
            cout<<"AAAAAAA"<<a<<endl;
            return ;
        }
        Solve(st,i+1,e,lvl+1,a+temp+".",ans);
    }
}
int main(){
    string s = "100";
    vector <string> ans;
    string a="";
    int start = 0;
    int end = s.length();
    int lvl=1; //which segment of the ip address.
    Solve(s,start,end-1,lvl,a,ans);
    cout<<ans.size()<<endl;
    for(int i =0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
void PrintAllSubsequences(string s, string t)
{
    //Since we must print all the subseq. we must have atleast a 2^n algo so we follow recursion here
    if(s=="")
    {
        //including a blank string t.
        cout<<t<<endl;
    }
    else{
        //Recursion with the take one and leave one concept.
        PrintAllSubsequences(s.substr(1),t);//Do not add s[0] to t
        t=t+s[0]; 
        PrintAllSubsequences(s.substr(1),t);//append the s[0] to t
    }
}
int main(){
    string s;
    cin>>s;
    string t="";
    PrintAllSubsequences(s,t);    
    return 0;
}

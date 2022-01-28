#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
//lets assumee only small letters.
int smallestWindow(string s)
{
    int windowlength =s.length();
    int countUniq=0;
    int arr[26] ={0};
    for(int i =0;i<s.length();i++)
    {
        if(arr[s[i]-'a'] == 0)
        {
            arr[s[i]-'a']++;
            countUniq++;
        }
    }
    int start =0;
    int uniq = 0;
    int freq[26]={0};
    int n = s.length();
    if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    for(int i =0;i<s.length();i++)
    {
        freq[s[i]-'a']++;
        if(freq[s[i]-'a'] == 1)
        {
            //uniq char
            uniq++;
        }
        if(countUniq == uniq)
        {
            while(freq[s[start]-'a'] > 1)
            {
                freq[s[start]-'a']--;
                start++;
            }
        }
        if(countUniq==uniq)
        {
            if(windowlength>(i-start+1)) windowlength = i-start+1;
        }
    }
    return windowlength;
}
int main(){
    cout<<smallestWindow("aaaaaabbbb")<<endl;
    return 0;
}

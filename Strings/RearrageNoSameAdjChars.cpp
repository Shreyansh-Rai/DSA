#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;
char findMax(vector <int> count)
{
    int max =0;
    char ch =' ';
    for(int i =0;i<26;i++)
    {
        if(count[i] > max)
        {
            ch = 'a'+i;
            max= count[i];
        }
    }
    return ch;
}
string ModIt(string s)
{   //we use a greedy approach to solve this question and put the largest freq char in the even places first.
    vector <int> count(26);

    for(int i=0;i<26;i++)
    {
        count[s[i] - 'a']++;
    }
    char maxc = findMax(count);
    
    int n = s.length();
    if(count[maxc-'a']>s.length()/2) return "-1";
    string result(n,' ');
    //greedy
    int i =0;
    while(count[maxc-'a'])
    {
        result[i] = maxc;
        i+=2;
        count[maxc-'a'] --;
    }
    count[maxc-'a'] =0;
    for(int j =0;j<26;j++)
    {
        while(count[j])
        {
            if(i>=s.length()) i=1;
            result[i]='a'+j;
            count[j]--;
            i+=2;
             //start filling th odd positions now.
        }

    }
    return result;
}
int main(){
    cout<<ModIt("aaabbc");
    return 0;
}

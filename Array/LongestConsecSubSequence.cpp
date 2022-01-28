#include <iostream>

#include <stack>

#include <vector>

#include <iostream>

#include <string>

#include <unordered_map>

#include <unordered_set>
using namespace std;

//Below is the most efficient solution from the editorial.

// { Driver Code Starts MY SUBISSION
// #include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]
    int FLCS(int arr[], int N)
    {
        unordered_set<int> S;
        for (int i = 0; i < N; i++)
        {
            S.insert(arr[i]);
        }
        int maxcount = 0;
        for (int i = 0; i < N; i++)
        {
            if (S.find(arr[i] - 1) == S.end()) //if the element arr[i] -1 is not found this means arr[i] is first element of the subsequence
            {
                //in this case we find out all the next elements.
                int j = arr[i];
                // j here maintains the count of all the elements that are in the needed sequence.
                while (S.find(j) != S.end())
                {
                    j++; //find the next element that is exactly one larger than the previous
                }
                maxcount = max(maxcount, j - arr[i]);
                //Note that this is an O(N) approach as all elements are iterated through exactly one time.
            }
        }
        return maxcount;
    }

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_map<int, int> umap;
        int min = INT_MAX;
        int max = INT_MIN;

        for (int i = 0; i < N; i++)
        {
            umap[arr[i]]++;
            if (min > arr[i])
                min = arr[i];
            if (max < arr[i])
                max = arr[i];
        }
        int cursum = 0;
        int maxsum = 0;
        for (int i = min; i <= max; i++)
        {
            if (umap[i] > 0)
            {
                cursum++;
                if (maxsum < cursum)
                    maxsum = cursum;
            }
            else
            {
                cursum = 0;
            }
        }
        return maxsum;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int n, i, a[100001];
    
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.FLCS(a, n) << endl;
    

    return 0;
} // } Driver Code Ends


/*
It was clear from teh get go that we atleast had to hash the values ot make sure we get an o(1) lookup time
now since we needed to find out a continous seq we can simply hash the values as needed and then 

we must only check for the longest sequence if the element we are starting from is going to be the starting 
element of our sequence.

So eachtime we are getting an element from the array we first perform a lookup in our hash and check
if the element that we got back is actually a start element and then if it is that

we start a loop such that we keep getting out elements such that each new element is one larger than the prev
and so all the elements that we are getitng are definitely in a sequence .

Once we stop finding the elements in this way we can subtract the current value of the element that was not
found in the hash with the arr[i] so now we know exactly how long the sequence was and we can then maintain
track of this to get an answer.
*/
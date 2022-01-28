// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;


// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(string a, int l, int r)
{
	// Base case
	if(l==r)
	{
		cout<<a<<endl;
	}
	else{
		for(int i=0;i<=r;i++)
		{
			swap(a[i],a[l]);
			permute(a,l+1,r);
			swap(a[i],a[l]);
		}
	}
}

// Driver Code
int main()
{
	string str = "ABC";
	
	int n = str.size();
	permute(str, 0, n-1);
	return 0;
}

// This is code is contributed by rathbhupendra
#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std; 
int multiply(int res [], int x, int si)
{
    int carryover = 0;
    //now we perform second standard wala multiplication
    for(int i = 0;i<si;i++)
    {
        long long prod = res[i]*x + carryover;
        res[i] = prod % 10 ;
        carryover = prod/10;
    }
    /*
    Dekho ye wala question was more about thoda brute approach.
    What you need to remember is that multiply toh krna is not very difficult at all but the point here is that when you multiply
    the product that you get needs to get not only added to the carry but also to the res[i] 

    now consider the case where the last digit is 9 and there multiplication being done by 100 then 900 is generated. 

    What this means is that there is going to be a carry of 90 and 0 is going to go to the highest place in the res array

    now given all of this we need to consider what we must do with this 90 that is left over with us

    so first of all we must generate a new carry for the res[si] place and this will be the units place of the carry 90

    now we are left over with another 9 and so inorder to handle this bit right over here we must reduce the value of carry by a 10th
    
    and then move on in the while loop adding the 9 % 10 to the res[si] where si has gone up by 1.

    so remember that.
    */

    while(carryover)
    {
        //if there is a carryover we must add it on to the last index of the result
        res[si] = carryover%10;
        carryover/=10;
        si++;
        
    }
    return si;
}
void factorial(int num)
{
    int res[500] ;
    //This is going to blatant abuse of space and time to get the work done.
    res[0] = 1;
    int result_s = 1;
    for(int i =2;i<num+1; i++)
    {
        result_s = multiply(res,i,result_s);
        // cout<<i<< " "<<res[0];
    }
    
    for(int i = 0;i<result_s;i++)
    {
        cout<<res[result_s-1-i];
    }
    cout<<endl;
}
int main(){
    int num =0;
    cin>> num;
    factorial(num);
    return 0;
}

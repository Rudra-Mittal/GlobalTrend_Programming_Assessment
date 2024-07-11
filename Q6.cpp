#include<bits/stdc++.h>
using namespace std;
//  funtion to find factorial of a number
int factorialRecursive(int n){
    if(n==0){
        return 1;
    }
    return n*factorialRecursive(n-1);
    // time complexity is O(n)
    // space complexity is O(n) (for the recursive stack space)
}
int factorialIterative(int n){
    int fact = 1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
    // time complexity is O(n)
    // space complexity is O(1)
}
int main(){
    int n;
    cout<<"Enter the number to find the factorial\n";
    cin>>n;
    if(n<0){
        cout<<"Factorial of negative number is not possible\n";
        return 0;
    }
    cout<<"Factorial using recursive function "<<factorialRecursive(n)<<endl;
    cout<<"Factorial using iterative function "<<factorialIterative(n)<<endl;


return 0;
}
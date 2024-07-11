#include<bits/stdc++.h>
using namespace std;

// funtion to find sum of Digits of a number using recursion
int sumOfDigitsRecursive(int n){
    if(n==0){
        return 0;
    }
    return n%10+sumOfDigitsRecursive(n/10);
    // time complexity is O(log(n))
    // space complexity is O(log(n)) (for the recursive stack space)
}

// function to find sum of Digits of a number using iteration
int sumOfDigitsIterative(int n){
    int sum = 0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
    // time complexity is O(log(n))
    // space complexity is O(1)
}
int main(){
    int n;
    cout<<"Enter the number to find the sum of digits\n";
    cin>>n;
    //  we can find the sum of digits of negative number by taking the absolute value of the number
    cout<<"Sum of digits using recursive function "<<sumOfDigitsRecursive(abs(n))<<endl;
    cout<<"Sum of digits using iterative function "<<sumOfDigitsIterative(abs(n))<<endl;



return 0;
}
#include<bits/stdc++.h>
using namespace std;

// funtion to find GCD of two numbers using recursion
// this algotithm is known as Euclidean algorithm
int gcdRecursive(int a,int b){
    if(b==0){
        return a;
    }
    return gcdRecursive(b,a%b);
    // time complexity is O(log(min(a,b)))
    // space complexity is O(log(min(a,b))) (for the recursive stack space)
}

// function to find GCD of two numbers using iteration
int gcdIterative(int a,int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
    // time complexity is O(log(min(a,b)))
    // space complexity is O(1)
}
int main(){

int a,b;
cout<<"Enter the two numbers to find the GCD\n";
cin>>a>>b;
cout<<"GCD using recursive function "<<gcdRecursive(a,b)<<endl;
cout<<"GCD using iterative function "<<gcdIterative(a,b)<<endl;


return 0;
}

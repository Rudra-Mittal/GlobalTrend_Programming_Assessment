#include<bits/stdc++.h>
using namespace std;
// function to check whether the string contains only alphabets
bool isOnlyAlphaebts(string s){
    for(int i=0;i<s.size();i++){
        if(!(s[i]>='a' && s[i]<='z') && !(s[i]>='A' && s[i]<='Z')){
            return false;
        }
    }
    return true;
    // time complexity is O(n)
    // space complexity is O(1)
}
int main(){

string s1 = "Hello";
cout<<isOnlyAlphaebts(s1)<<endl;
string s2 = "Hello123";
cout<<isOnlyAlphaebts(s2)<<endl;
string s3 = "4343";
cout<<isOnlyAlphaebts(s3)<<endl;

return 0;
}
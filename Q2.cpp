#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string &s){
    int n = s.size();
    if(n==0){
        return 0;
    }
    unordered_set<char>st; //  this set will contain the unique characters of the substring
    int i = 0 , j = 0 , maxLen = 0;
    // using a sliding window approach 
    // i will be the start of the window and j will be the end of the window
    // if the character at j is not present in the set then we will add it to the set and increment j
    // if the character at j is already present in the set then we will remove the character at i from the set and increment i
    while(j<n){
        while(st.count(s[j])){
            st.erase(s[i]);
            i++;
        }
        st.insert(s[j]);
        maxLen = max(maxLen,j-i+1);
        j++;
    }
    return maxLen;

    // Time complexity : O(n)
    // Space complexity : O(n)
}
int main(){
    string s;
    cout<<"Enter the string :";
    cin>>s;
    cout<<"Length of longest substring is: "<<longestSubstring(s)<<endl;


return 0;
}

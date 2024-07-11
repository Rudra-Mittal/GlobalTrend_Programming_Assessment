#include<bits/stdc++.h>
using namespace std;


void leftRotate(vector<int> &nums, int k){
    int n = nums.size();
    k = k%n; // as after n rotations the array will be same
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    reverse(nums.begin(),nums.end());
    // time complexity is O(n)
    // space complexity is O(1)
}
void rightRotate(vector<int> &nums, int k){
    int n = nums.size();
    k = k%n; // as after n rotations the array will be same
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    // time complexity is O(n)
    // space complexity is O(1)
}
int main(){
    vector<int> nums1 = {1,2,3,4,5};
    cout<<"Original Array\n";
    int k1 = 2; // number of rotations to be done
    leftRotate(nums1,k1);
    cout<<"Left Rotate\n";
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
    cout<<"\n________________________\n";
    vector<int> nums2 = {1,2,3,4,5,6,7,8,9,10};
    int k2=5;
    cout<<"\nRight Rotate\n";
    rightRotate(nums2,k2);
    for(int i=0;i<nums2.size();i++){
        cout<<nums2[i]<<" ";
    }
    cout<<endl;

return 0;
}
// 1 2 3 4 5
// 4 5 1 2 3

#include<bits/stdc++.h>
using namespace std;
// function to find maximum difference between any two elements in the array
long long maxDifference(vector<int> nums){
    int n = nums.size();
    if(n==0){
        return 0;
    }
    int minElement = nums[0];
    int maxElement = nums[0];
    for(int i=1;i<n;i++){
        minElement = min(minElement,nums[i]);
        maxElement = max(maxElement,nums[i]);
    }
    return (long long)maxElement-minElement;
    // time complexity is O(n)
    // space complexity is O(1)
}
int main(){
    vector<int> nums1 = {2,3,10,6,4,8,1};
    cout<<"Maximum difference between any two elements in the array is "<<maxDifference(nums1)<<endl;
    vector<int> nums2 = {1,-1};
    cout<<"Maximum difference between any two elements in the array is "<<maxDifference(nums2)<<endl;
    vector<int> nums3 = {};
    cout<<"Maximum difference between any two elements in the array is "<<maxDifference(nums3)<<endl;


return 0;
}
#include<bits/stdc++.h>
using namespace std;
// defination of  class TreeNode 

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
//  function to generate tree from the given numbers
// considering INT_MIN as NULL
TreeNode* generateTree(vector<int> nums){
    if(nums.size()==0){
        return NULL;
    }
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*>q;
    q.push(root);
    int i = 1;
    while(i<nums.size()){
        TreeNode* temp = q.front();
        q.pop();
        if(nums[i]!=INT_MIN){
            temp->left = new TreeNode(nums[i]);
            q.push(temp->left);
        }
        i++;
        if(i<nums.size() && nums[i]!=INT_MIN){
            temp->right = new TreeNode(nums[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

//  function to find maximum path sum
int maxSum(TreeNode *root,int &ans){
    if(!root){
        // cout<<ans<<endl;
        return 0;
    }
    int leftSum = maxSum(root->left,ans);
    int rightSum = maxSum(root->right,ans);
    // the maximum path sum could be the current node value or the current node value + left subtree or current node value + right subtree or current node value + left subtree + right subtree
    int currSum=max({root->val, root->val+leftSum , root->val+rightSum , root->val+leftSum+rightSum});
    ans=max(ans,currSum);

    return max({root->val,root->val+leftSum,root->val+rightSum});
    // time complexity is O(n) , n is  number of nodes in the tree
    // space complexity is O(n)  (for the recursive stack space
}
int main(){

// the value INT_MIN is considered as NULL

TreeNode* root=generateTree({-10,9,20,INT_MIN,INT_MIN,15,7});

int ans=INT_MIN;

maxSum(root,ans);
cout<<ans<<endl;

return 0;
}
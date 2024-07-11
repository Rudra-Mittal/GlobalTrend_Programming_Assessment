#include<bits/stdc++.h>
using namespace std;
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

// function to serialize the tree, it will return the tree as string
string serialize(TreeNode* root){ 
    if(!root){
        return "null";
    }
    queue<TreeNode*>q;
    q.push(root);
    string s = "";
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp){
            s+=to_string(temp->val)+",";
            q.push(temp->left);
            q.push(temp->right);
        }
        else{
            s+="null,";
        }
    }
    return s;

    // time complexity is O(n) , n is  number of nodes in the tree
    // space complexity is O(n)  (for the queue)
}
// function to deserialize the tree, it will return the root of the tree
TreeNode* deserialsize(string s){
    if(s=="null"){
        return nullptr;
    }
    stringstream ss(s);
    string temp;
    vector<string> nums;
    while(getline(ss,temp,',')){
        nums.push_back(temp);
    }
    queue<TreeNode*>q;
    TreeNode* root = new TreeNode(stoi(nums[0]));
    q.push(root);
    int i = 1;
    while(i<nums.size()){
        TreeNode* temp = q.front();
        q.pop();
        if(nums[i]!="null"){
            temp->left = new TreeNode(stoi(nums[i]));
            q.push(temp->left);
        }
        i++;
        if(i<nums.size() && nums[i]!="null"){
            temp->right = new TreeNode(stoi(nums[i]));
            q.push(temp->right);
        }
        i++;
    }
    return root;
    // time complexity is O(n) , n is  number of nodes in the tree
    // space complexity is O(n)  (for the queue)
}
int main(){

    vector<int> nums = {1,2,3};
    TreeNode* root = generateTree(nums);
    string s = serialize(root);
    cout<<s<<endl;
    TreeNode* root1 = deserialsize(s);
    string s1 = serialize(root1);
    cout<<s1<<endl;


return 0;
}

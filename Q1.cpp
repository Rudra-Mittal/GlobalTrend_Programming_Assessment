#include<bits/stdc++.h>
using namespace std;
// defination of class ListNode
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

// funtion to create a linked list with given n numbers
ListNode* createList(vector<int> &nums){
    if(nums.size()==0){
        return nullptr;
    }
    ListNode *head= new ListNode(nums[0]);
    ListNode *temp = head;
    for(int i=1;i<nums.size();i++){
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }
    return head;
}

ListNode*  reverseRecursive(ListNode *head){ // function to reverse a linked list using recursion
    if(!head || !head->next){
        return head;
    }
    ListNode * newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;

    // Time complexity : O(n)
    // Space complexity : O(n) due to recursion stack
}

ListNode* reverseIterative(ListNode *head){ // function to reverse a linked list using iteration
    // base case if head is null or head is the only node
    if(!head || !head->next){
        return head;
    }
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;

    // Time complexity : O(n)
    // Space complexity : O(1)
}

void display(ListNode *head){// function to display the linked list
    ListNode *temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    
    vector<int> nums1= {1,2,3,4,5};
    ListNode *head1 = createList(nums1);
    cout<<"Original List: ";
    display(head1);
    ListNode *newHead1 = reverseRecursive(head1);
    cout<<"Reversed List using recursion: ";
    display(newHead1);
    cout<<"______________________________________________________\n";

    vector<int> nums2= {1,2,3,4,5,6,7,8};
    ListNode *head2 = createList(nums2);
    cout<<"Original List: ";
    display(head2);
    ListNode *newHead2 = reverseIterative(head2);
    cout<<"Reversed List using iteration: ";
    display(newHead2);
    cout<<endl;

    cout<<"\nAn edge case: \n";
    vector<int> nums3= {1};
    ListNode *head3 = reverseIterative(createList(nums3));
    cout<<"Reverse of a single node list: ";
    display(head3);

return 0;
}
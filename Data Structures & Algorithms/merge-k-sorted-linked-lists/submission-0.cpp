/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwo(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* curr=&dummy;
        while(l1!=nullptr && l2!=nullptr){
           if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
           }else{
                curr->next=l2;
                l2=l2->next;
           }
           curr=curr->next;
        }
        if (l1 != nullptr) curr->next = l1;
        if (l2 != nullptr) curr->next = l2;
        return dummy.next;


    }
    ListNode* merge(int l, int r, vector<ListNode*>& lists){
        if(l>r)return nullptr;
        if(l==r)return lists[l];
        int mid=l+(r-l)/2;
        ListNode* m1=merge(l,mid,lists);
        ListNode* m2=merge(mid+1,r,lists);
        return mergeTwo(m1,m2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        return merge(0,lists.size()-1,lists);
    }
};

// LEETCODE SOLUTION

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

/*

class Solution {
    
private:
    ListNode* solve(ListNode* chhoti_list, ListNode* mothi_list){
        // ***A IMP QUESTION***
        //jar chhoti_list mdhe fakt ekach node asel tr
        if(chhoti_list->next==NULL) {
            chhoti_list->next = mothi_list;
            return chhoti_list;
        }
        
        //creating nodes
        ListNode* curr1=chhoti_list;
        ListNode* next1=curr1->next;
        ListNode* curr2=mothi_list;
        ListNode* next2=curr2->next;
        
        while(next1!=NULL && curr2!=NULL){
            if(curr2->val >= curr1->val && curr2->val <=next1->val){
                curr1->next=curr2;
                next2=curr2->next;
                curr2->next=next1;
                
                //update pointers
                curr1=curr2;
                curr2=next2;
                
            }
            
            else{
                curr1=curr1->next;
                next1=next1->next;
                
                if(next1==NULL){
                    curr1->next=curr2;
                    return chhoti_list;
                }
                
            }
        }
        return chhoti_list;
    }
    
    
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        if(list1->val < list2->val){
            return solve(list1, list2);
        }
        else{
            return solve(list2, list1);
        }
        
    }
};

*/
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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;

        
        //to get the first middle in case of even sized LL listNode* fast = head->next
        //start with a head start so it stops one step early
        
        ListNode* slow=head;
        ListNode* fast=head;

        //for [1,2,3,4,5,6]  intialization slow=1,fast=1
        //iteration 1 cond(1 and 2 both valid) slow =2, fast =3
        //iteration 2 cond(3 and 4 both valid) slow =3, fast =5
        //iteration 3 cond(5 and 6 both valid) slow =4, fast =null  (next of 6)
        //iteration 4 cond(null and null both invalid) 
        //so slow = 4

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

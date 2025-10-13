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
    ListNode* sortList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid = middle(head);
        ListNode* head2=mid->next;
        mid->next=nullptr;
        head = sortList(head);
        head2 = sortList(head2);
        return merge(head,head2);
    }

private:

    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* head , ListNode* head2){
        ListNode* dummyNode= new ListNode(-1);
        ListNode* curr = dummyNode;
        ListNode* t1 = head;
        ListNode* t2 = head2;

        while(t1 && t2){
            if(t1->val < t2->val){
                curr->next = t1;
                curr = t1;
                t1=t1->next;
            }
            else{
                curr->next = t2;
                curr = t2;
                t2=t2->next; 
            }
        }
        if(t1)curr->next=t1;
        else curr->next=t2;

        ListNode* newhead = dummyNode->next;
        delete dummyNode;
        return newhead;
    } 
};

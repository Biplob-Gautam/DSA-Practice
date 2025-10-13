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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0,carry=0;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* curr = dummyNode;
        ListNode* t1=l1;
        ListNode* t2=l2;

        while(t1 || t2){
            sum = carry;
            if(t1) sum+=t1->val;
            if(t2) sum+=t2->val;

            carry=sum/10;
            sum=sum%10;

            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = curr->next;

            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        ListNode* head = dummyNode->next;
        delete dummyNode ;
        return head;
    }
};

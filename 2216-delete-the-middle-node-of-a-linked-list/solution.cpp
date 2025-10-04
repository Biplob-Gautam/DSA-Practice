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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)return NULL;
        ListNode* toRemove = middleNode(head);
        ListNode* temp=head;

        while(temp->next != toRemove){
            temp=temp->next;
        }
        temp->next=toRemove->next;
        toRemove->next=nullptr;
        delete toRemove;
        return head;
    }

private:

    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

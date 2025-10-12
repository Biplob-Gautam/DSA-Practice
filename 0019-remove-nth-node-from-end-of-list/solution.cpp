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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return nullptr;
        ListNode* fast=head;
        ListNode* slow=head;
        int count=0;
        while(fast->next){
            if(count>=n)slow=slow->next;
            fast=fast->next;
            count++;
        }
        if (count + 1 == n) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
        return head;
    }
};

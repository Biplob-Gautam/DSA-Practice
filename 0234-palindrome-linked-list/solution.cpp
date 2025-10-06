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
    bool isPalindrome(ListNode* head) {

        if(head==NULL || head->next==NULL)return true;

        //Using a stack TC=O(2n) SC=O(n)

        // stack<int> st;
        // ListNode* temp=head;
        // while(temp){
        //     st.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp){
        //     if(st.top()!=temp->val)return false;
        //     st.pop();
        //     temp=temp->next;
        // }
        // return true;

        //Using 2 pointer TC=O(2n) SC=(1)

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);

        ListNode* first=head;
        ListNode* second=newHead;

        while(second){
            if(first->val != second->val){
                reverse(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newHead);
        return true;
    }

private:

    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)return head;
        
        ListNode* newHead = reverse(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next=NULL;

        return newHead;
    }
};

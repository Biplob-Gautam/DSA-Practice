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
    ListNode* oddEvenList(ListNode* head) {

        //Using a vector TC=O(n/2+n/2)=O(n) SC=O(n)

        if(head==NULL || head->next==NULL)return head;
        vector<int> nums;
        ListNode* temp=head;
        int i=0;
        while(temp && temp->next){  //filling out odd nodes
            nums.push_back(temp->val);
            temp=temp->next->next;
            i++;
        }
        if(temp) nums.push_back(temp->val);
        temp=head->next;
        while(temp && temp->next){  //filling out even ones
            nums.push_back(temp->val);
            temp=temp->next->next;
            i++;
        }
        if(temp) nums.push_back(temp->val);

        i=0;
        temp=head;
        while(temp){      //changing the LL
            temp->val=nums[i];
            temp=temp->next;
            i++;
        }
        return head;

        // Using 2 pointer TC=O(n) SC=O(1)
        // if(head==NULL || head->next==NULL)return head;

        // ListNode* odd=head;
        // ListNode* even=head->next;
        // ListNode* evenHead=head->next;

        // while(even && even->next){
        //     odd->next=odd->next->next;
        //     even->next=even->next->next;

        //     odd=odd->next;
        //     even=even->next;
        // }

        // odd->next=evenHead;
        // return head;
    }
};

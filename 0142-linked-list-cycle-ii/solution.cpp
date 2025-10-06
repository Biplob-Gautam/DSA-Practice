/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head==NULL||head->next==NULL)return NULL;

        //Using a hashmap TC=O(n) SC=O(n)
        // unordered_map<ListNode*,int> hashmap;
        // ListNode* temp=head;
        // while(temp){
        //     if(hashmap.find(temp)!=hashmap.end()){
        //         //cycle detected
        //         return temp;
        //     }
        //     hashmap[temp]++;
        //     temp=temp->next;
        // }
        // return NULL;

        //Using two pointer TC=O(n) SC+O(1)

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                //cycle detected
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow; //or fast
            }
        }
        return NULL;
    }
};

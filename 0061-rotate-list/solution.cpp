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
    ListNode* rotateRight(ListNode* head, int k) {
        // if(head==NULL || head->next==NULL)return head;       //tc=On  sc=On
        // if(k==0)return head;

        // vector<int> nums;
        // nums=convert(head);

        // k=k%nums.size();
        // reverse(nums.begin(), nums.end());     
        // reverse(nums.begin(),nums.begin()+k);
        // reverse(nums.begin() + k,nums.end());

        // ListNode* temp=head;
        // int i=0;
        // while(temp){
        //     temp->val=nums[i];
        //     i++;
        //     temp=temp->next;
        // }

        // return head;

        if(head==NULL || head->next==NULL)return head;
        if(k==0)return head;

        ListNode* tail=head;
        int count=1;

        while(tail->next){
            tail=tail->next;
            count++;
        }

        tail->next=head;
        k=k%count;

        ListNode* temp=head;
        int steps= count-k-1;
        while(steps){
            steps--;
            temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;

        return head;
    }
// private:
//     vector<int> convert(ListNode* head){
//         vector<int> nums;
//         ListNode* temp=head;

//         while(temp){
//             nums.push_back(temp->val);
//             temp=temp->next;
//         }

//         return nums;
//     }
};






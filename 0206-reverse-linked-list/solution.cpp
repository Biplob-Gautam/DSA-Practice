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
    ListNode* reverseList(ListNode* head) {

        //Iterative Solution TC=O(n) SC=O(1) ----BTW you can use stack also TC=O(2N) SC=O(N)

        // ListNode* current = head;
        // ListNode* tempBack= NULL;
        
        // while(current){
        //     ListNode* front = current->next;
        //     current->next=tempBack;
        //     tempBack=current;
        //     current=front;
        // }
        // head = tempBack;
        // return head;

        //Recursive Solution

        if(head==NULL || head->next==NULL)return head;
        
        ListNode* newHead = reverseList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next=NULL;

        return newHead;
    }
};

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
    int LLlenght(ListNode* head){
        ListNode* temp = head;
        int x =0;
        while(temp != NULL){
            x++;
            temp = temp->next;
        }
        return x;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int len = LLlenght(head);
        // int x = len-n;
        
        // if(x==0){
        //     return head->next;
        // }
        // ListNode* temp = head;
        // while(--x){
        //     temp = temp->next;
        // }

        // ListNode* nex = temp->next->next;
        // temp->next->next = NULL;
        // temp->next = nex;

        // return head;


        ListNode* slow = head;
        ListNode* fast = head;

        while(n--){
            fast = fast->next;
        }

        if(fast == NULL){
            return head->next;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }


        ListNode* temp = slow->next->next;
        slow->next->next = NULL;
        slow->next = temp;
        
        return head;
    }
};
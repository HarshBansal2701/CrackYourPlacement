class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Approach -> Fast and Slow pointer
        // if(head == NULL){
        //     return head;
        // }
        // ListNode* curr = head;
        // ListNode* prev = NULL;

        // while(curr != NULL){
        //     ListNode* temp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = temp;
        // }
        // return prev;


        // Approach -> Recursively
        if(head==NULL || head->next == NULL){
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        
        ListNode* fontNode = head->next;
        fontNode->next = head;
        head->next= NULL;
        return newHead;

    }
};
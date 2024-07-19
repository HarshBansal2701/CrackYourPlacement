class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Using fast and slow pointer
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next!= NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};
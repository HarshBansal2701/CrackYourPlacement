class Solution {
    ListNode* rev(ListNode* head){
        if(head == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return  prev;
    }
public:
    int getDecimalValue(ListNode* head) {
        
        ListNode* newHead = rev(head);
        int ans = 0;
        int i = 0;

        while(newHead != NULL){
            if(newHead->val == 1){
                ans += pow(2,i);
            }
            i++;
            newHead = newHead->next;
        }
        return ans;
    }
};
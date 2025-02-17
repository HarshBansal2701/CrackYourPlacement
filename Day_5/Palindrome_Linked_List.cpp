class Solution {
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    bool compare(ListNode* head1 , ListNode* head2){
        while(head1 != NULL && head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middle(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;
        head2 = reverseLL(head2);
        bool ans = compare(head , head2);
        return ans;
    }
};
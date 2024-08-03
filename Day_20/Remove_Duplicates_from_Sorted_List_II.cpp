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
    ListNode* deleteDuplicates(ListNode* head) {
        int arr[302]{0};
        while(head != NULL){
            arr[(head->val)+100]++;
            head = head->next;
        }
        ListNode* ans = NULL;
        ListNode* tail = NULL;

        for(int i = 0 ; i<=300 ; i++){
            if(arr[i]==1){
                ListNode* newNode = new ListNode(i-100);
                if(ans == NULL){
                    ans = newNode;

                    tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }
            }
        }
        return ans;
    }
};
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }

        if(list2 == NULL){
            return list1;
        }

        ListNode* newHead = NULL;
        ListNode* tail = NULL;
        while(list1!= NULL && list2 != NULL){
            if(tail == NULL){
                if(list1->val < list2->val){
                    newHead = list1;
                    tail = list1;
                    list1 = list1->next;
                }
                else{
                    newHead = list2;
                    tail = list2;
                    list2 = list2->next;
                }
            }
            else{
                if(list1->val < list2->val){
                    tail->next = list1;
                    tail = list1;
                    list1 = list1->next;
                }
                else{
                    tail->next = list2;
                    tail = list2;
                    list2 = list2->next;
                }
            }
        }

        if(list1 != NULL){
            tail->next = list1;
        }
        if(list2 != NULL){
            tail->next = list2;
        }


        return newHead;
    }
};
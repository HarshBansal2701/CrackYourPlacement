/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/* Multiply contents of two linked lists */
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long m = 1000000007;
        long x = 0;
        long y = 0;
        
        Node* temp = first;
        while(temp != NULL){
            x = (x*10+temp->data)%m;
            temp = temp->next;
        }
        
        temp = second;
        while(temp != NULL){
            y = (y*10+temp->data)%m;
            temp = temp->next;
        }
        return (x*y)%m;
    }
};
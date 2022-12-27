//Time complexity : O(N)
//Space Complexity : O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL ; 
        }
        Node *curr = head ; 
        //cout << curr -> val ; 

        // step 1 creating copy nodes and original nodes together in a linked list
        while(curr != NULL){
            Node *copy = new Node(curr -> val) ;
            copy -> next = curr -> next ; 
            curr -> next = copy ; 
            curr = copy -> next ; 
        }
        
        // step 2 : linking the random pointers

        curr = head ; 

        while(curr != NULL){
            if(curr -> random != NULL){
                curr -> next -> random  = curr -> random ->next  ;
            }
            curr = curr -> next -> next ; 
        }

        // step 3 : seperating the two linked lists

        curr = head ; 
        Node *copyhead = curr -> next ; 
        Node *copycurr = curr -> next ; 
        while(curr != NULL){
            curr -> next = curr -> next -> next ; 
            if(copycurr -> next != NULL){
                copycurr -> next = copycurr -> next -> next ; 
            }
            curr = curr -> next ; 
            copycurr = copycurr ->next ; 
        }
        return copyhead ; 
    }
};

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
    Node* find(Node* curr1,Node* curr2,Node* x){
        // edge case handling
        if(x==NULL){
            return NULL;
        }
        while(curr1!=x){
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return curr2;
    }

    Node* copyRandomList(Node* head) {
        // method 1 => clone random with with iteration 
        Node* headCopy = new Node(0);
        Node* tailCopy = headCopy,*temp = head;
        // clone the original list with next pointer only
        while(temp){
            tailCopy->next = new Node(temp->val);
            tailCopy = tailCopy->next;
            temp = temp->next;
        }
        // rearrange the pointers
        temp = head;
        tailCopy = headCopy;
        headCopy = headCopy->next;
        delete tailCopy;
        tailCopy = headCopy;
        // now iterate over the original list to find random pointers
        while(temp){
            tailCopy->random = find(head,headCopy,temp->random);
            tailCopy = tailCopy->next;
            temp = temp->next;
        }
        return headCopy;
    }
};
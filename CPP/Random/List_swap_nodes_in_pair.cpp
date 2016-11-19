Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if ( head == nullptr || head->next == nullptr ) return head;
    
        ListNode* prev = head;
        ListNode* curr = head->next;
        prev->next = swapPairs(curr->next);
        curr->next = prev; 
        return curr;
    }
};
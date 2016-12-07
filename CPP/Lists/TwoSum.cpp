Add Two Numbers

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Show Company Tags
Show Tags
Show Similar Problems

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if ( !l1 ) return l2; 
    if ( !l2 ) return l1;
    int sum, carry=0;
    int len1=0, len2=0;
    ListNode* l3;
    ListNode* tmp;
    tmp = l1;
    while (tmp) { tmp=tmp->next; ++len1; }
    tmp = l2;
    while (tmp) { tmp=tmp->next; ++len2; }
    l3 = (len1>len2)?l1:l2;
    ListNode* result = l3;
    
    while ( l1 || l2 ) {
        if ( l1 ) { carry += l1->val; l1=l1->next; }
        if ( l2 ) { carry += l2->val; l2=l2->next; }
        l3->val = carry%10;
        if ( carry>9 ) carry /= 10; 
        else carry = 0;
        if ( l1 || l2 ) l3=l3->next;
    }
    if ( carry ) 
        l3->next = new ListNode(carry);
    
    return result; 
    }
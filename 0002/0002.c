/**
 * raw version:
 * ----Runtime: 8 ms
 * --------beats 97.05 % of c submissions.
 * ----Memory Usage: 8.9 MB
 * --------beats 64.00 % of c submissions.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = l1;
    
    l1->val += l2->val;
    int extra = 0;
    if(l1->val >= 10) {
        extra = 1;
        l1->val -= 10;
    }
    
    while(l1->next && l2->next) {
        l1 = l1->next;
        l2 = l2->next;
        l1->val = l1->val + l2->val + extra;
        if(l1->val >= 10) {
            extra = 1;
            l1->val -= 10;
        } else {
            extra = 0;
        }
    }
    
    if(l2->next) {
        l1->next = l2->next;
        l2->next = NULL;
    }
    
    while(extra && l1->next) {
        l1 = l1->next;
        l1->val += 1;
        if(l1->val >= 10) {
            extra = 1;
            l1->val -= 10;
        } else {
            extra = 0;
        }
    }
    
    if(extra) {
        l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        l1 = l1->next;
        l1->val = 1;
        l1->next = NULL;
    }
    
    return head;
}


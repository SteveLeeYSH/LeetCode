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

typedef struct ListNode LNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    LNode *head = (LNode*)malloc(sizeof(LNode));
    LNode *current = head;
    
    current->val = l1->val + l2->val;
    int extra = current->val / 10;
    current->val %= 10;
    
    while(l1->next != NULL && l2->next != NULL) {
        l1 = l1->next;
        l2 = l2->next;
        current->next = (LNode*)malloc(sizeof(LNode));
        current = current->next;
        current->val = l1->val + l2->val + extra;
        extra = current->val / 10;
        current->val %= 10;
    }
    current->next = NULL;
    
    if(l1->next != NULL) {
        current->next = l1->next;
        l1->next = NULL;
        while(extra && current->next != NULL) {
            current = current->next;
            current->val += 1;
            extra = current->val / 10;
            current->val %= 10;
        }
    }

    if(l2->next != NULL) {
        current->next = l2->next;
        l2->next = NULL;
        while(extra && current->next != NULL) {
            current = current->next;
            current->val += 1;
            extra = current->val / 10;
            current->val %= 10;
        }
    }

    if(extra == 1) {
        current->next = (LNode*)malloc(sizeof(LNode));
        current = current->next;
        current->val = 1;
        current->next = NULL;
    }
    
    return head;
}

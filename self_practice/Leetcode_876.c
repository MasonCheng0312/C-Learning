/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode_old(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    int step_count = 0;
    // the condition is the input linklist at least has 1 element.
    while(fast != NULL){
        step_count++;
        fast = fast->next;
        if((step_count%2)-1)slow = slow->next;
    }
    return slow;
}

struct ListNode* middleNode_new(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast != NULL && fast->next != NULL){
        // fast need to ensure that is this
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
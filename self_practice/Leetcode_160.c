#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* path_A = headA;
    struct ListNode* path_B = headB;

    while(path_A != path_B){
        path_A = (path_A == NULL) ? path_A = headB : path_A -> next;
        path_B = (path_B == NULL) ? path_B = headA : path_B -> next;
    }
    return path_A;
}
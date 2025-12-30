#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev_of_slow = NULL;

    if(head->next == NULL && n == 1)return NULL;
    
    for(int gap = 0; gap < n; gap++){
        fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        prev_of_slow = slow;
        slow = slow->next;
    }

    if (slow == head)return head->next;

    struct ListNode* temp = slow;
    prev_of_slow->next = slow->next;
    free(temp);
    
}
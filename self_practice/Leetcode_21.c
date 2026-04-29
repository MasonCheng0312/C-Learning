struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy; // 在 Stack 上宣告一個臨時工
    struct ListNode* current = &dummy; // current 指向這個臨時工的位址
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) { // 注意是 val，不是 value
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // 技巧：剩下的不用跑迴圈，直接整串接上去
    current->next = (list1 != NULL) ? list1 : list2;

    return dummy.next; // dummy 是實體，用點存取成員
}